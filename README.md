RaspberryPints (RPints) is a digital upgrade to the conventional chalkboard taplist, created just for the home brewer. Display your current beers on tap with a sleek, digital presentation. Manage your beers, recipes, kegs, and taps with our built-in tracking system.


__Licensing:__

	GNU GENERAL PUBLIC LICENSE
	Version 3, 29 June 2007
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

Full license text available in 'LICENSE.md'.


Questions? Comments? Want to Contribute?
https://homebrewtalk.com/threads/version-2-release-raspberrypints-digital-taplist-solution.487694

Inspired by Kegerface:
http://github.com/kegerface/kegerface

# RaspberryPints Installation and User Guide

## Overview

**RaspberryPints** is a digital tap list solution designed for Raspberry Pi that displays real-time information about what's on tap. It's perfect for home brewers, bars, and anyone who wants to showcase their beverage selection professionally.

### Key Features

- **Real-time Tap Display**: Show what's currently on tap with beautiful visual presentation
- **Pour Tracking**: Monitor consumption using flow meters (optional)
- **Keg Management**: Track keg levels, line cleaning, and tap assignments
- **Brewery & Beer Database**: Maintain detailed information about breweries, beers, and styles
- **Statistics & Analytics**: View consumption statistics by beer, tap, and user
- **RFID Support**: Track individual drinker pours with RFID cards
- **Temperature Monitoring**: Monitor keg/fermenter temperatures with DS18B20 probes
- **Untappd Integration**: Import beer data from Untappd
- **Multiple Display Options**: Support for various screen sizes and orientations

---

## Installation

### Prerequisites

- **Raspberry Pi** (any model with network connectivity)
- **Raspbian OS** (Jessie, Stretch, Buster, Bullseye, or Bookworm)
- **Internet connection** for downloading packages
- **Monitor/Display** (optional, for kiosk mode)

### Installation Methods

#### Method 1: Quick Install (Recommended)

Run the following command on your Raspberry Pi:

```bash
curl -L install.rpints.com | sudo bash
```

Or from the project directory:

```bash
sudo ./util/installRaspberryPints
```

#### Method 2: Update Existing Installation

```bash
sudo ./util/installRaspberryPints --update
```

#### Method 3: Custom Install Path

```bash
sudo ./util/installRaspberryPints --install /custom/path
```

### Installation Walkthrough

The installer will guide you through several configuration steps:

