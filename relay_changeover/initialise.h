#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int sensepin = 4;
int relaypin = 13;
int ledpin = 5;
void pinInitialise()
{
  pinMode(sensepin, INPUT_PULLUP);
  pinMode(relaypin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  digitalWrite(relaypin, LOW);
  digitalWrite(ledpin, LOW);
}
void displayinitialise()
{

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
  }
}
void showDisplay(String text,short int left=0,short int right=0,int textsize=1)
{
  display.clearDisplay();
  display.setTextSize(textsize);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(left, right);            // Start at top-left corner
  display.println(text);
  display.display();
}
float readCutoff()
{
  int value=analogRead(relayPin);
  cutoff=value/1023*45;
  return cutoff;
}
