/*
 Name:		MorseCode.ino
 Created:	10/11/2016 10:40:48 PM
 Author:	smcintosh
*/
#include "MorseCodeDefs.h"
#include "MorseCodePatternGenerator.h"

// Defines for the pins and the delays
#define LedPin1 9
#define LedPin2 11
#define dotDelay 150
#define dashDelay 300
#define charDelay 500
#define wordDelay 700

// Character array of the english characters supported
char characterArray[37] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', '1', '2',
'3', '4', '5', '6', '7', '8', '9', '0', ' ' };

// Array of strings for the Morse Code
char* morseCodeArray[37] = { ".-","-...","-.-.","-..",".-","..-.","--.","....","..",".---","-.-",".-..","--",
"-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--",
"....-",".....","-....","--...","---..","----.","-----", "/" };

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LedPin1, OUTPUT);
	pinMode(LedPin2, OUTPUT);
	Serial.begin(9600);
}

// Decodes a string into Morse and flashes the specified pin 
void DecodeAndSoundMorse(int pinNumber, String message) {
	message.toLowerCase();

	for (int messageIndex = 0; messageIndex < message.length(); messageIndex++) {
		char targetChar = message[messageIndex];
		if (targetChar >= 97 && targetChar <= 122) {
			// zero the array with 97 and get the difference
			int index = targetChar - 97;
			char *morseCode = morseCodeArray[index];
			if (morseCode != nullptr) {
				char codeString[25];
				codeString[0] = targetChar;
				strcpy(&codeString[1], morseCode);
				Serial.write(codeString);
				for (int counter = 0; counter < strlen(morseCode); counter++) {
					switch (morseCode[counter]) {
					case '.':
						Dot(pinNumber);
						delay(charDelay);
						break;
					case '-':
						Dash(pinNumber);
						delay(charDelay);
						break;
					case '/':
						delay(wordDelay);
						break;
					}
				}
			}
			
		}
	}
}

// Dot function
void Dot(int pinNumber) {
	digitalWrite(pinNumber, HIGH);
	delay(dotDelay);
	digitalWrite(pinNumber, LOW);
}

// Dash function
void Dash(int pinNumber) {
	digitalWrite(pinNumber, HIGH);
	delay(dashDelay);
	digitalWrite(pinNumber, LOW);
}

// the loop function runs over and over again until power down or reset
void loop() {
	DecodeAndSoundMorse(LedPin1, "Savers is the place to work in 2016 because there is a lot of work to do");
	delay(wordDelay);
	DecodeAndSoundMorse(LedPin2, "Halloween is the best time of year for Savers");
	delay(wordDelay);
}
