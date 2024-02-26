#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 64 // OLED display width, in pixels
#define SCREEN_HEIGHT 48 // OLED display height, in pixels
 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
void setup() {
  Serial.begin(115200);
 
  delay(2000);
  Serial.println(F("Starting!"));
 
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  Serial.println(F("Initialized!"));
 
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds
 
  // Clear the buffer
  display.clearDisplay();
  // Refresh (apply command)
  display.display();
 
  // Set color of the text
  display.setTextColor(SSD1306_WHITE);
  // Set position of cursor
  display.setCursor(10, 20);
  // Set text size multiplier (x1 standard size)
  display.setTextSize(1);
  // print text like Serial
  display.print(F("Hello!"));
 
  display.setCursor(10, 50);
  // Set color of the text and color of the background
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.setTextSize(1);
  display.print(F("Test 123"));
 
  // Refresh (apply command)
  display.display();
}
 
void loop() {
}