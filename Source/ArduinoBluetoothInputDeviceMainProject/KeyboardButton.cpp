//
//
//

#include <Keyboard.h>
#include "KeyboardButton.h"

KeyboardButton::KeyboardButton()
{
  this->KeyValue = 0;
}

KeyboardButton::KeyboardButton(int bounceTime, uint8_t keyValue)
{
  this->KeyValue = keyValue;

  this->BounceTime = bounceTime;

  this->CurrentState = HIGH;
  this->LastChangeStateTime = 0;
}

void KeyboardButton::OperationPress()
{
  if (this->CurrentState == LOW)
    Keyboard.press(this->KeyValue);
}

void KeyboardButton::OperationRelease()
{
  if (this->CurrentState == HIGH)
    Keyboard.release(this->KeyValue);
}

bool KeyboardButton::IsMoreBounceTime()
{
  unsigned long now = millis();
  return now - this->LastChangeStateTime > this->BounceTime;
}
