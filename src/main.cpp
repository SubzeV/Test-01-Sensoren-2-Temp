#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

#include  <Wire.h>

#include <Adafruit_BMP280.h>

#include <DHTesp.h>
DHTesp dht;

//initialize the liquid crystal library
//the first parameter is  the I2C address
//the second parameter is how many rows are on your screen
//the  third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27,  16, 2);

#define BMP280_ADDRESS 0x76 // I2C address of BMP280 sensor
#define LED_PIN D5          // Pin for the LED
#define THRESHOLD_TEMP 20.0 // Temperature threshold in Celsius

Adafruit_BMP280 bmp; // Create BMP280 object

void setup() {
  Wire.begin(); // Initialize I2C communication
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT); // Set LED pin as output

  dht.setup(D5, DHTesp::DHT11);

  // Initialize BMP280 sensor
  if (!bmp.begin(BMP280_ADDRESS)) {
    Serial.println("Could not find BMP280 sensor, check wiring!");
    while (1);
  }

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Booting...");

  lcd.setCursor(0,0);
  delay(250);
  lcd.clear();
}

void loop() {
  float temperature1 = bmp.readTemperature(); // Read temperature from BMP280
  float temperature2 = dht.getTemperature(); // Read temperature from DHT11
  Serial.print("Temperature1: ");
  Serial.print(temperature1);
  Serial.println(" °C");
  Serial.print("Temperature2: ");
  Serial.print(temperature2);
  Serial.println(" °C");

  lcd.setCursor(0,0);

  lcd.print("Temp1  |  Temp2");

  lcd.setCursor(0,1);

  lcd.print(String(temperature1) + "C |  " + String(temperature2) + "C");

  delay(100); // Delay for stability
}