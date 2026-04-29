/*
NodeMCU (ESP8266)
Dual YF-S201 Style Flow Meters and DS18B20 OneWire
MQTT Integration with RaspberryPints
Special Thanks to Homebrewtalk.com Members RandR+ and Thorrak who made this sketch possible!
This sketch is brought to you by coders like them!
*/

#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <time.h>

void setup_wifi(); // Add this line at the top
void ICACHE_RAM_ATTR pulseCounter1(); // Add this line at the top
void ICACHE_RAM_ATTR pulseCounter2(); // Add this line at the top
void callback(char* topic, byte* payload, unsigned int length); // Add this line at the top
void reconnect(); // Add this line at the top
void pulseCounter1(); // Add this line at the top
void pulseCounter2(); // Add this line at the top
const char* mqtt_topic = "rpints/pours"; // Add this line at the top
void sendTemp(float temp, const char* probe, const char* unit, const char* timestamp); // Add this line at the top
char* getTimestamp(); // Add this line at the top

// WiFi Settings
const char* ssid = "YourSSID";
const char* password = "YourSSID_PW";

// MQTT Settings
const char* mqtt_server = "raspberrypints.local";  //If your RaspberryPints has a static IP, you can use the IP address.
const int mqtt_port = 1883;
const char* mqtt_user = "YOUR_USER";  //If you change the MQTT user name, make sure you add that name here.
const char* mqtt_pass = "YOUR_PW";

// Flow Sensor 1
const int flowPin1 = D2; // Avoid using D3, D4, and D8
const int tapNumber1 = 4;  // Change for each tap. If running an Arduino through Serial or USB in conjunction with MQTT, Do not make this a pin number already used.
volatile unsigned long pulseCount1 = 0;

// Flow Sensor 2
const int flowPin2 = D5;  // Avoid using D3. D4, and D8
const int tapNumber2 = 6;  // Change for each tap. If running an Arduino through Serial or USB in conjunction with MQTT, Do not make this a pin number already used.
volatile unsigned long pulseCount2 = 0;

// Pour tracking
const unsigned long POUR_TIMEOUT = 2000;   // ms of no flow before pour is considered done
const unsigned long CHECK_INTERVAL = 100;  // how often to check for flow activity
const unsigned long MIN_POUR_PULSES = 5;   // minimum pulses to count as a real pour (noise filter)

bool pouring1 = false;
unsigned long pourPulses1 = 0;
unsigned long lastPulseTime1 = 0;

bool pouring2 = false;
unsigned long pourPulses2 = 0;
unsigned long lastPulseTime2 = 0;

unsigned long lastCheckTime = 0;

// OneWire Settings
#define SENSOR_PIN D7  // The ESP8266 pin connected to DS18B20 sensor's DQ pin
const char* TZstr = "EST+5EDT,M3.2.0/2,M11.1.0/2";  //read putting TZ offset in configTime is problematic

OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);

float temperature_C;  // temperature in Celsius
float temperature_F;  // temperature in Fahrenheit

WiFiClient espClient;
PubSubClient client(espClient);

static unsigned long tempTime = 0;

char probeName[24] = "Garage";

