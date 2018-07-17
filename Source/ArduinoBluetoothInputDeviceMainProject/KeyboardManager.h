// KeyboardManager.h

#ifndef _KEYBOARDMANAGER_h
#define _KEYBOARDMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "KeyboardButton.h"

class KeyboardManager {
public:
	KeyboardManager();

  void OperationState(int8_t rowPin, int8_t columnPin, bool currentState);
	void Execution();

	KeyboardButton *GetMapping(int8_t rowPin, int8_t columnPin);
private:
	int type;

	KeyboardButton *getLeftMapping(int8_t rowPin, int8_t columnPin);
	KeyboardButton *getRightMapping(int8_t rowPin, int8_t columnPin);
	KeyboardButton *getNumberMapping(int8_t rowPin, int8_t columnPin);

	KeyboardButton keyboardButtons[101];
};

#endif
