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
**Enjoy your RaspberryPints installation! Cheers! 🍺**




__Known Bugs:__

	All versions:
	- Firefox has difficulty rendering our SRM image masks correctly.
		Due to a deficiency in the way Firefox handles z-values with images and is a known
		issue within the MDN. Not sure if this is an issue any more...


__Version History:__

	v2025.10.1:
		- Updated readme. 
	
	v2019.12.01
		- RandR+ version
		- 
