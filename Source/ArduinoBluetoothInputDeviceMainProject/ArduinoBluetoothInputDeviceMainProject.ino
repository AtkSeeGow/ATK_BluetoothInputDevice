#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "KeyboardButton.h"
#include "KeyboardManager.h"

LiquidCrystal_I2C liquidCrystalI2C = LiquidCrystal_I2C(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

KeyboardManager keyboardManager = KeyboardManager(&liquidCrystalI2C);

int8_t rowPins[] = { A3, A2, A1, A0, 15, 14, 16, 10 };
int8_t columnPins[] = { 4, 5, 6, 7, 8, 9 };

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