#### 1. **Initial Setup**
   - The script will check for root privileges and set up logging
   - Default password check for the 'pi' user (you'll be prompted to change it if needed)
   - Timezone configuration
   - Hostname change (recommended to change from default "raspberrypi")

#### 2. **Choose RaspberryPints Version**
   
   You'll be presented with three options:
   - **RandR+** (Recommended): Most actively maintained version
   - **Tobor**: Alternative version with specific features
   - **Original**: Legacy version (may not work on newer Raspbian)

#### 3. **Web Server Selection**
   
   Choose your web server:
   - **Apache** (Default): Recommended for standalone RPints installations
   - **Nginx**: Choose this if you're running Fermentrack or prefer Nginx

#### 4. **Installation Path**
   
   - Default: `/var/www/html`
   - You can specify a custom path if needed
   - For Fermentrack integration, you can nest RPints under it

#### 5. **Database Configuration**
   
   Configure MySQL/MariaDB settings:
   - **Database Host**: Usually `localhost`
   - **Database Name**: Default is `raspberrypints`
   - **Database User**: Default is `RaspberryPints`
   - **Database Password**: Default is `RaspberryPints` (change recommended)
   - **Admin Account**: Create your admin username and password
   - **Time Format**: Choose your preferred date/time display format

#### 6. **Test Data**
   
   Choose whether to load sample data (recommended for first-time setup to look at without creating your own beer yet)

#### 7. **Hardware Configuration**

   The installer will ask about optional hardware:

   **Flow Meters** (Arduino-based pour tracking)
   - Requires Arduino or Alamode board
   - Connection type: Serial, USB, Bluetooth, or MQTT
   - Automatically configures I2C and SPI interfaces
   
   **RFID Readers**
   - Track individual users' pours
   - Configure GPIO pin for RFID module
   
   **Motion Sensors**
   - Wake display when someone approaches
   - Auto-dim when no motion detected
   
   **Temperature Probes**
   - Monitor keg/fermenter temperatures
   - Uses DS18B20 digital temperature sensors
   
   **MQTT Support**
   - For ESP32/Photon-based flow meters
   - Configure broker settings

   > **Note:** You can add hardware features later! If you skip any hardware during initial installation, you can rerun the installer and select **"Reconfigure Pi/Enable Features"** to add flow meters, RFID, motion sensors, temperature probes, or other hardware without reinstalling RaspberryPints.

#### 8. **Display Configuration**
   
   If using a monitor:
   - **Resolution**: Choose from common resolutions (1080p, 720p, etc.)
   - **Rotation**: 0°, 90°, 180°, 270°
   - **Screen Blanking**: Option to disable the screen going black
   - **Kiosk Mode**: Auto-launch Chromium in fullscreen

#### 9. **Completion**
   
   - Reboot when prompted
   - Access RPints at `http://[your-pi-ip]` or `http://[hostname].local`

---

## Admin Interface Guide

Access the admin interface at: `http://[your-pi-ip]/admin/`
Use the admin username and password from setup

### Main Admin Sections

#### 🍺 **Beer Management**

**Beer List**
- View all beers in your database
- Quick search and filter options
- Add new beers or edit existing ones
- Import from Untappd or XML (see XML Import Guide below)

**Beer Form**
- Add/edit beer details:
  - Name, brewery, style
  - ABV, IBU, SRM (color)
  - Description and tasting notes
  - Untappd ratings
  - Custom images

**Beer Batch**
- Track homebrew batches (Each time you brew a beer you can create a specific batch to track it's data)
- Link batches to kegs
- Record brew dates and notes

**Beer Styles**
- Manage beer style categories
- BJCP style guidelines integration
- Import styles from XML (see XML Import Guide below)

#### 🏭 **Brewery Management**

**Brewery List**
- View and manage breweries
- Link to brewery websites
- Add brewery logos
- Track location information

**Brewery Form**
- Add/edit brewery details
- Upload brewery logos
- Add contact information

#### 🛢️ **Keg & Batch Management**

**Keg List**
- Track all kegs in inventory
- Edit/View keg levels (manually or with flow meters)

**Keg Form**
- Add new kegs
- Assign to taps
- Set keg size and capacity

#### 🚰 **Tap Management**

**Tap List**
- Configure tap positions
- Assign kegs to taps
- Set Keg/Beer associated with the tap

**Tap List - Settings**
- Click on the Settings Button to show advanced settings for the taps
    - **Feature Enable/Disable Checkboxes:**
        - **Use Flow Meters**: Enable/disable flow meter tracking
        - **Use Tap Valves**: Enable automated valve control
        - **Use 3-Wire Valves**: Enable 3-wire valve configuration
        - **Use Fan Control**: Enable temperature management fan
        - **Use Keg Weight Calculator**: Calculate keg levels by weight
        - **Use Plaato**: Enable Plaato digital scale integration
        - **Allow Manual Pours**: Enable manual pour entry without flow meters
    - Click **Show Pin Settings** checkbox to show/hide GPIO pin configuration columns in the tap list table
- **Weight Calculator Settings** (when Keg Weight Calculator is enabled):
    - **Brewery Altitude**: Altitude above sea level for CO2 volume calculations
    - **Use Default Weight Settings**: Apply same weight settings to all taps (otherwise configure per-tap)
    - **Default Fermentation Pressure**: PSI during fermentation (0 if not fermenting under pressure)
    - **Default Kegging Temperature**: Temperature of beer when transferred to keg (for CO2 calculation)
- **Alamode/Flow Meter Setup** (when Flow Meters enabled):
    - **Pour Message Delay**: Milliseconds to wait after pulses stop before recording the pour
    - **Pour Trigger Count**: Minimum flow meter pulse count to start recording a pour
    - **Kick Trigger Count**: Pulse count within one millisecond that indicates a kicked/empty keg
    - **Update Trigger Count**: Pulse count threshold for internal status updates
- **Fan Setup** (when Fan Control is enabled):
    - **Fan Pin (GPIO)**: Raspberry Pi GPIO pin that powers the fan
    - **Fan Interval (mins)**: How often fan triggers (≤0 means always on)
    - **Fan Duration (mins)**: How long fan runs after being triggered (≤0 means never runs)
    - **Restart On Pour**: Checkbox to restart fan cycle when a pour is detected
- **Tap Valves Setup** (when Tap Valves enabled):
    - **Pour Shutoff Count**: Flow meter pulse count limit before valve auto-closes tap (0 to disable)
    - **Valve Power Pin**: GPIO pin that powers three-way valves (only shown if using 3-wire valves)
    - **Valve On Time**: Duration (in milliseconds) valves remain powered
- **General Tap Setup**:
    - **Number of Taps**: Total number of taps in your system
- **Per-Tap Configuration** (in main tap table):
    - **Tap Description**: Tap number/name with optional custom image upload
    - **Keg Assignment**: Select which keg is on this tap (dropdown shows keg ID, label, and current tap) - Currently Required
    - **Beer Selection**: Choose beer/batch to display (linked to keg selection)
    - **Start Amount**: Initial keg capacity in gallons/liters
    - **Current Amount**: Remaining beer in keg (auto-updates with pours if using flow meters)
    - **Current Weight**: Keg weight (if using weight calculator, can calculate volume from weight)
    - **Fermentation PSI**: Pressure during fermentation for this specific keg (if not using defaults)
    - **Kegging Temperature**: Temperature when kegged for this specific beer (if not using defaults)
    - **Flow Pin**: GPIO pin number for this tap's flow meter (shown when "Show Pin Settings" is checked)
    - **Count Per Gallon/Liter**: Calibration value - pulses per volume unit (shown when "Show Pin Settings" is checked)
    - **Calibrate Button**: Launch flow meter calibration wizard for this tap
    - **Manual Pour**: Enter a pour manually by volume (when Allow Manual Pours is enabled)
    - **Valve Pin**: GPIO pin for this tap's valve (shown when "Show Pin Settings" is checked)
    - **Valve PI Pin Checkbox**: Indicates if valve pin is on Raspberry Pi (checked) vs Arduino (unchecked)
    - **Valve Control Button**: Manually open ("Let it flow") or close ("Stop flow") this tap's valve
    - **Plaato Auth Token**: Authentication token for Plaato scale integration (when enabled)

#### 📦 **Extra Setup Management**

**Fermenter List**
- Track Fermenters and their beer/batches
- Monitor temperature

**Fermenter Form**
- Add/edit fermenters
- Set temperature profiles
- Add fermentation notes

**Bottle List**
- Track bottled beers
- Monitor bottle inventory
- Link to batches

**Gas Tank List**
- Track CO2/nitrogen tanks
- Monitor tank levels (with sensors)

**Customize Tap Display**
- Choose display layout - Taps Up to Down or Left to Right
- Select which information to show/hide in the layout of the main display
- Customize colors and themes
- Configure display orientation

#### 📊 **Statistics & Reports**

**Pour List**
- View all recorded pours
- Filter by date, tap, user
- Export data

**Statistics - Beer**
- Most popular beers
- Consumption by beer
- Beer ratings and favorites

**Statistics - Tap**
- Pour volume by tap
- Busiest taps
- Tap history

**Statistics - Tap History**
- Historical view of tap assignments
- When each beer was on tap
- Duration on tap

**Statistics - Drinker**
- Top consumers (requires RFID)
- Favorite beers by user
- User pour history

#### 👥 **User Management**

**User List**
- Manage admin users
- View drinker accounts
- Set permissions
- Activate/deactivate users

**User Form**
- Add/edit users
- Set admin privileges
- Link Untappd accounts
- Assign email addresses

**User RFID**
- Assign RFID tags to users
- Test RFID reader functionality
- Manage card IDs
- Displays unassigned Tags that were scanned but not associated with a user

#### ⚙️ **Hardware Configuration**

**RFID Readers**
- Add/configure RFID readers
- Set GPIO pins for the Trigger to get data from RDID reader
- Test reader functionality

**Temperature Probes**
- Auto-discovers DS18B20 1-wire temperature probes connected to the Pi
- When use temperature probes is checked: Probes automatically populate when connected correctly (see [Adafruit DS18B20 Guide](https://cdn-learn.adafruit.com/downloads/pdf/adafruits-raspberry-pi-lesson-11-ds18b20-temperature-sensing.pdf) for wiring)
- Click **Settings** button to configure temperature probe system:
    - **Use Temperature Probes**: Enable/disable temperature probe monitoring
    - **Show Temperature on Main Page**: Display average temperature on the main tap display (when temp probes enabled)
    - **Check Delay**: Seconds between temperature readings (default: 60)
    - **Lowest Temperature**: Minimum valid temperature in Celsius (readings below this are ignored as errors)
    - **Highest Temperature**: Maximum valid temperature in Celsius (readings above this are ignored as errors)
- **Per-Probe Configuration**:
    - **Name**: Descriptive name/notes for the probe (e.g., "Keezer", "Fermenter 1", "Ambient")
    - **State Pin**: Optional GPIO pin to check state when temperature is recorded (blank or 0 to disable)
        - Useful for tracking compressor on/off state or other conditions
    - **Adjustment**: Manual temperature adjustment/calibration offset (in degrees)
        - Use this to calibrate individual probes if they read slightly high or low
        - Example: Enter `-0.5` if probe reads 0.5° too high
- Assign probes to kegs, fermenters, or gas tanks in their respective management pages
- View historical temperature data in **Temperature Log**

**Load Cells**
- Configure HX711 or compatible load cells for weight-based tracking
- Supports load cells for both taps (kegs) and gas tanks
- Two separate tables for configuration:
    
    **Tap Load Cells** (for keg weight monitoring):
    - **Tap**: Shows tap number from tap configuration
    - **Command Pin**: GPIO pin number for load cell data/clock (DT pin on HX711)
    - **Response Pin**: GPIO pin number for load cell serial clock (SCK pin on HX711)
    - **Scale Ratio**: Calibration multiplier to convert raw readings to weight units
        - Obtain by weighing a known weight and calculating: (reading with weight - reading without weight) / known weight
    - **Offset**: Tare offset value (automatically set when using Tare button)
    - **Update Variance**: Minimum weight change (in selected unit) to trigger database update
        - Prevents excessive updates from small fluctuations
        - Example: Set to 0.1 to only update when weight changes by 0.1 lbs/kg
    - **Unit**: Weight unit for this load cell (lbs, kg, g, oz)
    - **Tare Date**: Timestamp of last tare operation
    - **Current Weight (Raw)**: Real-time weight reading from keg on this tap
    - **Tare Button**: Zero out the load cell (removes keg weight to measure only beer weight)
        - Place empty keg on load cell, then click Tare
        - Refresh page to see updated Offset value
    
    **Gas Tank Load Cells** (for CO2/nitrogen tank monitoring):
    - **Gas Tank**: Dropdown to select which gas tank this load cell monitors
    - All other columns same as Tap Load Cells (Command Pin, Response Pin, Scale Ratio, Offset, Update Variance, Unit, Tare Date, Current Weight, Tare Button)
    
- **Calibration Process**:
    1. Connect HX711 load cell amplifier to Raspberry Pi GPIO pins
    2. Enter Command Pin (DT) and Response Pin (SCK) numbers
    3. Place a known weight on the load cell (e.g., 5 lbs)
    4. Calculate Scale Ratio: (reading with weight - reading without weight) / known weight
    5. Enter Scale Ratio value
    6. Set Update Variance to prevent noise (typically 0.05 - 0.1)
    7. Place empty keg on load cell and click **Tare** button
    8. System now tracks beer weight by subtracting empty keg weight from total
    
- Load cell weights integrate with keg weight calculator (if enabled in Tap List settings)
- Current weight displayed on Tap List page when keg is assigned
- Weight changes automatically update keg remaining amounts

**Motion Detectors**
- Configure PIR (Passive Infrared) motion sensors for automatic display control
- Supports multiple motion detectors with priority system
- Click **Add Motion Detector** button to add new sensors
- **Configuration Columns**:
    - **Name**: Descriptive name for the motion detector (e.g., "Front Keezer", "Bar Area")
    - **Pi Pin**: GPIO pin number where motion detector output is connected
        - Connect PIR sensor OUT pin to this GPIO pin
        - PIR VCC goes to 5V (Pin 2 or 4), GND to ground (Pin 6, 9, 14, 20, or 25)
    - **Priority**: Determines which detector takes precedence (lower number = higher priority)
        - Useful when multiple detectors control the same display
        - Priority 0 = highest, will override others
    - **LED Pin**: Optional GPIO pin to control an LED indicator
        - LED lights up when motion is detected
        - Leave blank if not using LED indicator
    - **Sound File**: Path to audio file to play when motion detected
        - Example: `/home/pi/sounds/welcome.wav`
        - Leave blank for no sound
        - Requires audio output configured on Pi
    
    **MQTT Integration** (optional, for remote motion detection):
    - **MQTT Command**: MQTT topic to publish commands to
        - Example: `rpints/motion/command`
    - **MQTT Event**: MQTT topic to subscribe for motion events
        - Example: `rpints/motion/detected`
        - Allows remote motion sensors to trigger display wake
    - **MQTT User**: Username for MQTT broker authentication
    - **MQTT Password**: Password for MQTT broker authentication
    - **MQTT Host**: MQTT broker address (e.g., `localhost` or `192.168.1.100`)
    - **MQTT Port**: MQTT broker port (default: 1883)
    - **MQTT Interval**: Seconds between MQTT status updates
    
- **Display Control Integration**:
    - Works with xscreensaver to wake/sleep display
    - Configure screen blanking settings in Display Configuration during installation
    - Motion detector wakes display when motion detected
    - Display sleeps after configured idle time (see xscreensaver settings)
    
- **Typical PIR Sensor Setup**:
    - HC-SR501 or similar PIR motion sensor
    - Adjust sensitivity dial on sensor (typically 3-7 meters range)
    - Set time delay dial to minimum (motion detection handled by RPints)
    - Ensure jumper is set for retriggering mode (H position)
    - Connect: VCC → 5V, GND → Ground, OUT → GPIO pin configured above

**iSpindel Conecters**
- Connect iSpindel digital hydrometers
- Need to define at least one connector 
      - **IP Address**: An IP address on the PI. Can be left blank and all IPs on the Pi will work (put actual Pi IP y into the iSpindel to talk to)
      - **Port**: The port that RPints uses for this iSpindel. Must be a port not in use on the Pi. Example 258. (Put this into the iSpindel as well)
      - **Allowed Connects**: Kinda a safety thing to not allow everything in the work to connect to this Pi at once. Enter the number of iSpindels you (maybe +1 if you think about getting more)

**iSpindel Devices**
- Displays iSpindels that have connected to the Pi and their last reported values
- Set Name for iSpindel (automatically assigned on first connection)
- Associate a Beer or Beer Batch with it to track its fermentation
- Quick access to Graphs per iSpindel or by Beer
- Click **Edit** button on a device to configure advanced settings:
    - **Beer Assignment**: Link device to a specific beer or beer batch for tracking
    - **Gravity Unit**: Select Plato, Specific Gravity (SG), or Brix
    - **Update Interval**: How often (in seconds) the iSpindel reports data
    - **iSpindel Token**: Unique identifier for this device (read-only, generated automatically)
    - **Remote Interval Config Enabled**: Allow RPints to remotely change the update interval on the iSpindel
    - **SQL Logging Enabled**: Store gravity readings in RPints database
    - **CSV Logging Enabled**: Save readings to CSV file
        - CSV Outpath: File path for CSV output
        - CSV Delimiter: Character to separate values (usually comma or semicolon)
        - CSV NewLine Type: Windows or Linux line endings
        - CSV Include DateTime: Add timestamp to each row
    - **Ubidots Logging Enabled**: Forward data to Ubidots IoT platform
        - Use iSpindel Token: Use device token for authentication
        - Ubidots Token: Custom token if not using iSpindel token
    - **Forward Logging Enabled**: Forward raw data to another server
        - Forward Address: IP or hostname to forward to
        - Forward Port: Port number for forwarding
    - **Fermentrack Logging Enabled**: Send data to Fermentrack brewing software
        - Fermentrack Address: IP or hostname of Fermentrack instance
        - Fermentrack Port: Port number for Fermentrack
        - Use iSpindel Token: Use device token or custom token
        - Fermentrack Token: Custom token if not using iSpindel token
    - **BrewPiLess Logging Enabled**: Integrate with BrewPiLess temperature controller
        - BrewPiLess Address: IP or hostname
    - **CraftBeerPi Logging Enabled**: Send data to CraftBeerPi brewing automation
        - CraftBeerPi Address: IP or hostname
        - Send Raw Angle: Include tilt angle in data
    - **BrewSpy Logging Enabled**: Forward to BrewSpy monitoring platform
        - BrewSpy Address: IP or hostname
        - BrewSpy Port: Port number
        - Use iSpindel Token or custom token
    - **BrewFather Logging Enabled**: Integrate with BrewFather brewing app
        - BrewFather Address: API endpoint
        - BrewFather Port: Port number
        - Use iSpindel Token or custom token
        - BrewFather Suffix: Optional suffix for device identification

**IO Pins**
- View pin usage map for the Pi and Arudino
- Cannot Change but is a quick way to see what you have configured on each pin


#### 🎨 **Customization**

**Personalize Configuration**

Comprehensive customization and configuration page with multiple sections:

**1. Display Preferences** (Toggle On/Off)
- Controls what information appears on the main tap list display
- Common options include:
    - **Show Hide Data on Main Display**: Easier to use the Customize Tap Display then individual settings
    - **Auto Refresh Local**: Automatically refresh display
    - **Use High Resolution**: Enable HD graphics mode
    - **Display Rows Same Height**: Normalize row heights in layout

**2. Pour Display Settings**
- **Number of Pours to Show on Home Page**: How many recent pours to display (numeric value)
- **Maximum Pour Amount**: Maximum value (in volume units) before a pour is flagged/ignored
    - Prevents erroneous readings from flow meter issues
    - Example: Set to 128 oz to ignore impossible "pours"

**3. Remaining Amount Display**
- **Amount Per Pint**: Volume in your display units (oz, mL, etc.) that equals one "pint"
    - If greater than 0, remaining kegs displayed in pints instead of volume
    - Example: Set to 16 for US pints, 20 for UK pints
    - Set to 0 to display in volume units instead

**4. Sample Pour Size**
- **Amount Per Sample Pour**: Volume for "sample" button pours
    - If greater than 0, enables sample pour feature
    - Typical: 4-6 oz for tasting samples
    - Useful for RFID users to pour small tastes without full pour

**5. Taplist Header**
- **Text to Display**: Custom header text shown on tap list
    - Your brewery/bar name, event name, welcome message
    - Example: "Welcome to Bob's Brewery" or "Today's Selections"
- **Truncate To**: Maximum characters to display (prevents overflow)
- **Show Untappd Brewery Feed**: Display your Untappd brewery feed (requires Brewery ID)

**6. Number of Accolades Display**
- Controls how many award badges/medals display per row or column
- Depends on vertical vs. horizontal layout
- Prevents overcrowding of accolade displays

**7. Untappd Integration Settings**
- Connect to Untappd API
- Import beer data
- Sync ratings
- **Untappd Client ID**: API client identifier from Untappd developer portal
- **Untappd Client Secret**: API secret key from Untappd
- **Untappd Brewery ID**: Your brewery's Untappd ID number
    - Find in URL of your brewery page: `untappd.com/brewery/XXXXX`
- **Untappd Redirect URI**: OAuth callback URL
    - Typically: `http://your-pi-ip/admin/untappd_oauth.php`
- These enable:
    - Beer searches from Untappd database
    - Automatic beer info population
    - User check-ins integration
    - Brewery feed display

**8. Taplist Logo**
- Upload logo displayed on public-facing tap list
- Current image preview shown
- Accepts: GIF, JPG, PNG formats
- Appears in header or corner of tap list (theme-dependent)

**9. Admin Logo**
- Upload logo displayed in admin panel header
- Separate from taplist logo (can be same or different)
- Accepts: GIF, JPG, PNG formats

**10. Background Image**
- Upload custom background for tap list display
- Current image preview shown (thumbnail)
- Accepts: GIF, JPG, PNG formats
- **Restore Default Background** button returns to original
- Tip: Use high-resolution images matching your display size

**11. Weight Calculation Configuration**
- Used by keg weight calculator to determine CO2 volumes and beer weight
- **Altitude Above Sea Level**: Your brewery/bar altitude
    - Affects CO2 calculation accuracy
    - Enter in your preferred distance unit (ft, m)
- **Default Fermentation Pressure**: Pressure during fermentation
    - 0 if not fermenting under pressure
    - Used to calculate dissolved CO2
    - Enter in your preferred pressure unit (PSI, kPa, bar)
- **Default Beer Temperature During Kegging**: Temperature when keg filled
    - Affects CO2 volume calculations
    - Enter in your preferred temperature unit (°F, °C)
- These defaults apply when adding new kegs (can override per-keg) 

**Themes**
- Choose between green/red themes
- Customize UI colors

**SRM Colors**
- Customize beer color display


**Units of Measure**
- Choose metric or imperial
- Configure display units

**Install Management**
- Update database schema
- Run maintenance scripts
- Backup/restore RPints database to/from a file in <WWWROOT>/sql/backups
  - copy file to different Pi with RPints install to keep data
  - must manually copy images from <WWWROOT>/img dirtory

#### 📝 **Logs & Monitoring**

**RPints Log**
- RPints Python and Arduino Logs
- Debug information for troubleshooting hardware and communication issues

**Enabling Debug Logging**

To troubleshoot issues with flow meters, load cells, iSpindel, or other hardware, you can enable detailed debug logging:

1. **Edit the Config File**:
   ```bash
   sudo nano /var/www/html/python/Config.py
   ```
   *(Adjust path if you installed RPints to a different directory)*

2. **Available Debug Options**:
   - **`config['flowmon.debug']`**: Flow meter monitoring and Arduino/Alamode communication
     - Set to `True` to log all flow meter events, pulses, and communication
     - Useful for diagnosing flow meter counting issues or communication problems
   
   - **`config['dispatch.debug']`**: PintDispatch event processing
     - Set to `True` to log all pour events, RFID reads, and database operations
     - Useful for diagnosing pour recording or RFID issues
   
   - **`config['loadcell.debug']`**: Load cell (HX711) communications
     - Set to `True` to log all load cell readings and weight calculations
     - Useful for diagnosing keg weight tracking issues
   
   - **`config['iSpindel.debug']`**: iSpindel device communications
     - Set to `True` to log all iSpindel data received and processed
     - Useful for diagnosing fermentation tracking issues
   
   - **`config['websocket.debug']`**: WebSocket communications
     - Set to `True` to log WebSocket connections and messages
     - Useful for diagnosing real-time display update issues
   
   - **`config['dispatch.debugMonitoring']`**: Fake pour simulation
     - Set to `True` to generate simulated pour events (for testing without hardware)
     - Useful for testing the system without physical flow meters

3. **Example Configuration**:
   ```python
   # Enable flow meter debugging
   config['flowmon.debug'] = True
   
   # Enable load cell debugging
   config['loadcell.debug'] = True
   
   # Keep others disabled
   config['dispatch.debug'] = False
   config['iSpindel.debug'] = False
   config['websocket.debug'] = False
   ```

4. **Restart RPints Service**:
   After saving changes, restart the flowmon service for changes to take effect:
   ```bash
   sudo /etc/init.d/flowmon restart
   ```

5. **View Debug Logs**:
   - Logs appear in the **RPints Log** page in the admin panel
   - Or view directly: `sudo tail -f /var/log/flowmon.log`
   - Look for detailed debug messages showing exactly what's happening

**⚠️ Important Notes**:
- Debug logging is verbose and can fill logs quickly
- Only enable debugging for components you're troubleshooting
- Remember to disable debug logging after resolving issues
- Debug messages include timestamps, component names, and detailed event data

**Temperature Log**
- Historical temperature data
- Graph temperature trends
- Export data

---

## XML Import Guide

RaspberryPints supports importing beer styles and beers using XML files. This is especially useful for importing BJCP style guidelines or BeerXML recipe files.

### Beer Style XML Format

To import beer styles (such as BJCP guidelines), create an XML file with the following structure:

```xml
<?xml version="1.0" encoding="utf-8"?>
<BEERSTYLES>
  <BEERSTYLE>
    <NAME>American IPA</NAME>
    <CATEGORY>21</CATEGORY>
    <LETTER>A</LETTER>
    <STYLE_GUIDE>BJCP 2015</STYLE_GUIDE>
    <ABV_MIN>5.5</ABV_MIN>
    <ABV_MAX>7.5</ABV_MAX>
    <OG_MIN>1.056</OG_MIN>
    <OG_MAX>1.070</OG_MAX>
    <FG_MIN>1.008</FG_MIN>
    <FG_MAX>1.014</FG_MAX>
    <COLOR_MIN>6</COLOR_MIN>
    <COLOR_MAX>14</COLOR_MAX>
    <IBU_MIN>40</IBU_MIN>
    <IBU_MAX>70</IBU_MAX>
  </BEERSTYLE>
  <BEERSTYLE>
    <!-- Add more styles here -->
  </BEERSTYLE>
</BEERSTYLES>
```

#### Beer Style XML Fields

| Field | Required | Description |
|-------|----------|-------------|
| `NAME` | Yes | Style name (e.g., "American IPA") |
| `CATEGORY` | Yes | Style category number (e.g., "21") |
| `LETTER` | No | Sub-category letter (e.g., "A") |
| `STYLE_GUIDE` | No | Style guide name (e.g., "BJCP 2015") |
| `ABV_MIN` | No | Minimum ABV percentage |
| `ABV_MAX` | No | Maximum ABV percentage |
| `OG_MIN` | No | Minimum original gravity (SG format) |
| `OG_MAX` | No | Maximum original gravity (SG format) |
| `FG_MIN` | No | Minimum final gravity (SG format) |
| `FG_MAX` | No | Maximum final gravity (SG format) |
| `COLOR_MIN` | No | Minimum color in SRM |
| `COLOR_MAX` | No | Maximum color in SRM |
| `IBU_MIN` | No | Minimum IBU (bitterness) |
| `IBU_MAX` | No | Maximum IBU (bitterness) |

**To Import:** Go to **Beer Styles** → **Import from XML** → Upload your XML file

### Beer XML Format (BeerXML)

To import beers with full recipe information, use the BeerXML format:

```xml
<?xml version="1.0" encoding="utf-8"?>
<BEERLISTS>
  <RECIPE>
    <STYLE>
      <CATEGORY>21</CATEGORY>
      <LETTER>A</LETTER>
      <NAME>American IPA</NAME>
    </STYLE>
    <BREWERY>Homebrew Brewing Co.</BREWERY>
    <NAME>Cascade Hop Bomb</NAME>
    <ABV>6.5</ABV>
    <OG>1.065</OG>
    <FG>1.012</FG>
    <SRM>8</SRM>
    <IBU>65</IBU>
    <UNTAPPEDID></UNTAPPEDID>
    <RATING>4.2</RATING>
    <FERMENTABLES>
      <FERMENTABLE>
        <NAME>2-Row Pale Malt</NAME>
        <AMOUNT>12</AMOUNT>
      </FERMENTABLE>
      <FERMENTABLE>
        <NAME>Crystal 20L</NAME>
        <AMOUNT>1</AMOUNT>
      </FERMENTABLE>
    </FERMENTABLES>
    <HOPS>
      <HOP>
        <NAME>Cascade</NAME>
      </HOP>
      <HOP>
        <NAME>Centennial</NAME>
      </HOP>
    </HOPS>
    <YEASTS>
      <YEAST>
        <NAME>US-05 American Ale</NAME>
      </YEAST>
    </YEASTS>
  </RECIPE>
</BEERLISTS>
```

#### Beer XML Fields

| Field | Required | Description |
|-------|----------|-------------|
| `NAME` | Yes | Beer name |
| `BREWERY` | Yes | Brewery name (will be created if it doesn't exist) |
| `STYLE/NAME` | Yes | Style name |
| `STYLE/CATEGORY` | No | Style category number |
| `STYLE/LETTER` | No | Style sub-category letter |
| `ABV` | No | Alcohol by volume percentage |
| `OG` | No | Original gravity (SG format) |
| `FG` | No | Final gravity (SG format) |
| `SRM` | No | Color in SRM (Standard Reference Method) |
| `IBU` | No | International Bitterness Units |
| `UNTAPPEDID` | No | Untappd beer ID for linking |
| `RATING` | No | Beer rating (0-5) |
| `FERMENTABLES` | No | List of fermentable ingredients |
| `HOPS` | No | List of hop varieties used |
| `YEASTS` | No | List of yeast strains used |

**To Import:** Go to **Beer List** → **Import from XML** → Upload your XML file

### Tips for XML Imports

1. **Validate Your XML**: Ensure your XML file is properly formatted before uploading. Use an XML validator or text editor with XML syntax highlighting.

2. **Character Encoding**: Use UTF-8 encoding for proper display of special characters in beer names.

3. **Multiple Entries**: You can include multiple `<BEERSTYLE>` or `<RECIPE>` entries in a single XML file for batch imports.

4. **BeerXML Compatibility**: RaspberryPints accepts standard BeerXML format from brewing software like BeerSmith, BrewFather, and similar applications.

5. **Style Matching**: When importing beers, if the style doesn't exist, make sure to import the style first or create it manually.

6. **Brewery Auto-Creation**: When importing beers, if a brewery doesn't exist, it will be created automatically from the `<BREWERY>` field.

7. **Duplicate Prevention**: The system checks for existing styles based on name and category number to prevent duplicates.

### Common Import Sources

- **BJCP Style Guidelines**: Download official BJCP style XML files for complete style libraries
- **BeerSmith**: Export recipes as BeerXML from BeerSmith software
- **BrewFather**: Export recipes in BeerXML format
- **Custom Spreadsheets**: Convert your own beer data to XML format using Excel or similar tools

---

## Common Tasks

### Adding Your First Beer

1. Go to **Beer List** → Click "Add Beer"
2. Fill in beer details (name, style, ABV, IBU)
3. Upload a beer image (optional)
4. Save the beer

### Configuring Number of Taps

Before putting beers on tap, you may need to configure how many taps your system has:

1. Go to **Tap List** page
2. Click the **Settings** button at the top
3. Locate **Number of Taps** field in the "General Tap Setup" section
4. Enter the total number of taps in your keezer/kegerator
   - Example: 4, 6, 8, etc.
   - This determines how many tap columns appear on your display
5. Click **Save** at the bottom of the settings panel
6. The tap list will now show the correct number of taps
7. You can configure each tap individually (assign beers, set flow pins, etc.)

**Note**: Changing the number of taps adds or removes tap entries. If reducing taps, data from removed taps is preserved in the database but hidden from the display.

### Adding a Keg to the System

Before putting a beer on tap, you need to add the physical keg to your inventory:

1. Go to **Keg List** → Click **Add Keg**
2. Fill in the required fields (marked with *):
   - **Label**: A unique identifier for this keg (e.g., "Keg #1", "Sankey 1", "Corny A")
   - **Status**: Select keg status:
     - "Available" - Ready to be filled/tapped
     - "In Use" - Currently on tap
     - "In Transit" - Being transported
     - "Needs Maintenance" - Requires cleaning/repair
   - **Type**: Select keg type:
     - "Corny (5 gal)" for Cornelius kegs
     - "Sixth Barrel", "Quarter Barrel", "Half Barrel" for commercial sizes
     - Other sizes as configured in your system
7. Click **Save** to add the keg to your inventory

**Tips**:
- Add all your physical kegs to the inventory first, even if they're empty
- For load cell accuracy, weigh empty kegs individually and record their empty weights
- Update "Start Amount" each time you fill a keg, this can be done from the tap list when tapping a keg.
- The system will track "Current Amount" automatically if flow meters or load cells are configured

### Putting a Beer on Tap

Once you have beers and kegs in your system, you can assign them to taps:

1. Go to **Tap List** page
2. Locate the tap you want to use (Tap 1, Tap 2, etc.)
3. In the **Keg** dropdown for that tap, select which keg to put on tap
  - If the keg is already on tap the tap number will show in paranthesis next to the keg number
  - If you select a keg already on a different tap it will be moved to that new tap number.
4. The beer information associated to the keg will automatically populate on the tap display
   - Adjust the Beer Name as needed
   - Adjust the current Amount as needed
*Repeat Steps 2-4 as for any other taps that changed
5. Click **Save** at the bottom of the page to apply changes
6. The tap will now display the beer on your public tap list

**One-Time Tap Configuration** (only needed during initial setup):
- **Flow Pins**: Set the GPIO pin for each tap's flow meter (Tap List → Settings)
- **Valve Pins**: Set the GPIO pin for each tap's valve (Tap List → Settings)
- **Calibration**: Calibrate flow meters for accuracy (see "Calibrating Flow Meters" below)
- Once configured, these settings persist and don't need to change when swapping kegs

**Note**: The number of visible taps is controlled by the "Number of Taps" setting in Tap List → Settings. Make sure this is set correctly before assigning kegs.

**Kicking a Keg** (Marking as Empty):
1. Go to **Tap List**
2. Locate the tap to remove
3. Change Keg to blank (Empty)
4. Click **Save** at the bottom of the page to apply changes

### Calibrating Flow Meters

1. Go to **Tap List** → Select tap
2. Click "Calibrate"
3. Pour a measured amount (e.g., 500ml)
4. Enter actual volume poured
5. System calculates pulses per volume
6. Save calibration

### Viewing Pour Statistics

1. Go to **Statistics** section
2. Choose view: Beer, Tap, or Drinker
3. Select date range
4. View graphs and data
5. Export  CSV if needed

### Setting Up RFID Users

1. Go to **User List** → Add user
2. Save user with email
3. Go to **User RFID**
4. Have user scan their card/tag
  - The "Save Non User RFID tage when Scanned" Setting must be On for RPints to save the RFID
5. Assign card ID to user
6. Test by scanning card

### Monitoring Keg Levels

With flow meters installed:
1. Assign keg to tap (see above)
2. System automatically tracks pours
3. View **Main Display** for current levels in a nice graphic
4. Set low-keg alerts by color of the graphic

### Adding Hardware After Installation

If you want to add flow meters, RFID readers, temperature probes, or other hardware after your initial installation:

1. **Rerun the installer** on your Raspberry Pi:
   ```bash
   sudo ./util/installRaspberryPints
   ```
   Or if you no longer have the files:
   ```bash
   curl -L install.rpints.com | sudo bash
   ```

2. **Select "Reconfigure Pi/Enable Features"** when prompted with the installation options

3. The installer will:
   - Detect your existing RaspberryPints installation
   - Present the same hardware configuration options as initial setup
   - Add the selected hardware without affecting your existing data, beers, kegs, or settings

4. Follow the hardware-specific prompts:
   - **Flow Meters**: Configure Arduino/Alamode connection and communication method
   - **RFID**: Set GPIO pins for card readers
   - **Motion Sensors**: Configure PIR sensor pins and screen wake behavior
   - **Temperature Probes**: Enable 1-wire interface for DS18B20 sensors
   - **MQTT**: Set up broker connection for wireless flow meters

5. **Reboot when prompted** to apply the hardware changes

6. **Configure the hardware** in the admin interface:
   - Go to **Tap List** → **Settings** to enable and configure flow meters
   - Go to **RFID Readers** to add and test RFID readers
   - Go to **Temperature Probes** to assign probes to kegs/fermenters
   - Go to **Motion Detectors** to configure screen wake behavior

> **Tip:** This reconfiguration process is safe and non-destructive. Your existing database, kegs, beers, and pours will not be affected.

---

## Troubleshooting

### Can't Access Web Interface

- Check Pi is powered on and connected to network
- Verify web server is running: `sudo systemctl status apache2` or `nginx`
- Check firewall settings
- Try IP address instead of hostname

### Flow Meters Not Working

- Verify Arduino/Alamode connection
- Check if flowmon service is running: `sudo systemctl status flowmon`
- Restart service: `sudo /etc/init.d/flowmon restart`
- Check Config.py settings in `/var/www/html/python/`

### Database Connection Errors

- Verify MySQL is running: `sudo systemctl status mariadb`
- Check credentials in `/var/www/html/admin/includes/conn.php`
- Test connection: `mysql -u RaspberryPints -p`

### Temperature Probes Not Detected

- Verify 1-wire is enabled: `lsmod | grep w1`
- Check boot config: `cat /boot/config.txt | grep w1`
- List probes: `ls /sys/bus/w1/devices/`
- Restart flowmon service

### Display Issues

- Check HDMI settings in `/boot/config.txt`
- Verify resolution settings (hdmi_group, hdmi_mode)
- Test with: `xrandr` command
- Check Chromium kiosk mode in autostart

### Customizing the Header Display (headerRight.php)

The right side of the tap list header can display various information widgets that rotate automatically. The file `includes/headerRight.php` controls this dynamic display area.

**Available Display Widgets**:

1. **Temperature Display** (ConfigName: `ShowTempOnMainPage`)
   - Shows readings from all active temperature probes
   - Displays probe name/number, temperature, and last reading time
   - Supports both DS18B20 probes and Plaato temperature sensors
   - Includes visual thermometer indicator
   - Temperature shown in your configured display unit (°F/°C)
   - Example: "Probe 1: 38.5°F | 2024-01-15 3:45 PM"

2. **Last Pour** (ConfigName: `ShowLastPour`)
   - Shows the most recent pour from any tap
   - Displays: Username (if RFID used), Beer Name, Amount Poured
   - Example: "John Smith | IPA | 16.0 oz"
   - Updates in real-time as new pours occur
   - Great for social engagement at parties/events

3. **RaspberryPints Logo** (ConfigName: `ShowRPLogo`)
   - Displays the RaspberryPints project logo
   - Links to [raspberrypints.com](http://www.raspberrypints.com)
   - Two sizes available:
     - Standard: 100px height (default)
     - High-res: 200px height (when `UseHighResolution` enabled)
   - Good for crediting the project

4. **Analog Clock** (ConfigName: `ShowAnalogClock`)
   - Displays a circular clock face with moving hands
   - Canvas-based animated clock (95x95px)
   - Shows current system time
   - Classic appearance, good for traditional bar/pub aesthetics

5. **Digital Clock** (ConfigNames: `ShowDigitalClock` or `ShowDigitalClock24`)
   - Displays current time in digital format
   - Choose between:
     - 12-hour format with AM/PM (`ShowDigitalClock`)
     - 24-hour format (`ShowDigitalClock24`)
   - Large, easy-to-read font (24px)
   - Updates every second

6. **Fermenter Status** (ConfigName: `ShowFermOnMainPage`)
   - Shows active fermentation vessels
   - Displays: Fermenter label, beer name, batch name
   - Visual fermenter graphic colored by beer SRM
   - If iSpindel connected: shows current gravity and temperature
   - Shows fill date
   - Example: "Conical 1 | IPA-Batch:5 | 1.015 | 68.2°F | Filled: 2024-01-10"
   - Cycles through all active fermenters

7. **Gas Tank Status** (ConfigNames: `ShowGTOnMainPage`, `ShowAllGTOnMainPage`)
   - Shows gas tank (CO2/Nitrogen) levels
   - Visual tank graphic with fill level
   - Color-coded by remaining amount:
     - 🟢 Green: 45-100% full
     - 🟡 Yellow: 25-45% full
     - 🟠 Orange: 15-25% full
     - 🔴 Red: 0-15% full (needs refill)
   - Requires load cells for accurate weight tracking
   - `ShowAllGTOnMainPage`: If enabled, shows all tanks; if disabled, only shows dispensing tanks
   - Displays tank label and current level

**How the Rotation Works**:

The header cycles through enabled widgets based on the **Info Time** setting (ConfigName: `InfoTime`):
- **Positive value**: Seconds to display each widget before rotating to next
  - Example: Set to `5` = each widget shows for 5 seconds
- **0**: Rotates on each page refresh
- **Negative value**: Displays all enabled widgets at once (no rotation)
  - Best for wide displays or when you want all info visible

**Configuration**:

All display options are controlled through **Admin → Personalize → Display Preferences**:
1. Enable/disable each widget using the toggle switches
2. Set rotation speed using the Info Time setting (if available)
3. Save changes
4. The main tap list display updates immediately

**Tips**:
- Enable only the widgets you find useful to avoid clutter
- Use rotation (positive Info Time) for smaller displays
- Show all widgets (negative Info Time) on large/wide displays (1920px+)
- Fermenter and Gas Tank displays cycle through multiple items if you have several
- Temperature display automatically combines readings from multiple probes
- Consider your audience: bars may prefer clock/logo, homebrewers may prefer fermenters/temps

**Example Configurations**:

*Homebrew Setup (rotating every 10 seconds)*:
- ✅ Temperature Display
- ✅ Fermenter Status
- ✅ Gas Tank Status
- ✅ Digital Clock
- ❌ Last Pour (private use)
- ❌ Logo

*Public Bar Setup (rotating every 5 seconds)*:
- ✅ Last Pour (social proof)
- ✅ Digital Clock
- ✅ RaspberryPints Logo
- ✅ Temperature Display
- ❌ Fermenter Status (backend info)
- ❌ Gas Tank Status (operational info)

### Support

- **GitHub**: [RaspberryPints GitHub Repository](https://github.com/RaspberryPints/RaspberryPints)
- **HomeBrewTalk Forum**: Search for RaspberryPints threads [Main Thread](https://homebrewtalk.com/threads/version-2-release-raspberrypints-digital-taplist-solution.487694)
- **Documentation**: Check the project README.md

### Credits

RaspberryPints is an open-source project with contributions from:
- Original developers
- RandR+ (rtlindne fork)
- Tobor
- day_trippr
- Lee C. Bussy (@LBussy) - Install script
- And many community contributors

---

## Quick Reference

### Default Credentials

- **Admin URL**: `http://[pi-ip]/admin/`
- **Default DB User**: `RaspberryPints`
- **Default DB Pass**: `RaspberryPints` (change this!)
- **Default DB Name**: `raspberrypints`

### Important Commands

```bash
# Restart web server
sudo systemctl restart apache2
# or
sudo systemctl restart nginx

# Restart flowmon (flow meters)
sudo /etc/init.d/flowmon restart

# View flowmon status
sudo systemctl status flowmon

# Database backup
sudo mysqldump raspberrypints > backup.sql

# Check installed version
cat /var/www/html/includes/config.php | grep rpintsversion
```

### GPIO Pin Reference

Common GPIO pins for sensors:
- **RFID SDA**: Any GPIO (commonly GPIO 8)
- **Temperature**: GPIO 4 (default 1-wire)
- **Motion Sensor**: Any GPIO (commonly GPIO 17)
- **Flow Meters**: Via Arduino/Alamode (not direct GPIO)

---
# Connecting Flow Meters to Arduino and Integrating with Raspberry Pi

## Overview

This guide explains the components needed and the steps involved to:
- Connect flow meters (e.g., water flow sensors) to an Arduino.
- Have the Arduino measure flow and send data to a Raspberry Pi for logging or further processing.

---

## Parts Needed

### 1. **Flow Meter / Flow Sensor**
- Example: YF-S201 Water Flow Sensor (compatible with most Arduinos)
- Outputs pulses proportional to flow rate

### 2. **Arduino Board**
- Example: Arduino Uno, Nano, or Mega
- Reads pulse signals from the flow sensor

### 3. **Resistor (10K Ω recommended)**
- For the pull-down on the signal line of the flow sensor

### 4. **Connecting Wires / Jumper Cables**

### 5. **Power Supply**
- USB power for Arduino
- Power source for Raspberry Pi

### 6. **Raspberry Pi**
- Any model with USB ports (e.g., Pi 3, Pi 4)
- Runs script/software to receive data from Arduino

### 7. **USB Cable (Arduino to Raspberry Pi)**
- Standard USB A/B or Micro USB, depending on Arduino model

---

## Wiring Diagram
Flow Meter (YF-S201) | | | | 
 | +----> (White Wire: Signal) ------------> Arduino Digital Pin X  (optional pull-down resistor to GND)
 | +----> (Red Wire: VCC) -----------------> Arduino 5V 
 | +----> (Black Wire: GND) ---------------> Arduino GND

- **Signal pin** goes to Arduino digital I/O pin (e.g., D2), with a 10K pull-down resistor to ground.
- You can chain flow meters on the +5V and GND 
---

## Step-by-Step Instructions

### 1. **Connect Flow Meter to Arduino**
- Connect:
 - Red wire (VCC) to Arduino 5V
 - Black wire (GND) to Arduino GND
 - White wire (Signal) to Arduino Digital Pin 2
 - Place a 10K Ω resistor between Signal and GND

The Arduino counts pulses for one second and prints the flow rate via Serial.
3. Connect Arduino to Raspberry Pi
Plug Arduino into Raspberry Pi using USB cable.

4. Read Data on Raspberry Pi
Python Example to Read Serial Data:

Tips & Notes
Make sure your user has permission to access the serial port on Raspberry Pi (sudo usermod -a -G dialout pi).

[YF-S201 Datasheet](https://components101.com/sensors/yf-s201-water-flowmeter-sensor)
[Digiten Flowmeters](https://www.digiten.shop/collections/counter)
[Arduino Serial Communication](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Serial)
[PySerial Documentation](https://pyserial.readthedocs.io/)

---

# Connecting RFID Readers to Raspberry Pi

## Overview

RFID (Radio-Frequency Identification) readers allow users to scan RFID tags/cards to track who is pouring beer. RaspberryPints supports RC522 RFID readers connected via SPI.

---

## Parts Needed

### 1. **RC522 RFID Reader Module**
- Compatible with 13.56MHz RFID tags (ISO 14443A)
- Common modules: MFRC522

### 2. **RFID Tags/Cards**
- 13.56MHz tags (keyfobs, cards, stickers)
- Compatible with RC522 reader

### 3. **Jumper Wires**
- Female-to-female jumper wires for connecting to Raspberry Pi GPIO

### 4. **Raspberry Pi**
- Any model with GPIO pins (Pi 3, Pi 4, Zero W, etc.)

---

## Wiring Diagram

### RC522 to Raspberry Pi GPIO Connection

```
RC522 Module          Raspberry Pi GPIO
─────────────────────────────────────────────
SDA (SS)     ──────►  GPIO 8  (Pin 24) - Chip Select
SCK          ──────►  GPIO 11 (Pin 23) - SPI Clock
MOSI         ──────►  GPIO 10 (Pin 19) - SPI MOSI
MISO         ──────►  GPIO 9  (Pin 21) - SPI MISO
IRQ          ──────►  Not Connected (optional)
GND          ──────►  GND     (Pin 6, 9, 14, 20, or 25)
RST          ──────►  GPIO 25 (Pin 22) - Reset (configurable)
3.3V         ──────►  3.3V    (Pin 1 or 17)
```

**⚠️ IMPORTANT**: RC522 operates at **3.3V** - Do NOT connect to 5V or you will damage the module!

### Visual Pin Layout

```
    RC522 Module
    ┌─────────────┐
    │ SDA  SCK    │
    │ MOSI MISO   │
    │ IRQ  GND    │
    │ RST  3.3V   │
    └─────────────┘
```

### Raspberry Pi GPIO Pinout (Top View)

```
     3.3V (1)  ●  ● (2)  5V
    GPIO2 (3)  ●  ● (4)  5V
    GPIO3 (5)  ●  ● (6)  GND
    GPIO4 (7)  ●  ● (8)  GPIO14
      GND (9)  ●  ● (10) GPIO15
   GPIO17 (11) ●  ● (12) GPIO18
   GPIO27 (13) ●  ● (14) GND
   GPIO22 (15) ●  ● (16) GPIO23
     3.3V (17) ●  ● (18) GPIO24
   GPIO10 (19) ●  ● (20) GND
    GPIO9 (21) ●  ● (22) GPIO25  ◄── RST
   GPIO11 (23) ●  ● (24) GPIO8   ◄── SDA
      GND (25) ●  ● (26) GPIO7
```

---

## Step-by-Step Connection Instructions

### 1. **Enable SPI on Raspberry Pi**

The installer enables this automatically, or manually:

```bash
sudo raspi-config
# Navigate to: Interface Options → SPI → Enable
```

Verify SPI is enabled:
```bash
lsmod | grep spi
# Should show: spi_bcm2835
```

### 2. **Connect the RC522 Module**

**Power Connections**:
1. RC522 **3.3V** → Pi **Pin 1** (3.3V)
2. RC522 **GND** → Pi **Pin 6** (GND)

**SPI Connections**:
3. RC522 **SDA** → Pi **Pin 24** (GPIO 8)
4. RC522 **SCK** → Pi **Pin 23** (GPIO 11)
5. RC522 **MOSI** → Pi **Pin 19** (GPIO 10)
6. RC522 **MISO** → Pi **Pin 21** (GPIO 9)

**Control Connection**:
7. RC522 **RST** → Pi **Pin 22** (GPIO 25)

**IRQ** pin can remain unconnected (not used by default).

### 3. **Install Required Python Libraries**

The installer handles this, or manually:

```bash
cd /var/www/html/python/SPI-Py
sudo python setup.py install
```

### 4. **Configure RFID Reader in RaspberryPints**

1. Go to **Admin → Advanced Hardware → RFID Readers**
2. Click **Add RFID Reader**
3. Configure:
   - **Name**: "Main Reader" (or descriptive name)
   - **Type**: RC522 (0)
   - **Pin**: 8 (SDA pin number)
   - **Priority**: 0 (for single reader)
4. Click **Save**

### 5. **Register RFID Tags**

1. Go to **Admin → User Management → Users**
2. Add or edit a user
3. Have user scan their RFID tag while on this page
4. The tag ID will auto-populate
5. Save the user

---

## Multiple RFID Readers

To use multiple RFID readers:

1. Each reader needs a unique **SDA (Chip Select)** pin
2. All readers share **SCK, MOSI, MISO** pins
3. Common SDA pins: GPIO 8, GPIO 7, GPIO 5

**Example 2-Reader Setup**:
- Reader 1: SDA → GPIO 8 (Pin 24)
- Reader 2: SDA → GPIO 7 (Pin 26)
- Both share: SCK, MOSI, MISO, GND, 3.3V

---

## Troubleshooting

**RFID reader not detected**:
1. Check SPI is enabled: `lsmod | grep spi`
2. Verify 3.3V connection (NOT 5V!)
3. Check all wire connections
4. Test with: `ls /dev/spi*` (should show `/dev/spidev0.0`)

**Tags not scanning**:
1. Ensure tags are 13.56MHz (not 125kHz)
2. Hold tag within 1-2cm of reader antenna
3. Check debug logs in Admin → RPints Log

---

# Connecting DS18B20 Temperature Probes

## Overview

DS18B20 digital temperature sensors provide accurate temperature monitoring for kegs, fermenters, or ambient conditions. They use the 1-wire protocol and can be daisy-chained on a single GPIO pin.

---

## Parts Needed

### 1. **DS18B20 Temperature Sensor**
- Waterproof version recommended for keg/fermenter monitoring
- Available as bare sensor or waterproof probe
- Operating range: -55°C to +125°C (-67°F to +257°F)

### 2. **4.7kΩ Resistor**
- Pull-up resistor for 1-wire bus
- Required for stable operation

### 3. **Jumper Wires**
- For connecting to Raspberry Pi GPIO

### 4. **Optional: Terminal Block**
- For easier probe swapping and organization

---

## Wiring Diagram

### Single DS18B20 Connection

```
DS18B20 Probe           Raspberry Pi GPIO
─────────────────────────────────────────────
Red (VCC)      ──────►  3.3V    (Pin 1 or 17)
Yellow (Data)  ──────►  GPIO 4  (Pin 7) - Default 1-wire pin
                           │
                           └──[4.7kΩ resistor]──► 3.3V
Black (GND)    ──────►  GND     (Pin 6, 9, 14, 20, or 25)
```

### Multiple DS18B20 Sensors (Daisy Chain)

```
              ┌─ 3.3V ─┬─[4.7kΩ]─┬─ GPIO 4
              │         │         │
    Probe 1:  Red ──────┤         │
              Yellow ───┴─────────┘
              Black ─── GND
              
    Probe 2:  Red ──────┤         │
              Yellow ───┴─────────┘
              Black ─── GND
              
    Probe 3:  Red ──────┤         │
              Yellow ───┴─────────┘
              Black ─── GND
```

**Note**: All probes share the same GPIO 4 (1-wire bus). One 4.7kΩ resistor is used for all probes.

---

## Step-by-Step Connection Instructions

### 1. **Enable 1-Wire Interface**

The installer enables this automatically, or manually:

```bash
sudo raspi-config
# Navigate to: Interface Options → 1-Wire → Enable
```

Or edit `/boot/config.txt`:
```bash
sudo nano /boot/config.txt
# Add this line:
dtoverlay=w1-gpio
```

Reboot:
```bash
sudo reboot
```

### 2. **Physical Connection**

**For Single Probe**:
1. Connect probe **Red** wire to Pi **Pin 1** (3.3V)
2. Connect probe **Yellow** wire to Pi **Pin 7** (GPIO 4)
3. Connect probe **Black** wire to Pi **Pin 6** (GND)
4. Install 4.7kΩ resistor between **Yellow (Data)** and **Red (3.3V)**

**For Multiple Probes**:
1. Connect all **Red** wires together to **3.3V**
2. Connect all **Yellow** wires together to **GPIO 4**
3. Connect all **Black** wires together to **GND**
4. One 4.7kΩ resistor between data line and 3.3V

### 3. **Verify Probes Are Detected**

```bash
# Load kernel modules (if not auto-loaded)
sudo modprobe w1-gpio
sudo modprobe w1-therm

# List detected probes
ls /sys/bus/w1/devices/
```

You should see directories like `28-xxxxxxxxxxxx` (one per probe).

**Read temperature manually**:
```bash
cat /sys/bus/w1/devices/28-xxxxxxxxxxxx/w1_slave
```

### 4. **Configure in RaspberryPints**

1. Go to **Admin → Advanced Hardware → Temperature Probes**
2. Click **Auto Discover** button
3. System will detect all connected probes
4. For each probe:
   - **Name**: Descriptive name (e.g., "Keg 1", "Fermenter", "Ambient")
   - **State Pin**: Optional GPIO for status LED
   - **Adjustment**: Temperature offset for calibration (±degrees)
5. Configure system settings:
   - **Check Delay**: Seconds between readings (default: 60)
   - **Lowest/Highest Temperature**: Bounds for valid readings
6. Click **Save**

---

## Tips for Temperature Monitoring

**Probe Placement**:
- **Kegs**: Attach probe to side of keg with thermal paste or tape
- **Fermenters**: Insert waterproof probe through thermowell
- **Ambient**: Mount probe away from direct heat/cold sources

**Calibration**:
- Use ice water (0°C/32°F) as reference
- Adjust "Adjustment" field to correct offset

**Wire Management**:
- Label each probe's unique ID for easy identification
- Use terminal blocks for easy probe swapping

---

## Troubleshooting

**Probes not detected**:
1. Check 1-wire is enabled: `lsmod | grep w1`
2. Verify 4.7kΩ resistor is installed
3. Check wire connections (especially data line)
4. Try rebooting after enabling 1-wire

**Erratic readings**:
1. Add or replace 4.7kΩ pull-up resistor
2. Shorten wire length (max ~10 meters recommended)
3. Use shielded cable for long runs
4. Check for loose connections

**Wrong probe ID**:
- Each DS18B20 has unique 64-bit ID (28-xxxxxxxxxxxx)
- Note the ID when connecting to identify which physical probe

---

# Connecting PIR Motion Sensors

## Overview

PIR (Passive Infrared) motion sensors detect movement and can wake the display when someone approaches the tap list.

---

## Parts Needed

### 1. **HC-SR501 PIR Motion Sensor**
- Common and inexpensive PIR module
- 3-7 meter detection range
- Adjustable sensitivity and time delay

### 2. **Jumper Wires**
- Female-to-female for connecting to Pi GPIO

---

## Wiring Diagram

```
HC-SR501 Module        Raspberry Pi GPIO
─────────────────────────────────────────────
VCC          ──────►  5V      (Pin 2 or 4)
OUT          ──────►  GPIO 17 (Pin 11) - Configurable
GND          ──────►  GND     (Pin 6, 9, 14, 20, or 25)
```

### HC-SR501 Module Layout

```
    ┌───────────────┐
    │   [Dome Lens] │
    │               │
    │  ┌─┐     ┌─┐  │  ← Potentiometers
    │  │S│     │T│  │     S = Sensitivity
    │  └─┘     └─┘  │     T = Time Delay
    │               │
    │  [ VCC ]      │
    │  [ OUT ]      │  ← Jumper: H=Repeating, L=Single
    │  [ GND ]      │
    └───────────────┘
```

---

## Step-by-Step Connection Instructions

### 1. **Physical Connection**

1. Connect sensor **VCC** to Pi **Pin 2** (5V)
2. Connect sensor **GND** to Pi **Pin 6** (GND)
3. Connect sensor **OUT** to Pi **Pin 11** (GPIO 17) or any available GPIO

### 2. **Configure PIR Sensor Hardware**

**Jumper Setting** (on back of module):
- Set jumper to **H position** (Repeating Trigger Mode)
- This allows continuous detection while motion present

**Sensitivity Adjustment** (left potentiometer):
- Turn clockwise to increase range
- Start at 50% (middle position)
- Adjust based on detection distance needed

**Time Delay Adjustment** (right potentiometer):
- Turn counter-clockwise for minimum delay
- RaspberryPints handles timing, so use shortest delay
- Typical: 3-5 seconds minimum

### 3. **Configure in RaspberryPints**

1. Go to **Admin → Advanced Hardware → Motion Detectors**
2. Click **Add Motion Detector**
3. Configure:
   - **Name**: "Front Sensor" (descriptive name)
   - **Pi Pin**: 17 (or GPIO number you used)
   - **Priority**: 0 (lower = higher priority for multiple sensors)
   - **LED Pin**: Optional GPIO for indicator LED
   - **Sound File**: Optional audio file path for alert sound
4. For MQTT-enabled remote sensors, configure MQTT fields
5. Click **Save**

### 4. **Configure Screen Wake Behavior**

Ensure xscreensaver is configured:
```bash
# Install if needed
sudo apt-get install xscreensaver -y

# Configure screensaver timeout
xscreensaver-demo
```

Set display power management in autostart:
```bash
nano ~/.config/lxsession/LXDE-pi/autostart
# Add these lines:
@xset s off
@xset -dpms
@xset s noblank
```

---

## Multiple Motion Sensors

To use multiple sensors:
1. Each sensor needs unique GPIO pin
2. Configure different priorities (0 = highest)
3. Higher priority sensor overrides others

**Example 2-Sensor Setup**:
- Front sensor: GPIO 17, Priority 0
- Side sensor: GPIO 27, Priority 1

---

## Troubleshooting

**Sensor always triggered**:
1. Reduce sensitivity (turn left pot counter-clockwise)
2. Check sensor isn't facing heat sources (heater, sunlight)
3. Ensure jumper is in correct position

**Sensor not triggering**:
1. Increase sensitivity (turn left pot clockwise)
2. Verify 5V power connection
3. Check GPIO pin number matches configuration
4. Test sensor LED (usually lights when motion detected)

**Display not waking**:
1. Check xscreensaver is installed and running
2. Verify motion detector is configured in admin
3. Check RPints logs for motion events

---

# Connecting HX711 Load Cells (Weight Scales)

## Overview

HX711 load cell amplifiers with strain gauge load cells provide accurate weight measurements for kegs and gas tanks. This enables automatic tracking of remaining beer/gas.

---

## Parts Needed

### 1. **HX711 Load Cell Amplifier Module**
- 24-bit ADC for precise weight measurement
- Amplifies small signals from load cells

### 2. **Load Cell (Strain Gauge)**
- Capacity depends on application:
  - **Kegs**: 50-100 lbs (20-50 kg) load cells
  - **Gas tanks**: 20-50 lbs (10-20 kg) load cells
- Common types: Single point, S-type, or platform load cells

### 3. **Platform/Mounting Hardware**
- For mounting load cells and supporting kegs/tanks
- Ensure stable, level surface

### 4. **Jumper Wires**
- For connecting to Raspberry Pi GPIO

---

## Wiring Diagram

### HX711 to Raspberry Pi Connection

```
HX711 Module          Raspberry Pi GPIO
─────────────────────────────────────────────
VCC (or VDD)  ──────►  5V or 3.3V (Pin 2 or 1)
GND           ──────►  GND     (Pin 6, 9, 14, 20, or 25)
DT (Data)     ──────►  GPIO 5  (Pin 29) - Configurable
SCK (Clock)   ──────►  GPIO 6  (Pin 31) - Configurable
```

### Load Cell to HX711 Connection

```
Load Cell Wire Colors     HX711 Terminals
───────────────────────────────────────────
Red    (Excitation+) ───► E+ or VCC
Black  (Excitation-) ───► E- or GND
White  (Signal+)     ───► A+ or S+
Green  (Signal-)     ───► A- or S-
```

**Note**: Wire colors may vary by manufacturer. Consult your load cell datasheet.

### Complete System Diagram

```
    ┌──────────┐
    │   Keg    │
    │  or Tank │
    └────┬─────┘
         │
    ┌────▼────────┐
    │  Platform   │
    │  (on Load   │
    │   Cells)    │
    └─────────────┘
         │
    ┌────▼────┐        ┌─────────────┐
    │  Load   ├───────►│   HX711     ├──► Raspberry Pi
    │  Cell   │        │  Amplifier  │    (DT → GPIO 5)
    └─────────┘        └─────────────┘    (SCK → GPIO 6)
```

---

## Step-by-Step Connection Instructions

### 1. **Connect Load Cell to HX711**

1. Identify load cell wires (use multimeter if needed):
   - Measure resistance between wires
   - Excitation wires: ~400-1000Ω
   - Signal wires: ~350-700Ω
   
2. Connect to HX711:
   - **Red** → E+
   - **Black** → E-
   - **White** → A+
   - **Green** → A-

### 2. **Connect HX711 to Raspberry Pi**

1. **Power**:
   - HX711 **VCC** → Pi **Pin 2** (5V) or **Pin 1** (3.3V)
   - HX711 **GND** → Pi **Pin 6** (GND)

2. **Data Lines** (example for first load cell):
   - HX711 **DT** → Pi **GPIO 5** (Pin 29) - Response Pin
   - HX711 **SCK** → Pi **GPIO 6** (Pin 31) - Command Pin

### 3. **Physical Installation**

**For Kegs**:
1. Place 3 or 4 load cells under platform corners
2. Ensure platform is level
3. Load cells should be the only support (no floor contact)
4. Place keg centered on platform

**For Gas Tanks**:
1. Mount load cell between tank support and floor
2. Ensure tank hangs from load cell (not resting on floor)
3. Secure to prevent swinging

### 4. **Configure in RaspberryPints**

1. Go to **Admin → Advanced Hardware → Load Cells**
2. Add load cell configuration:

**Per Load Cell Configuration**:
- **Tap/Gas Tank**: Select which tap/tank this measures
- **Command Pin**: GPIO for SCK (e.g., 6)
- **Response Pin**: GPIO for DT (e.g., 5)
- **Scale Ratio**: Calibration factor (see calibration below)
- **Offset**: Tare value (automatically set)
- **Update Variance**: Noise filter (grams, e.g., 50)
- **Unit**: Weight unit (lbs, kg, g, oz)
- **Tare Date**: Last calibration timestamp
- **Current Weight**: Real-time reading (read-only)

### 5. **Calibration Process**

**Step 1: Calculate Scale Ratio**

1. **Get Raw Reading with No Weight**:
   ```bash
   # In RPints debug mode, note the raw value with platform empty
   ```

2. **Place Known Weight** (e.g., 10 lbs or 5 kg):
   ```bash
   # Note the new raw value
   ```

3. **Calculate Ratio**:
   ```
   Scale Ratio = (Raw_WithWeight - Raw_Empty) / Known_Weight
   
   Example:
   Raw_Empty = 50000
   Raw_WithWeight = 150000  
   Known_Weight = 10 lbs
   Scale Ratio = (150000 - 50000) / 10 = 10000
   ```

4. Enter Scale Ratio in Load Cell configuration

**Step 2: Tare (Zero) the Scale**

1. Place empty keg (or tank) on platform
2. Click **Tare** button in Load Cells page
3. System records offset for this weight as "zero"

**Step 3: Set Update Variance**

- Filters out noise/vibrations
- Typical: 50-100 grams (prevents constant tiny updates)
- Adjust based on environment

**Step 4: Verify**

1. Place keg with known amount of beer
2. Check **Current Weight** matches expected
3. Adjust Scale Ratio if needed

---

## Multiple Load Cells

**For Multiple Taps**:
- Each tap/tank needs unique Command Pin and Response Pin pair
- Example:
  - Tap 1: Command=GPIO6, Response=GPIO5
  - Tap 2: Command=GPIO13, Response=GPIO19
  - Tap 3: Command=GPIO26, Response=GPIO21

**Sharing GPIO** (NOT recommended):
- Different Command pins can share Response pins
- Better to use unique pin pairs for each load cell

---

## Tips for Accurate Measurements

**Physical Setup**:
- Ensure platform doesn't touch walls/floor
- Level the platform (use bubble level)
- Isolate from vibrations
- Protect from temperature extremes

**Calibration**:
- Calibrate with weight similar to full keg (40-50 lbs)
- Re-tare after moving keg/platform
- Recalibrate if measurements drift over time

**Environmental**:
- Temperature affects accuracy
- Keep load cells dry
- Avoid mechanical stress on wires

---

## Troubleshooting

**No readings or zero values**:
1. Check power to HX711 (3.3V or 5V)
2. Verify DT and SCK connections
3. Check load cell wiring (E+, E-, A+, A-)
4. Test with multimeter: measure resistance across load cell wires

**Erratic/jumping readings**:
1. Increase Update Variance to filter noise
2. Check for loose connections
3. Ensure platform doesn't touch floor/walls
4. Shield data wires if near electrical noise sources

**Readings drift over time**:
1. Re-tare the scale
2. Check for temperature changes
3. Verify load cell is not mechanically stressed
4. Recalibrate Scale Ratio

**Wrong weight values**:
1. Recalculate and update Scale Ratio
2. Check Unit setting matches your expectations
3. Verify known calibration weight is accurate
4. Re-tare after adjusting

---

**Resources**:
- [HX711 Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf)
- [Load Cell Basics](https://learn.sparkfun.com/tutorials/load-cell-amplifier-hx711-breakout-hookup-guide)

---

# Connecting 12V Solenoid Tap Valves

## Overview

Solenoid valves allow automated control of beer taps through RaspberryPints. Since tap valves operate at 12VDC and the Raspberry Pi/Arduino operate at 3.3V/5V, relay modules are required as an interface to safely switch the higher voltage.

**⚠️ CRITICAL SAFETY WARNING**: NEVER connect 12V directly to Raspberry Pi or Arduino GPIO pins! This will permanently damage your device. Always use relay modules to isolate the high voltage circuit.

---

## Parts Needed

### 1. **12VDC Solenoid Valves**
- Standard keg tap solenoid valves
- Operating voltage: 12VDC
- Current draw: typically 0.5-1.0A per valve
- Connection: 1/4" or 3/8" barb fittings

### 2. **Relay Module**
- Single channel relay per valve
- Or multi-channel relay board (2, 4, 8, or 16 channels)
- Specifications:
  - Control voltage: 5VDC (trigger from Pi/Arduino)
  - Switching capacity: 10A @ 12VDC (minimum)
  - Type: Active LOW or Active HIGH (note which type)
- Common modules: SainSmart, Elegoo, or similar relay boards

### 3. **12VDC Power Supply**
- Capacity: Calculate total valve current + 20% margin
  - Example: 4 valves × 1A = 4A → use 5A supply
- Regulated 12V DC adapter
- Barrel jack or screw terminals

### 4. **Wiring Components**
- 18-22 AWG wire for 12V circuit (power to valves)
- 22-24 AWG wire for 5V control signals (Pi to relay)
- Wire connectors or terminal blocks
- Heat shrink tubing (recommended)

### 5. **Optional: Flyback Diodes**
- 1N4007 diodes (one per valve)
- Protects relays from voltage spikes when valve deactivates
- Often built into relay modules

---

## Understanding the Circuit

### Two Separate Circuits

**Low Voltage Control Circuit (5V)**:
- Pi/Arduino GPIO → Relay IN pin (control signal)
- Pi/Arduino 5V → Relay VCC (powers relay coil)
- Pi/Arduino GND → Relay GND (common ground)

**High Voltage Switching Circuit (12V)**:
- 12V Power Supply + → Relay COM (Common)
- Relay NO (Normally Open) → Valve positive terminal
- Valve negative terminal → 12V Power Supply - (ground)

### How It Works

1. GPIO pin sends 5V signal to relay IN pin
2. Relay coil energizes, closing the switch
3. COM connects to NO, completing 12V circuit
4. 12V flows through valve, opening it
5. GPIO goes LOW, relay opens, valve closes

---

## Wiring Diagram

### Single Valve Setup

```
12V Power Supply                Relay Module              Solenoid Valve
─────────────────              ───────────────            ──────────────
                               
    (+) ────────────────────► COM                         
                                │                         
                               NO ──────────────────────► (+) Terminal
                                                           │
    (-) ────────────────────────────────────────────────► (-) Terminal
                               
                               
Raspberry Pi / Arduino         Relay Control Side
──────────────────            ───────────────────
                               
GPIO (e.g., 23) ──────────────► IN (Control Pin)

5V ────────────────────────────► VCC (Relay Power)

GND ───────────────────────────► GND (Common Ground)
```

### Complete System Diagram with 2 Valves

```
                    ┌─────────────────┐
                    │  12V DC Power   │
                    │     Supply      │
                    └────┬───────┬────┘
                         │       │
                        (+)     (-)
                         │       │
        ┌────────────────┴───┐   │
        │                    │   │
        │  ┌──────────────┐  │   │
        │  │  Relay 1     │  │   │
        └─►│  COM    NO   ├──┼───┼──► Valve 1 (+)
           │              │  │   │         │
           │  IN  VCC GND │  │   │         │
           └──┬───┬───┬───┘  │   │    Valve 1 (-)
              │   │   │      │   │         │
              │   │   │      │   └─────────┴──────┐
        ┌─────┴───┘   │      │                    │
        │             │      │                    │
        │  ┌──────────────┐  │                    │
        │  │  Relay 2     │  │                    │
        └─►│  COM    NO   ├──┼────────────────────┤
           │              │  │         Valve 2 (+)│
           │  IN  VCC GND │  │                    │
           └──┬───┬───┬───┘  │         Valve 2 (-)│
              │   │   │      └────────────────────┘
              │   │   │
    ┌─────────┴───┴───┴──────────┐
    │   Raspberry Pi / Arduino   │
    │                            │
    │  GPIO 23 ──► Relay 1 IN    │
    │  GPIO 24 ──► Relay 2 IN    │
    │  5V      ──► Relay VCC     │
    │  GND     ──► Relay GND     │
    └────────────────────────────┘
```

---

## Step-by-Step Connection Instructions

### 1. **Prepare the Relay Module**

1. Identify relay module pins:
   - **VCC**: Power input (5V from Pi/Arduino)
   - **GND**: Ground (common with Pi/Arduino)
   - **IN**: Control signal input (from GPIO)
   - **COM**: Common terminal (12V input)
   - **NO**: Normally Open terminal (to valve)
   - **NC**: Normally Closed terminal (not used)

2. Check if relay is Active HIGH or Active LOW:
   - **Active LOW**: Relay activates when GPIO is LOW (0V) - most common
   - **Active HIGH**: Relay activates when GPIO is HIGH (5V)
   - RaspberryPints typically uses Active LOW relays

### 2. **Connect Low Voltage Control Circuit**

1. **From Raspberry Pi/Arduino to Relay**:
   - Pi/Arduino **5V** → Relay module **VCC**
   - Pi/Arduino **GND** → Relay module **GND**
   - Pi/Arduino **GPIO 23** → Relay 1 **IN** (for first valve)
   - Pi/Arduino **GPIO 24** → Relay 2 **IN** (for second valve)
   - Continue for additional valves...

**Example GPIO Pin Assignments**:
- Tap 1 Valve: GPIO 23 (Pi Pin 16)
- Tap 2 Valve: GPIO 24 (Pi Pin 18)
- Tap 3 Valve: GPIO 25 (Pi Pin 22)
- Tap 4 Valve: GPIO 8 (Pi Pin 24)

### 3. **Connect High Voltage Switching Circuit**

1. **12V Power Supply to Relay COM terminals**:
   - Connect 12V supply **positive (+)** to all relay **COM** terminals
   - Can use bus bar or daisy chain across relay COM pins

2. **Relay NO to Valve Positive**:
   - Connect relay **NO** terminal to valve **positive terminal**
   - Each relay NO goes to its respective valve

3. **Valve Negative to 12V Ground**:
   - Connect all valve **negative terminals** together
   - Connect to 12V power supply **negative (-)**

**⚠️ IMPORTANT**: 
- The 12V circuit is completely isolated from the Pi/Arduino
- Only the relay coil (VCC/GND/IN) connects to Pi
- Common ground ensures proper switching

### 4. **Add Flyback Diodes (Recommended)**

If relay module doesn't have built-in protection:

1. For each valve, add a 1N4007 diode across valve terminals
2. Diode **cathode** (stripe) → valve **positive**
3. Diode **anode** → valve **negative**
4. This protects against voltage spikes when valve closes

### 5. **Secure Connections**

1. Use terminal blocks for easy maintenance
2. Label all wires (valve number, positive/negative)
3. Use heat shrink tubing on exposed connections
4. Zip-tie wire bundles for organization
5. Keep 12V wiring away from signal wires

---

## Configuration in RaspberryPints

### 1. **Enable Tap Valves**

1. Go to **Admin → Tap List**
2. Click **Settings** button
3. Configure:
   - **Use Tap Valves**: Check to enable
   - **Use 3-Wire Valves**: Uncheck (for standard 2-wire valves)
   - **Valves Power Pin**: Leave blank (external 12V supply)
   - **Valves On Time**: Duration in milliseconds (e.g., 500ms)

### 2. **Configure Individual Tap Valves**

In **Tap List** page, for each tap:
- **Valve Pin**: Enter GPIO number (e.g., 23, 24, 25)
- **Valve PI Pin**: Check box if pin is on Raspberry Pi (vs. Arduino)

### 3. **Test Valves**

1. In Tap List, locate valve control buttons
2. Click **"Let it flow"** to open valve
3. Verify:
   - Relay clicks (audible)
   - Valve opens (beer flows)
   - LED on relay board lights up
4. Click **"Stop flow"** to close valve

---

## Multiple Valve Configurations

### Option 1: Pi GPIO Control (Recommended for 1-8 Valves)

- Each valve controlled by dedicated Pi GPIO
- Direct control from RaspberryPints
- Simpler wiring, no Arduino needed
- Limited by available GPIO pins

**GPIO Pin Recommendations**:
- Use GPIO 23, 24, 25, 8, 7, 12, 16, 20, 21
- Avoid GPIO 2, 3 (I2C), GPIO 14, 15 (Serial)
- Document which GPIO controls which tap

### Option 2: Arduino Control (For 8+ Valves)

- Arduino controls relays via serial commands from Pi
- Requires Arduino/Alamode setup
- Configure valve pins in Arduino firmware
- More complex but supports many valves

### Option 3: Shift Registers (Advanced)

- Use 74HC595 shift registers to expand GPIO
- Control 8+ valves with 3 GPIO pins
- Requires custom coding
- Best for large tap systems (16+ taps)

---

## Troubleshooting

### Valve Doesn't Open

1. **Check GPIO signal**:
   ```bash
   # Test GPIO manually (GPIO 23 example)
   gpio -g mode 23 out
   gpio -g write 23 0  # For Active LOW relay
   # Should hear relay click
   ```

2. **Verify relay module**:
   - Check VCC has 5V power
   - Check GND is connected
   - LED on relay should light when activated

3. **Check 12V circuit**:
   - Measure voltage at relay COM (should be 12V)
   - Check valve connections (tight, no corrosion)
   - Test valve directly with 12V (bypass relay)

### Relay Clicks But Valve Doesn't Open

1. Check 12V power supply capacity (sufficient amps)
2. Measure voltage at valve terminals while activated (should be 12V)
3. Test valve with multimeter (resistance: 10-50Ω typical)
4. Check wire gauge adequate (18-22 AWG for 12V circuit)

### Valve Stays Open/Won't Close

1. Relay may be stuck (mechanical failure)
2. GPIO may be stuck HIGH/LOW (check configuration)
3. Valve may be mechanically stuck (debris, scale)
4. Check for short circuit in wiring

### Multiple Valves Not Working

1. Check 12V power supply capacity
   - Each valve draws ~0.5-1A
   - Use adequate power supply (2A per valve recommended)
2. Check common ground connections
3. Verify each relay module powered correctly

### Intermittent Operation

1. Loose wire connections (check all terminals)
2. Inadequate power supply (voltage drop under load)
3. EMI interference (separate signal and power wiring)
4. Relay contacts wearing out (replace relay)

---

## Safety Considerations

**Electrical Safety**:
- Always disconnect 12V power before working on wiring
- Use appropriate wire gauge for current
- Fuse the 12V circuit (5A fuse recommended)
- Weatherproof connections if in humid environment

**Beer Line Safety**:
- Valves must be food-grade stainless steel
- Regular cleaning and sanitization
- Check for leaks regularly
- Ensure proper pressure (10-12 PSI typical)

**Mechanical**:
- Secure valve bodies (vibration-resistant mounting)
- Use proper beer line fittings
- Don't over-tighten connections (can crack plastic)

---

## Advanced Configurations

### 3-Wire Valve Support

Some valves have 3 wires for position feedback:
1. Wire 1: 12V+ (COM → NO)
2. Wire 2: Ground (to 12V-)
3. Wire 3: Position signal (separate GPIO input)

In RaspberryPints:
- Enable **Use 3-Wire Valves**
- Configure both control pin and feedback pin

### Valve Control via MQTT

For wireless valve control:
1. Configure ESP32/ESP8266 with relay shield
2. Subscribe to RaspberryPints MQTT topic
3. Control valves remotely
4. Useful for distributed tap systems

### Timed Pour Feature

1. Enable **Pour Shut-Off Count** in Tap List Settings
2. System automatically closes valve after preset amount
3. Prevents overflow/waste
4. Useful for events or self-serve setups

---

## Wiring Best Practices

**Organization**:
- Use different wire colors:
  - Red: 12V positive
  - Black: 12V/common ground
  - Yellow/Green/Blue: GPIO signals (numbered)
- Label everything with wire markers
- Use terminal blocks for easy troubleshooting

**Routing**:
- Keep 12V power wires separated from signal wires
- Use shielded cable for long GPIO runs (>3 feet)
- Mount relay boards near valves to minimize 12V wiring
- Use cable management (zip ties, wire looms)

**Future-Proofing**:
- Install extra relay channels for expansion
- Run extra wires to tap locations
- Document GPIO assignments in admin notes
- Take photos of wiring for future reference

---

## Parts Shopping List (4-Tap Example)

| Item | Quantity | Example Part |
|------|----------|--------------|
| 12V Solenoid Valves | 4 | Standard keg valve, 1/4" barb |
| 4-Channel Relay Module | 1 | SainSmart 4-channel 5V relay |
| 12V Power Supply | 1 | 5A (60W) 12VDC adapter |
| 1N4007 Diodes | 4 | Flyback protection (if needed) |
| 18 AWG Wire | 20 ft | For 12V circuit |
| 22 AWG Wire | 20 ft | For GPIO signals |
| Terminal Blocks | 2 | 12-position screw terminals |
| Heat Shrink Tubing | 1 pack | Various sizes |
| Wire Labels | 1 pack | For marking connections |

**Estimated Cost**: $60-100 for 4-tap system

---

**Resources**:
- [Relay Module Tutorial](https://www.electronicshub.org/control-a-relay-using-raspberry-pi/)
- [Solenoid Valve Basics](https://www.fluidpowerworld.com/understanding-solenoid-valves/)
- [GPIO Pinout Reference](https://pinout.xyz/)

---

# MQTT Integration with RaspberryPints

## Overview

MQTT (Message Queuing Telemetry Transport) is a lightweight publish/subscribe messaging protocol perfect for IoT devices. RaspberryPints can use MQTT to communicate with wireless flow meters, sensors, and other hardware without direct wiring to the Raspberry Pi.

**Use Cases**:
- Wireless flow meters (Photon, ESP8266, ESP32)
- Remote motion sensors
- Distributed temperature probes
- Cloud-connected devices
- Multi-Pi installations sharing data

---

## MQTT Architecture in RaspberryPints

```
┌─────────────────────┐
│  Raspberry Pi       │
│  ┌───────────────┐  │
│  │ Mosquitto     │  │◄──── MQTT Broker (Server)
│  │ MQTT Broker   │  │
│  └───────┬───────┘  │
│          │          │
│  ┌───────▼───────┐  │
│  │ RaspberryPints│  │◄──── Subscribes to topics
│  │ Python/PHP    │  │      Publishes commands
│  └───────────────┘  │
└─────────────────────┘
          ▲
          │ MQTT Messages
          │ (WiFi/Network)
          │
    ┌─────┴─────┬─────────┬─────────┐
    │           │         │         │
┌───▼────┐  ┌──▼───┐  ┌──▼───┐  ┌──▼───┐
│Photon  │  │ESP32 │  │ESP8266│ │Other │
│Flow    │  │Temp  │  │Motion│  │MQTT  │
│Meter   │  │Sensor│  │Sensor│  │Device│
└────────┘  └──────┘  └──────┘  └──────┘
```

---

## Part 1: Setting Up MQTT Broker on Raspberry Pi

### Installing Mosquitto MQTT Broker

The installer can set this up automatically, or you can install manually:

**Automatic Installation** (During RPints Setup):
1. When asked "Do you want to use MQTT?" → Select **Yes**
2. When asked "Will this pi host the MQTT Server?" → Select **Yes**
3. Enter MQTT Port (default: **1883**)
4. Enter MQTT Username (default: **RaspberryPints**)
5. Enter MQTT Password (create a secure password)
6. Installer configures Mosquitto automatically

**Manual Installation**:
```bash
# Install Mosquitto broker and clients
sudo apt-get update
sudo apt-get install mosquitto mosquitto-clients -y

# Install Python MQTT library
pip install paho-mqtt
# For Bookworm/Python3:
sudo apt-get install python3-paho-mqtt -y
```

### Configuring Mosquitto

The configuration file is located at: `/etc/mosquitto/conf.d/rpints.conf`

**View Current Configuration**:
```bash
cat /etc/mosquitto/conf.d/rpints.conf
```

**Example Configuration**:
```
allow_anonymous false
password_file /etc/mosquitto/pwfile
listener 1883
```

**Managing Users and Passwords**:
```bash
# Add a new user
sudo mosquitto_passwd -b /etc/mosquitto/pwfile username password

# Add first user (creates file)
sudo mosquitto_passwd -c /etc/mosquitto/pwfile RaspberryPints YourPassword

# Change password
sudo mosquitto_passwd -b /etc/mosquitto/pwfile RaspberryPints NewPassword

# Restart Mosquitto after changes
sudo systemctl restart mosquitto
```

**Checking Broker Status**:
```bash
# Check if Mosquitto is running
sudo systemctl status mosquitto

# View Mosquitto logs
sudo tail -f /var/log/mosquitto/mosquitto.log

# Test broker locally
mosquitto_sub -h localhost -p 1883 -u RaspberryPints -P YourPassword -t '#' -v
```

---

## Part 2: Configuring RaspberryPints for MQTT

### Python Configuration

Edit `/var/www/html/python/Config.py`:

```python
# MQTT Connection Settings
config['flowmon.port'] = 'MQTT'  # Tell flowmon to use MQTT instead of serial
config['mqtt.host'] = 'localhost'  # MQTT broker address
config['mqtt.port'] = '1883'       # MQTT broker port
config['mqtt.user'] = 'RaspberryPints'  # MQTT username
config['mqtt.password'] = 'YourPassword'  # MQTT password
```

**After editing**, restart the flowmon service:
```bash
sudo /etc/init.d/flowmon restart
```

### Database Configuration

Flow meter pins are configured in the database through **Admin → Tap List → Settings**.

For MQTT-based flow meters, the "Flow Pin" becomes the **MQTT Topic** identifier:
- Instead of GPIO pin number (e.g., 2, 3, 4)
- Use MQTT topic identifiers (e.g., "tap1", "tap2", "tap3")

---

## Part 3: MQTT Topics Used by RaspberryPints

### Current Topic Structure

**RaspberryPints currently uses a simple topic structure:**

**Subscribe Topic** (RPints listens for messages):
```
rpints/pours
```
- All flow meter devices publish their pour/pulse data to this single topic
- RaspberryPints FlowMonitor subscribes to this topic

**Publish Topic** (RPints sends messages):
```
rpints
```
- RaspberryPints publishes commands and status to this topic
- Flow meters and other devices can subscribe to receive commands

**Implementation Details** (`python/FlowMonitor.py`):
- Line 922: Default subscription topic is `"rpints/pours"`
- Line 990: Publishing uses topic `"rpints"`
- Line 985-987: Messages are processed by `flowMonitor.processMsg()`

### Message Format

Messages should be in the format that the Arduino/Photon firmware sends:

**Pour/Pulse Message** (Device → RPints):
```
Format: Standard Arduino serial protocol message
The message format should match what the Arduino code sends via serial
```

**Example Message Processing**:
The `processMsg()` function in FlowMonitor.py parses incoming messages to extract:
- Tap/pin identification
- Pulse counts
- Flow meter readings
- Status updates

**Note**: The actual message parsing depends on the Arduino firmware format being used. Common formats include:
- Simple pulse counts: `"tap1:450"`
- JSON format: `{"tap":"tap1","pulses":450}`
- Arduino protocol format (varies by firmware version)

### Customizing Topics

If you need different topics for your setup, you can modify:

**In `python/FlowMonitor.py` line 922**:
```python
class MQTTListenerThread (threading.Thread):
    def __init__(self, threadID, flowMonitor, host, port, user, password, 
                 live_interval=45, topics="rpints/pours"):  # Change this
```

**Example Custom Topics**:
```python
topics="mybrewery/flow/#"  # Subscribe to all flow topics
topics="rpints/tap/+"      # Subscribe to rpints/tap/1, rpints/tap/2, etc.
```

MQTT wildcards:
- `+` = single level wildcard (e.g., `rpints/+/status`)
- `#` = multi-level wildcard (e.g., `rpints/#` for all rpints topics)

---

## Part 4: Building MQTT-Based Flow Meters

### Example: Photon-Based Flow Meter

**Hardware Needed**:
- Particle Photon (WiFi-enabled microcontroller)
- YF-S201 Flow Sensor
- 10K Ω resistor
- Power supply (5V)

**Photon Code Example**:
```cpp
#include <MQTT.h>

// MQTT Settings
MQTT client("raspberrypi.local", 1883, callback);
const char* mqtt_user = "RaspberryPints";
const char* mqtt_pass = "YourPassword";

// Flow Sensor Settings
const int flowPin = D2;
volatile int pulseCount = 0;
String tapID = "tap1";

void setup() {
    pinMode(flowPin, INPUT_PULLUP);
    attachInterrupt(flowPin, pulseCounter, FALLING);
    
    // Connect to MQTT
    client.connect("photon-tap1", mqtt_user, mqtt_pass);
    
    // Subscribe to commands from RPints
    client.subscribe("rpints");
}

void loop() {
    if (client.isConnected()) {
        client.loop();
        
        // Send pulse count every second to rpints/pours topic
        static unsigned long lastTime = 0;
        if (millis() - lastTime > 1000) {
            // Format message to match Arduino serial protocol
            // Adjust format based on your Arduino firmware
            String payload = String::format("tap%d:%d", 1, pulseCount);
            // Or use JSON if your setup expects it:
            // String payload = String::format("{\"tap\":\"%s\",\"pulses\":%d}", 
            //                                tapID.c_str(), pulseCount);
            client.publish("rpints/pours", payload);
            pulseCount = 0;
            lastTime = millis();
        }
    } else {
        client.connect("photon-tap1", mqtt_user, mqtt_pass);
        delay(5000);
    }
}

void pulseCounter() {
    pulseCount++;
}

void callback(char* topic, byte* payload, unsigned int length) {
    // Handle commands from RPints
    // Commands arrive on "rpints" topic
    String message;
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    Serial.println("Received: " + message);
}
```

### Example: ESP8266-Based Flow Meter

**Hardware Needed**:
- ESP8266 (NodeMCU or Wemos D1 Mini)
- YF-S201 Flow Sensor
- 10K Ω resistor

**ESP8266 Arduino Code**:
```cpp
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi Settings
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

// MQTT Settings
const char* mqtt_server = "raspberrypi.local";
const int mqtt_port = 1883;
const char* mqtt_user = "RaspberryPints";
const char* mqtt_pass = "YourPassword";

// Flow Sensor
const int flowPin = D2;
const int tapNumber = 1;  // Change for each tap
volatile int pulseCount = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
    Serial.begin(115200);
    pinMode(flowPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(flowPin), pulseCounter, FALLING);
    
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    
    // Send pulse data every second to rpints/pours topic
    static unsigned long lastTime = 0;
    if (millis() - lastTime > 1000) {
        char payload[100];
        // Format to match Arduino serial protocol
        // Adjust format based on your Arduino firmware version
        snprintf(payload, sizeof(payload), "tap%d:%d", tapNumber, pulseCount);
        
        // Alternative JSON format (if your setup uses JSON):
        // snprintf(payload, sizeof(payload), 
        //          "{\"tap\":\"tap%d\",\"pulses\":%d}", 
        //          tapNumber, pulseCount);
        
        client.publish("rpints/pours", payload);
        Serial.print("Sent: ");
        Serial.println(payload);
        pulseCount = 0;
        lastTime = millis();
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

void reconnect() {
    while (!client.connected()) {
        Serial.print("Connecting to MQTT...");
        String clientId = "ESP8266-tap" + String(tapNumber);
        if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
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

void ICACHE_RAM_ATTR pulseCounter() {
    pulseCount++;
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
```

---

## Part 5: Testing and Debugging MQTT

### Testing with Command Line Tools

**Subscribe to all topics** (monitor all MQTT traffic):
```bash
mosquitto_sub -h localhost -p 1883 -u RaspberryPints -P YourPassword -t '#' -v
```

**Subscribe to flow/pour data**:
```bash
mosquitto_sub -h localhost -p 1883 -u RaspberryPints -P YourPassword -t 'rpints/pours' -v
```

**Manually publish test pulse data** (format matches Arduino protocol):
```bash
# Simple format
mosquitto_pub -h localhost -p 1883 -u RaspberryPints -P YourPassword \
  -t 'rpints/pours' \
  -m 'tap1:100'

# Or JSON format (if your setup uses JSON)
mosquitto_pub -h localhost -p 1883 -u RaspberryPints -P YourPassword \
  -t 'rpints/pours' \
  -m '{"tap":"tap1","pulses":100}'
```

**Test sending commands to devices**:
```bash
mosquitto_pub -h localhost -p 1883 -u RaspberryPints -P YourPassword \
  -t 'rpints' \
  -m 'valve1:open'
```

**Monitor what RPints is publishing**:
```bash
mosquitto_sub -h localhost -p 1883 -u RaspberryPints -P YourPassword -t 'rpints' -v
```

### Debugging Checklist

1. **Check Mosquitto is running**:
   ```bash
   sudo systemctl status mosquitto
   ```

2. **Verify RaspberryPints MQTT config** (`/var/www/html/python/Config.py`):
   - Correct host, port, username, password
   - `flowmon.port` set to `'MQTT'`

3. **Check flowmon is running**:
   ```bash
   sudo /etc/init.d/flowmon status
   ```

4. **Enable MQTT debugging** in Config.py:
   ```python
   config['flowmon.debug'] = True
   ```
   Then restart flowmon and check logs.

5. **Monitor MQTT traffic**:
   ```bash
   mosquitto_sub -h localhost -p 1883 -u RaspberryPints -P YourPassword -t '#' -v
   ```

6. **Check firewall** (if using remote broker):
   ```bash
   sudo ufw allow 1883/tcp
   ```

---

## Part 6: Advanced MQTT Configurations

### Using External MQTT Broker

If you want to use a cloud MQTT broker or separate server:

**In RaspberryPints Config.py**:
```python
config['mqtt.host'] = 'broker.hivemq.com'  # External broker
config['mqtt.port'] = '1883'
config['mqtt.user'] = 'your_username'
config['mqtt.password'] = 'your_password'
```

**Popular Public MQTT Brokers**:
- `broker.hivemq.com` (port 1883) - Free public broker
- `test.mosquitto.org` (port 1883) - Mosquitto test broker
- `mqtt.eclipseprojects.io` (port 1883) - Eclipse public broker

⚠️ **Security Warning**: Public brokers are not secure. Use for testing only!

### Secure MQTT with TLS/SSL

For production deployments, use encrypted MQTT:

**Generate Certificates**:
```bash
# Install certbot
sudo apt-get install certbot -y

# Generate certificates
sudo certbot certonly --standalone -d yourdomain.com

# Configure Mosquitto for TLS
sudo nano /etc/mosquitto/conf.d/rpints.conf
```

**TLS Configuration**:
```
listener 8883
cafile /etc/letsencrypt/live/yourdomain.com/chain.pem
certfile /etc/letsencrypt/live/yourdomain.com/cert.pem
keyfile /etc/letsencrypt/live/yourdomain.com/privkey.pem
```

### MQTT Quality of Service (QoS)

MQTT supports three QoS levels:
- **QoS 0**: At most once (fire and forget)
- **QoS 1**: At least once (acknowledged delivery)
- **QoS 2**: Exactly once (guaranteed delivery)

For flow meters, **QoS 1** is recommended to ensure pulse counts aren't lost.

### Retained Messages

Enable retained messages for device status:
```cpp
client.publish("rpints/flow/tap1/status", "online", true); // true = retained
```

This ensures new subscribers immediately see the last published status.

---

## Part 7: Troubleshooting Common Issues

### Issue: Device Can't Connect to Broker

**Solutions**:
1. Check broker is running: `sudo systemctl status mosquitto`
2. Verify network connectivity: `ping raspberrypi.local`
3. Check firewall: `sudo ufw status`
4. Test with mosquitto_sub: `mosquitto_sub -h localhost -p 1883 -t '#'`
5. Check credentials are correct
6. Look at Mosquitto logs: `sudo tail -f /var/log/mosquitto/mosquitto.log`

### Issue: Messages Not Reaching RaspberryPints

**Solutions**:
1. Check flowmon is running: `sudo /etc/init.d/flowmon status`
2. Verify Config.py has correct MQTT settings
3. Enable debug logging: `config['flowmon.debug'] = True`
4. Check RPints logs: Admin → RPints Log
5. Monitor MQTT traffic to confirm messages are being sent

### Issue: High Latency or Dropped Messages

**Solutions**:
1. Check WiFi signal strength on devices
2. Reduce QoS if latency is critical
3. Optimize message frequency (don't publish more than necessary)
4. Check for network congestion
5. Consider local broker instead of cloud broker

---

## Resources

- **Mosquitto Documentation**: [mosquitto.org](https://mosquitto.org/)
- **MQTT Protocol Specification**: [mqtt.org](https://mqtt.org/)
- **Paho MQTT Python**: [eclipse.org/paho/clients/python](https://www.eclipse.org/paho/clients/python/)
- **PubSubClient Arduino Library**: [github.com/knolleary/pubsubclient](https://github.com/knolleary/pubsubclient)
- **HiveMQ MQTT Essentials**: [hivemq.com/mqtt-essentials](https://www.hivemq.com/mqtt-essentials/)

---

**Enjoy your RaspberryPints installation! Cheers! 🍺**
	
	v2019.12.01
		- RandR+ version
		- 
