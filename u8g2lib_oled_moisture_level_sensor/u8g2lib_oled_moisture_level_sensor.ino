#include <Wire.h>
#include <U8g2lib.h>

int sensorPin = A0;

// Initialize the OLED display (change to match your display model)
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  u8g2.begin();  // Start display
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read moisture sensor (A0)
  float moistureLevel = (100 - ((sensorValue / 4095.00) * 100));// Convert to percentage
  // map(value we tryna use, convert 4095-0 to 0-100)

  u8g2.clearBuffer();  // Clear screen

  u8g2.setFont(u8g2_font_ncenB08_tr);  // Set font
  u8g2.setCursor(10, 20);  // Set position
  u8g2.print("Moisture: ");  
  u8g2.print(moistureLevel);
  u8g2.print("%");

  Serial.println(sensorValue);

  u8g2.sendBuffer();  // Display content
  delay(1000);  // Update every second
}
