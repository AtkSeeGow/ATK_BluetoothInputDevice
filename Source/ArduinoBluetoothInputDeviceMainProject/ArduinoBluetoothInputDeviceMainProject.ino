#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "KeyboardButton.h"
#include "KeyboardManager.h"

LiquidCrystal_I2C liquidCrystalI2C = LiquidCrystal_I2C(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

KeyboardManager keyboardManager = KeyboardManager(&liquidCrystalI2C);

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

  liquidCrystalI2C.begin(16, 2);

  keyboardManager.DisplayMappingModeName();
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
