// KeyboardButton.h

#ifndef _KEYBOARDBUTTON_h
#define _KEYBOARDBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class KeyboardButton {
public:
	KeyboardButton();
	KeyboardButton(int bounceTime, uint8_t keyValue);

	uint8_t KeyValue;
  uint8_t BounceTime;
  
	void OperationPress();
	void OperationRelease();

	bool CurrentState;
  bool IsMoreBounceTime();

  unsigned long LastChangeStateTime;
private:
	
};

#endif

