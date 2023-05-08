// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL6XbChrpZr"
#define BLYNK_DEVICE_NAME "Test" // BLYNK_TEMPLATE_NAME เปลี่ยนเป็น BLYNK_DEVICE_NAME

#define BLYNK_FIRMWARE_VERSION        "0.1.0" // Up Code จะปรับเป็น Version ที่สูงกว่าเท่านั้น

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

BLYNK_WRITE(V0)
{
  int value = param.asInt(); 
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D4, LOW); 
    Serial.println("ON");
  }
  if(value == 0)
  {
     digitalWrite(D4,HIGH); //Relay 1 OFF
     Serial.println("OFF");
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(D4, OUTPUT);
  delay(100);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
