#include <AsyncDelay.h>
#include <SoftWire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306_SoftWire.h>

#define WIDTH 128
#define HEIGHT 32

#define OLED_RESET 4

#define sdaPin A2
#define sclPin A3

SoftWire i2c(sdaPin, sclPin);
Adafruit_SSD1306 oled(WIDTH, HEIGHT, &i2c, OLED_RESET);

void setup() {
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.setTextSize(1);
  oled.print("Hello, time elapsed:");
  oled.setCursor(10,10);
  oled.setTextSize(2);
  oled.print(millis()/1000);
  oled.print(" s.");
  oled.display();
}
