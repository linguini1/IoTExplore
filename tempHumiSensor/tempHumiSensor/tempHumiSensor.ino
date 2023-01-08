#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

float temperature = 0;
float humidity = 0;

void setup() {

  while(!Serial);
  Serial.begin(9600);  // Baud rate of 9600 | standard

  // Enclosure not mounted to case
  carrier.noCase();

  // Initialize IoTSK carrier and output errors to serial monitor
  carrier.begin();
}

// Display functions
void displayTemperature() {

  // Configure
  carrier.display.fillScreen(ST77XX_RED);      // Red bg
  carrier.display.setTextColor(ST77XX_WHITE);  // White text
  carrier.display.setTextSize(6);

  // Display
  carrier.display.setCursor(30, 50);
  carrier.display.print("Temp: ");
  carrier.display.setTextSize(4);
  carrier.display.setCursor(40, 120);
  carrier.display.print(temperature);
  carrier.display.print(" C");
}

int humidity_safety(double humidity) {
  if (humidity > 80.0) {
    return ST77XX_RED;
  } else if (60.0 <= humidity && humidity <= 80.0) {
    return ST77XX_YELLOW;
  }

  return ST77XX_GREEN;
}

void displayHumidity() {

  // Configure
  carrier.display.fillScreen(humidity_safety(humidity));  // Bg depends on safety of humidity
  carrier.display.setTextColor(ST77XX_WHITE);             // White text
  carrier.display.setTextSize(6);

  // Display
  carrier.display.setCursor(30, 50);
  carrier.display.print("Humi: ");
  carrier.display.setTextSize(4);
  carrier.display.setCursor(40, 120);
  carrier.display.print(humidity);
  carrier.display.print(" %");
}

void loop() {

  // Read sensor values
  temperature = carrier.Env.readTemperature();
  humidity = carrier.Env.readHumidity();

  // Update touch buttons
  carrier.Buttons.update();

  // Display values to serial monitor and screen
  Serial.println(temperature);

  if (carrier.Buttons.onTouchDown(TOUCH0)) {
    displayTemperature();
  }

  if (carrier.Buttons.onTouchDown(TOUCH1)) {
    displayHumidity();
  }
}