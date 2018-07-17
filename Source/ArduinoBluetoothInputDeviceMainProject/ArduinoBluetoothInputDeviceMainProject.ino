#include "KeyboardButton.h"
#include "KeyboardManager.h"

KeyboardManager keyboardManager = KeyboardManager();

int8_t rowPins[] = { 8, 9, 10, 14, 16 };
int8_t columnPins[] = { 5, 6, 7, 15, A0 };

void setup()
{
  Serial.begin(9600);

  for (int8_t pin : rowPins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  for (int8_t pin : columnPins) {
    pinMode(pin, INPUT_PULLUP);
  }
}

void loop()
{
  for (int8_t rowPin : rowPins)
  {
    digitalWrite(rowPin, LOW);

    for (int8_t columnPin : columnPins)
    {
      bool currentState = digitalRead(columnPin);
      keyboardManager.OperationState(rowPin, columnPin, currentState);
    }

    digitalWrite(rowPin, HIGH);
  }
  
  keyboardManager.Execution();
}
