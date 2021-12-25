#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

// An IRsend instance is used to send data
IRsend sender;

void setup()
{
	Serial.begin(115200);

#if defined(IR_SEND_PIN)
    IrSender.begin(); // Start with IR_SEND_PIN as send pin and enable feedback LED at default feedback LED pin
#else
    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin
#endif

    Serial.print(F("Ready to send IR signals at pin "));
#if defined(ARDUINO_ARCH_STM32) || defined(ESP8266)
    Serial.println(IR_SEND_PIN_STRING);
#else
    Serial.print(IR_SEND_PIN);
#endif
}


void loop()
{

  /* Do other stuff */

  // The following values were obtained by reading the receiver in a different sketch
  // They correspond to the OFF button of another NEC compatible remote control
  uint32_t Address = 0x80;
  uint8_t Command = 0xA;

//  IrSender.sendNEC(Address, Command, 1);
//  IrSender.sendSony(Address, Command, 1);
//  IrSender.sendPanasonic(Address, Command, 1);
//
//  IrSender.sendJVC(Address, Command, 1);
//
//  IrSender.sendSamsung(Address, Command, 1);
  IrSender.sendLG(Address, Command, 1);



  delay(2000);
  Serial.println("Send Data Again");



  // To send messages using a different protocol
  // see: https://github.com/z3t0/Arduino-IRremote/wiki/IRremote-library-API

}
