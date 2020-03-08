//
//
//

#include <Mouse.h>
#include <Keyboard.h>
#include "KeyboardButton.h"

KeyboardButton::KeyboardButton()
{
  this->KeyValue = 0;
  this->KeyType = None;
}

KeyboardButton::KeyboardButton(int bounceTime, uint8_t keyValue, uint8_t keyType)
{
  this->KeyValue = keyValue;
  this->KeyType = keyType;
  this->BounceTime = bounceTime;

  this->CurrentState = HIGH;
  this->LastChangeStateTime = 0;
}

void KeyboardButton::OperationPress()
{
  if (this->CurrentState == LOW)
  {
    if (this->KeyType == KeyboardType)
      Keyboard.press(this->KeyValue);
    else if (this->KeyType == MouseType)
      Mouse.press(this->KeyValue);
  }
}

void KeyboardButton::OperationRelease()
{
  if (this->CurrentState == HIGH)
  {
    if (this->KeyType == KeyboardType)
      Keyboard.release(this->KeyValue);
    else if (this->KeyType == MouseType)
      Mouse.release(this->KeyValue);
  }
}

bool KeyboardButton::IsMoreBounceTime()
{
  unsigned long now = millis();
  return now - this->LastChangeStateTime > this->BounceTime;
}
