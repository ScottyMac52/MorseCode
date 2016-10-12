// MorseCodePatternGenerator.h

#ifndef _MORSECODEPATTERNGENERATOR_h
#define _MORSECODEPATTERNGENERATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class MorseCodePatternGenerator {
public:
	MorseCodePatternGenerator();
	MorseCodePatternGenerator(char *pattern);
	int Dot();
	int Dash();
	char* Write();
	char* Read();

private:
//	HashMap<char, char*> MorseCodeMap;
//	HashMap<char*, char> ReverseMorseCodeMap;


};

#endif



