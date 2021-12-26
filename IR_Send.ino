#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

// An IRsend instance is used to send data
IRsend sender;
char ChoiceProtocol = -1;
uint32_t Address;
uint8_t Command;
char myData[20];
uint8_t Stop = 255;
uint8_t CNT;

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
    Serial.println(IR_SEND_PIN);
#endif
    Serial.println(F("Enter 0 To finish sending"));
}


void loop()
{

	ChoiceProtocol = -1;
	Address = 0;
	Command = 0;
	Stop = 255;
	CNT = 0;

	Serial.println(F("--------------------------------------------"));
	Serial.println(F("1 - NEC"));
	Serial.println(F("2 - Sony"));
	Serial.println(F("3 - Panasonic"));
	Serial.println(F("4 - JVC"));
	Serial.println(F("5 - Samsung"));
	Serial.println(F("6 - LG"));
	Serial.println(F("Select the desired protocol (from 1 to 6):"));
	  while (ChoiceProtocol == -1) {
		  ChoiceProtocol = Serial.read();
	  }
	  Serial.println(F("Enter Address :"));
	  while (Address == 0) {
		  byte m = Serial.readBytesUntil('\n', myData, 20);
		  myData[m] = '\0';
		  Address = strtol(myData, NULL, 16);
	  }
	  Serial.println(F("Enter Command :"));
	  while (Command == 0) {
		  byte m = Serial.readBytesUntil('\n', myData, 20);
		  myData[m] = '\0';
		  Command = strtol(myData, NULL, 16);
	  }
	  Serial.println(F("------- IR Codes Info -------"));
		Serial.print(F("Address : 0x"));
		Serial.println(Address, HEX);
		Serial.print(F("Command : 0x"));
		Serial.println(Command, HEX);

switch (ChoiceProtocol) {
	case '1':
		Serial.println(F("Protocol : NEC"));
		Serial.println(F("--------------------------------"));
		while(Stop == 255){
		  IrSender.sendNEC(Address, Command, 1);
		  Serial.print(F("Sending IR Codes---> "));
		  Serial.println(CNT);
		  CNT++;
		  delay(5000);
		  Stop = Serial.read();
		}
		break;
	case '2':
		Serial.println(F("Protocol : Sony"));
		Serial.println(F("--------------------------------"));
		while(Stop == 255){
		  IrSender.sendSony(Address, Command, 1);
		  Serial.print(F("Sending IR Codes---> "));
		  Serial.println(CNT);
		  CNT++;
		  delay(5000);
		  Stop = Serial.read();
		}
		break;
	case '3':
		Serial.println(F("Protocol : Panasonic"));
		Serial.println(F("--------------------------------"));
		while(Stop == 255){
		  IrSender.sendPanasonic(Address, Command, 1);
		  Serial.print(F("Sending IR Codes---> "));
		  Serial.println(CNT);
		  CNT++;
		  delay(5000);
		  Stop = Serial.read();
		}
		break;
	case '4':
		Serial.println(F("Protocol : JVC"));
		Serial.println(F("--------------------------------"));
		while(Stop == 255){
		  IrSender.sendJVC(Address, Command, 1);
		  Serial.print(F("Sending IR Codes---> "));
		  Serial.println(CNT);
		  CNT++;
		  delay(5000);
		  Stop = Serial.read();
		}
		break;
	case '5':
		Serial.println(F("Protocol : Samsung"));
		Serial.println(F("--------------------------------"));
		while(Stop == 255){
		  IrSender.sendSamsung(Address, Command, 1);
		  Serial.print(F("Sending IR Codes---> "));
		  Serial.println(CNT);
		  CNT++;
		  delay(5000);
		  Stop = Serial.read();
		}
		break;
	case '6':
		Serial.println(F("Protocol : LG"));
		Serial.println(F("--------------------------------"));
		while(Stop == 255){
		  IrSender.sendLG(Address, Command, 1);
		  Serial.print(F("Sending IR Codes---> "));
		  Serial.println(CNT);
		  CNT++;
		  delay(5000);
		  Stop = Serial.read();
		}
		break;
	default:
		Serial.println(F("Please enter the correct protocol number : (from 1 to 6)"));
		break;
}


}
