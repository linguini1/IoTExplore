#include <Arduino_MKRIoTCarrier.h>

MKRIoTCarrier carrier;

// Variables
float temperature = 0;
float humidity = 0;
float pressure = 0;
int light = 0;
int r, g, b = 0;
float Gx, Gy, Gz;
float Ax, Ay, Az;
int counter = 0;

// File
File dataFile;

void setup() {

  // Serial
  Serial.begin(9600);

  // Carrier setup
  carrier.noCase();
  carrier.begin();

  // SD card initialization
  if (!SD.begin(SD_CS)) {
    carrier.display.setTextSize(2);
    carrier.display.setCursor(35, 70);
    carrier.display.print("SD card failed");
    carrier.display.setCursor(45, 110);
    carrier.display.print("to initialise.");
    Serial.println("Failed to initialize SD card!");
    while (1);
  }

  // Create logging file
  dataFile = SD.open("log-0000.csv", FILE_WRITE);
  delay(1000);
  dataFile.println("temperature,humidity,pressure,light,ax,ay,az,gx,gy,gz");
  dataFile.close();
  delay(100);

}

void loop() {
  
  // Open the file
  dataFile = SD.open("log-000.csv", FILE_WRITE);
  delay(1000);

  // Read values from sensors
  temperature = carrier.Env.readTemperature();
  humidity = carrier.Env.readHumidity();
  pressure = carrier.Pressure.readPressure();

  while(!carrier.Light.colorAvailable()){
    delay(5);
  }
  carrier.Light.readColor(r, g, b, light);

  carrier.IMUmodule.readAcceleration(Ax, Ay, Az);
  carrier.IMUmodule.readGyroscope(Gx, Gy, Gz);

  // Write the sensor values
  Serial.print(temperature);
  Serial.print(",");
 
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(pressure);
  Serial.print(",");
  Serial.print(light);
  Serial.print(",");
 
  Serial.print(Ax);
  Serial.print(",");
  Serial.print(Ay);
  Serial.print(",");
  Serial.print(Az);
  Serial.print(",");
 
  Serial.print(Gx);
  Serial.print(",");
  Serial.print(Gy);
  Serial.print(",");
  Serial.print(Gz);
  Serial.println(",");
  dataFile.close();

  // Display measurement status
  counter += 1;
 
  carrier.display.fillScreen(ST77XX_BLACK); // Red background
  carrier.display.setTextColor(ST77XX_WHITE); // White text
  carrier.display.setTextSize(4); // Medium sized text
 
  carrier.display.setCursor(100, 70);
  carrier.display.print(counter);
  carrier.display.setCursor(35, 125);
  carrier.display.setTextSize(2);
  carrier.display.print("Measures taken");
  delay(1000);
}