void setup() {
  Serial.begin(115200);
 
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  //OneWire
  DS18B20.begin();  // initialize the DS18B20 sensor
  configTime(TZstr, "pool.ntp.org", "time.nist.gov"); //POSIX Timezone String to accomodate for daylight savings

  pinMode(flowPin1, INPUT_PULLUP);
  pinMode(flowPin2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(flowPin1), pulseCounter1, FALLING);
  attachInterrupt(digitalPinToInterrupt(flowPin2), pulseCounter2, FALLING);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Check flow activity periodically: accumulate pulses during a pour,
  // then publish the total once flow has stopped for POUR_TIMEOUT ms.
  if (millis() - lastCheckTime > CHECK_INTERVAL) {
    unsigned long count1 = pulseCount1;
    pulseCount1 = 0;
    unsigned long count2 = pulseCount2;
    pulseCount2 = 0;

    unsigned long now = millis();

    // Tap 1
    if (count1 > 0) {
      pourPulses1 += count1;
      lastPulseTime1 = now;
      if (!pouring1) {
        pouring1 = true;
        Serial.print("Tap ");
        Serial.print(tapNumber1);
        Serial.println(": pour started");
      }
    } else if (pouring1 && (now - lastPulseTime1 > POUR_TIMEOUT)) {
      if (pourPulses1 >= MIN_POUR_PULSES) {
        char payload[100];
        snprintf(payload, sizeof(payload), "P;%d;%d;%lu", -1, tapNumber1, pourPulses1);
        client.publish("rpints/pours", payload);
        Serial.print("Sent: ");
        Serial.println(payload);
      } else {
        Serial.print("Tap ");
        Serial.print(tapNumber1);
        Serial.print(": discarded noise (");
        Serial.print(pourPulses1);
        Serial.println(" pulses)");
      }
      pouring1 = false;
      pourPulses1 = 0;
    }

    // Tap 2
    if (count2 > 0) {
      pourPulses2 += count2;
      lastPulseTime2 = now;
      if (!pouring2) {
        pouring2 = true;
        Serial.print("Tap ");
        Serial.print(tapNumber2);
        Serial.println(": pour started");
      }
    } else if (pouring2 && (now - lastPulseTime2 > POUR_TIMEOUT)) {
      if (pourPulses2 >= MIN_POUR_PULSES) {
        char payload[100];
        snprintf(payload, sizeof(payload), "P;%d;%d;%lu", -1, tapNumber2, pourPulses2);
        client.publish("rpints/pours", payload);
        Serial.print("Sent: ");
        Serial.println(payload);
      } else {
        Serial.print("Tap ");
        Serial.print(tapNumber2);
        Serial.print(": discarded noise (");
        Serial.print(pourPulses2);
        Serial.println(" pulses)");
      }
      pouring2 = false;
      pourPulses2 = 0;
    }

    lastCheckTime = now;
  }

  //OneWire
    if (millis() - tempTime > 90000) {            // You can change the time in ms to broadcast temp
        DS18B20.requestTemperatures();             // send the command to get temperatures
      
    temperature_C = DS18B20.getTempCByIndex(0);  // read temperature in °C
    temperature_F = temperature_C * 9 / 5 + 32;  // convert °C to °F

    sendTemp(temperature_F, probeName, "F", getTimestamp()); 

    Serial.print("Temperature: ");
    //Serial.print(temperature_C);  // print the temperature in °C
    //Serial.print("°C ");
    //Serial.print("  ~  ");        // separator between °C and °F
    Serial.print(temperature_F);  // print the temperature in °F
    Serial.println("°F");

    tempTime = millis();
  }
}

void setup_wifi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void ICACHE_RAM_ATTR pulseCounter1() {
  pulseCount1++;
}

void ICACHE_RAM_ATTR pulseCounter2() {
  pulseCount2++;
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    String clientId1 = "ESP8266-tap" + String(tapNumber1);
    if (client.connect(clientId1.c_str(), mqtt_user, mqtt_pass)) {
      Serial.println("Connected!");
      // Subscribe to commands from RPints
      client.subscribe("rpints");
      Serial.println("Subscribed to rpints topic");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
    Serial.print("Connecting to MQTT...");
    String clientId2 = "ESP8266-tap" + String(tapNumber2);
    if (client.connect(clientId2.c_str(), mqtt_user, mqtt_pass)) {
      Serial.println("Connected!");
      // Subscribe to commands from RPints
      client.subscribe("rpints");
      Serial.println("Subscribed to rpints topic");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle commands from RaspberryPints
  Serial.print("Message received on ");
  Serial.print(topic);
  Serial.print(": ");

  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println(message);

  // Parse and handle commands here
  // Example: valve control, configuration updates, etc.
}

char* getTimestamp(){
    static char buffer[80];
    time_t timer;
    struct tm* timeinfo;

    time(&timer);
    timeinfo = localtime(&timer);

    strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S", timeinfo);
    return(buffer);
}

void sendTemp(float temp, const char* probe, const char* unit, const char* timestamp)
{
   char payload[100];
   snprintf(payload, sizeof(payload),
            "T;%s;%.2f;%s;%s",
            probe,
            temp,
            unit,
            timestamp);
   Serial.print("Sending temperature: ");
   Serial.println(payload);

   client.publish(mqtt_topic, payload);
}
