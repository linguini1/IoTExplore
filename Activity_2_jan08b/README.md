:Author: Matteo Golin
:Email: matteo.golin@gmail.com
:Date: 08/01/2023
:Revision: 1
:License: MIT

# Project: Graphing Data in the Cloud

This project reads temperature and humidity data from the MKR1010 WiFi board in combination with the MKR IoT Carrier board. The data is transmitted to the Arduino Cloud where it is visualized on a dashboard.
The serial output of the program can also be parsed into a CSV file.

## Step 1: Installation

Requires access to the Arduino Web Editor and these code files.
Modify the `arduino_secrets.h` file to contain the SSID and SECRET_OPTIONAL_PASS for your wireless network.

## Step 2: Assemble the circuit

Connect the MKR1010 WiFi with the MKR IoT Carrier so that the pin labels align.

## Step 3: Load the code

Upload the sketch to the Arduino MKR1010 WiFi board and IoT Carrier via serial.

### License

This project is released under an MIT License.

### BOM

Add the bill of the materials you need for this project.

|===
| ID | Part name | Part number | Quantity
| M1 | MKR1010 WiFi | | 1  
| C1 | MKR IoT Carrier | | 1  
|===
