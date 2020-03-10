//
//
//

#include <Keyboard.h>
#include <Mouse.h>
#include "KeyboardButton.h"
#include "KeyboardManager.h"

KeyboardManager::KeyboardManager(LiquidCrystal_I2C *liquidCrystalI2C)
{
  int8_t bounceTime = 5;

  this->noneButton = KeyboardButton();

  this->liquidCrystalI2C = liquidCrystalI2C;

  this->keyboardButtons[0] = KeyboardButton(bounceTime, '`', KeyboardType);
  this->keyboardButtons[1] = KeyboardButton(bounceTime, KEY_TAB, KeyboardType);
  this->keyboardButtons[2] = KeyboardButton(bounceTime, KEY_CAPS_LOCK, KeyboardType);
  this->keyboardButtons[3] = KeyboardButton(bounceTime, KEY_LEFT_SHIFT, KeyboardType);
  this->keyboardButtons[4] = KeyboardButton(bounceTime, KEY_LEFT_GUI, KeyboardType);

  this->keyboardButtons[5] = KeyboardButton(bounceTime, '1', KeyboardType);
  this->keyboardButtons[6] = KeyboardButton(bounceTime, 'q', KeyboardType);
  this->keyboardButtons[7] = KeyboardButton(bounceTime, 'a', KeyboardType);
  this->keyboardButtons[8] = KeyboardButton(bounceTime, 'z', KeyboardType);
  this->keyboardButtons[9] = KeyboardButton(bounceTime, KEY_F1, KeyboardType);

  this->keyboardButtons[10] = KeyboardButton(bounceTime, '2', KeyboardType);
  this->keyboardButtons[11] = KeyboardButton(bounceTime, 'w', KeyboardType);
  this->keyboardButtons[12] = KeyboardButton(bounceTime, 's', KeyboardType);
  this->keyboardButtons[13] = KeyboardButton(bounceTime, 'x', KeyboardType);
  this->keyboardButtons[14] = KeyboardButton(bounceTime, KEY_F2, KeyboardType);

  this->keyboardButtons[15] = KeyboardButton(bounceTime, '3', KeyboardType);
  this->keyboardButtons[16] = KeyboardButton(bounceTime, 'e', KeyboardType);
  this->keyboardButtons[17] = KeyboardButton(bounceTime, 'd', KeyboardType);
  this->keyboardButtons[18] = KeyboardButton(bounceTime, 'c', KeyboardType);
  this->keyboardButtons[19] = KeyboardButton(bounceTime, KEY_F3, KeyboardType);

  this->keyboardButtons[20] = KeyboardButton(bounceTime, '4', KeyboardType);
  this->keyboardButtons[21] = KeyboardButton(bounceTime, 'r', KeyboardType);
  this->keyboardButtons[22] = KeyboardButton(bounceTime, 'f', KeyboardType);
  this->keyboardButtons[23] = KeyboardButton(bounceTime, 'v', KeyboardType);
  this->keyboardButtons[24] = KeyboardButton(bounceTime, KEY_F4, KeyboardType);

  this->keyboardButtons[25] = KeyboardButton(bounceTime, '5', KeyboardType);
  this->keyboardButtons[26] = KeyboardButton(bounceTime, 't', KeyboardType);
  this->keyboardButtons[27] = KeyboardButton(bounceTime, 'g', KeyboardType);
  this->keyboardButtons[28] = KeyboardButton(bounceTime, 'b', KeyboardType);

  this->keyboardButtons[29] = KeyboardButton(bounceTime, KEY_ESC, KeyboardType);
  this->keyboardButtons[30] = KeyboardButton(bounceTime, KEY_F6, KeyboardType);
  this->keyboardButtons[31] = KeyboardButton(bounceTime, KEY_F5, KeyboardType);

  this->keyboardButtons[32] = KeyboardButton(bounceTime, ' ', KeyboardType);
  this->keyboardButtons[33] = KeyboardButton(bounceTime, KEY_LEFT_CTRL, KeyboardType);
  this->keyboardButtons[34] = KeyboardButton(bounceTime, 1, FunctionType);
  this->keyboardButtons[35] = KeyboardButton(bounceTime, 2, FunctionType);
  this->keyboardButtons[36] = KeyboardButton(bounceTime, 3, FunctionType);
  this->keyboardButtons[37] = KeyboardButton(bounceTime, KEY_LEFT_ALT, KeyboardType);

  this->keyboardButtons[38] = KeyboardButton(bounceTime, KEY_F7, KeyboardType);
  this->keyboardButtons[39] = KeyboardButton(bounceTime, KEY_F8, KeyboardType);
  this->keyboardButtons[40] = KeyboardButton(bounceTime, KEY_F9, KeyboardType);
  this->keyboardButtons[41] = KeyboardButton(bounceTime, KEY_F10, KeyboardType);
  this->keyboardButtons[42] = KeyboardButton(bounceTime, KEY_F11, KeyboardType);
  this->keyboardButtons[43] = KeyboardButton(bounceTime, KEY_F12, KeyboardType);

  this->keyboardButtons[44] = KeyboardButton(bounceTime, KEY_UP_ARROW, KeyboardType);
  this->keyboardButtons[45] = KeyboardButton(bounceTime, KEY_DOWN_ARROW, KeyboardType);
  this->keyboardButtons[46] = KeyboardButton(bounceTime, KEY_LEFT_ARROW, KeyboardType);
  this->keyboardButtons[47] = KeyboardButton(bounceTime, KEY_RIGHT_ARROW, KeyboardType);

  this->keyboardButtons[48] = KeyboardButton(bounceTime, KEY_BACKSPACE, KeyboardType);
  this->keyboardButtons[49] = KeyboardButton(bounceTime, KEY_RETURN, KeyboardType);

  this->keyboardButtons[50] = KeyboardButton(bounceTime, MOUSE_LEFT, MouseType);
  this->keyboardButtons[51] = KeyboardButton(bounceTime, MOUSE_RIGHT, MouseType);
  this->keyboardButtons[52] = KeyboardButton(bounceTime, MOUSE_MIDDLE, MouseType);
}

void KeyboardManager::OperationState(int8_t rowPin, int8_t columnPin, bool currentState)
{
  unsigned long now = millis();

  KeyboardButton *keyboardButton = this->GetMapping(rowPin, columnPin);

  if (!keyboardButton->IsMoreBounceTime())
    return;

  if (keyboardButton->CurrentState != currentState)
  {
    keyboardButton->LastChangeStateTime = now;
    keyboardButton->CurrentState = currentState;
    this->DisplayMappingModeName();
  }
}

void KeyboardManager::Execution()
{
  for (int8_t i = 0; i < 53; i++)
  {
    KeyboardButton keyboardButton = this->keyboardButtons[i];
    keyboardButton.OperationPress();
    keyboardButton.OperationRelease();
  }
}

KeyboardButton *KeyboardManager::GetMapping(int8_t rowPin, int8_t columnPin)
{
  if (this->keyboardButtons[34].CurrentState == LOW) {
    KeyboardButton *keyboardButton = this->getExtendMapping(rowPin, columnPin);
    return keyboardButton;
  }
  else {
    KeyboardButton *keyboardButton = this->getBasicMapping(rowPin, columnPin);
    return keyboardButton;
  }
}

void KeyboardManager::DisplayMappingModeName() {
  this->liquidCrystalI2C->clear();
  if (this->keyboardButtons[34].CurrentState == LOW) {
    this->liquidCrystalI2C->setCursor(0, 0);
    this->liquidCrystalI2C->print("Mapping Mode :");
    this->liquidCrystalI2C->setCursor(0, 1);
    this->liquidCrystalI2C->print(" Extend Keyboard");
  }
  else {
    this->liquidCrystalI2C->setCursor(0, 0);
    this->liquidCrystalI2C->print("Mapping Mode :");
    this->liquidCrystalI2C->setCursor(0, 1);
    this->liquidCrystalI2C->print(" Basic Keyboard");
  }
}

KeyboardButton *KeyboardManager::getBasicMapping(int8_t rowPin, int8_t columnPin)
{
  // 1
  if (rowPin == 21 && columnPin == 4)
    return &this->keyboardButtons[0]; //
  else if (rowPin == 21 && columnPin == 5)
    return &this->keyboardButtons[1]; // TAB
  else if (rowPin == 21 && columnPin == 6)
    return &this->keyboardButtons[2]; // CAPS_LOCK
  else if (rowPin == 21 && columnPin == 7)
    return &this->keyboardButtons[3]; // SHIFT
  else if (rowPin == 21 && columnPin == 8)
    return &this->keyboardButtons[4]; // GUI

  // 2
  if (rowPin == 20 && columnPin == 4)
    return &this->keyboardButtons[5]; // 1
  else if (rowPin == 20 && columnPin == 5)
    return &this->keyboardButtons[6]; // Q
  else if (rowPin == 20 && columnPin == 6)
    return &this->keyboardButtons[7]; // A
  else if (rowPin == 20 && columnPin == 7)
    return &this->keyboardButtons[8]; // Z
  else if (rowPin == 20 && columnPin == 8)
    return &this->keyboardButtons[9]; // F1

  // 3
  if (rowPin == 19 && columnPin == 4)
    return &this->keyboardButtons[10]; // 2
  else if (rowPin == 19 && columnPin == 5)
    return &this->keyboardButtons[11]; // W
  else if (rowPin == 19 && columnPin == 6)
    return &this->keyboardButtons[12]; // S
  else if (rowPin == 19 && columnPin == 7)
    return &this->keyboardButtons[13]; // X
  else if (rowPin == 19 && columnPin == 8)
    return &this->keyboardButtons[14]; // F2

  // 4
  if (rowPin == 18 && columnPin == 4)
    return &this->keyboardButtons[15]; // 3
  else if (rowPin == 18 && columnPin == 5)
    return &this->keyboardButtons[16]; // E
  else if (rowPin == 18 && columnPin == 6)
    return &this->keyboardButtons[17]; // D
  else if (rowPin == 18 && columnPin == 7)
    return &this->keyboardButtons[18]; // C
  else if (rowPin == 18 && columnPin == 8)
    return &this->keyboardButtons[19]; // F3

  // 5
  if (rowPin == 15 && columnPin == 4)
    return &this->keyboardButtons[20]; // 4
  else if (rowPin == 15 && columnPin == 5)
    return &this->keyboardButtons[21]; // R
  else if (rowPin == 15 && columnPin == 6)
    return &this->keyboardButtons[22]; // F
  else if (rowPin == 15 && columnPin == 7)
    return &this->keyboardButtons[23]; // V
  else if (rowPin == 15 && columnPin == 8)
    return &this->keyboardButtons[24]; // F4

  // 6
  if (rowPin == 14 && columnPin == 4)
    return &this->keyboardButtons[25]; // 5
  else if (rowPin == 14 && columnPin == 5)
    return &this->keyboardButtons[26]; // T
  else if (rowPin == 14 && columnPin == 6)
    return &this->keyboardButtons[27]; // G
  else if (rowPin == 14 && columnPin == 7)
    return &this->keyboardButtons[28]; // B

  // 7
  if (rowPin == 16 && columnPin == 4)
    return &this->keyboardButtons[29]; // ESC
  else if (rowPin == 16 && columnPin == 5)
    return &this->keyboardButtons[30]; // F6
  else if (rowPin == 16 && columnPin == 6)
    return &this->keyboardButtons[31]; // F5

  // 8
  if (rowPin == 14 && columnPin == 8)
    return &this->keyboardButtons[32]; // ' '
  else if (rowPin == 16 && columnPin == 8)
    return &this->keyboardButtons[33]; // CTRL
  else if (rowPin == 10 && columnPin == 6)
    return &this->keyboardButtons[34]; // FN1
  else if (rowPin == 10 && columnPin == 8)
    return &this->keyboardButtons[35];
  else if (rowPin == 10 && columnPin == 7)
    return &this->keyboardButtons[36];
  else if (rowPin == 16 && columnPin == 7)
    return &this->keyboardButtons[37]; // ALT

  return &this->noneButton;
}

KeyboardButton *KeyboardManager::getExtendMapping(int8_t rowPin, int8_t columnPin)
{
  // 1
  if (rowPin == 21 && columnPin == 4)
    return &this->keyboardButtons[0]; //
  else if (rowPin == 21 && columnPin == 5)
    return &this->keyboardButtons[1]; // TAB
  else if (rowPin == 21 && columnPin == 6)
    return &this->keyboardButtons[2]; // CAPS_LOCK
  else if (rowPin == 21 && columnPin == 7)
    return &this->keyboardButtons[3]; // SHIFT
  else if (rowPin == 21 && columnPin == 8)
    return &this->keyboardButtons[4]; // GUI

  // 2
  if (rowPin == 20 && columnPin == 4)
    return &this->noneButton;
  else if (rowPin == 20 && columnPin == 5)
    return&this->noneButton;
  else if (rowPin == 20 && columnPin == 6)
    return &this->noneButton;
  else if (rowPin == 20 && columnPin == 7)
    return &this->noneButton;
  else if (rowPin == 20 && columnPin == 8)
    return &this->keyboardButtons[43]; // F12

  // 3
  if (rowPin == 19 && columnPin == 4)
    return &this->noneButton;
  else if (rowPin == 19 && columnPin == 5)
    return &this->keyboardButtons[50];
  else if (rowPin == 19 && columnPin == 6)
    return &this->noneButton;
  else if (rowPin == 19 && columnPin == 7)
    return &this->noneButton;
  else if (rowPin == 19 && columnPin == 8)
    return &this->keyboardButtons[42]; // F11

  // 4
  if (rowPin == 18 && columnPin == 4)
    return &this->noneButton;
  else if (rowPin == 18 && columnPin == 5)
    return &this->keyboardButtons[52];
  else if (rowPin == 18 && columnPin == 6)
    return &this->noneButton;
  else if (rowPin == 18 && columnPin == 7)
    return &this->keyboardButtons[46];
  else if (rowPin == 18 && columnPin == 8)
    return &this->keyboardButtons[41]; // F10

  // 5
  if (rowPin == 15 && columnPin == 4)
    return &this->noneButton;
  else if (rowPin == 15 && columnPin == 5)
    return &this->keyboardButtons[51];
  else if (rowPin == 15 && columnPin == 6)
    return &this->keyboardButtons[44];
  else if (rowPin == 15 && columnPin == 7)
    return &this->keyboardButtons[45];
  else if (rowPin == 15 && columnPin == 8)
    return &this->keyboardButtons[40]; // F9

  // 6
  if (rowPin == 14 && columnPin == 4)
    return &this->noneButton;
  else if (rowPin == 14 && columnPin == 5)
    return &this->keyboardButtons[48]; // BACK
  else if (rowPin == 14 && columnPin == 6)
    return &this->keyboardButtons[49]; // RETURN
  else if (rowPin == 14 && columnPin == 7)
    return &this->keyboardButtons[47];

  // 7
  if (rowPin == 16 && columnPin == 4)
    return &this->noneButton;
  else if (rowPin == 16 && columnPin == 5)
    return &this->keyboardButtons[38]; // F7
  else if (rowPin == 16 && columnPin == 6)
    return &this->keyboardButtons[39]; // F8

  // 8
  if (rowPin == 14 && columnPin == 8)
    return &this->keyboardButtons[32]; // ' '
  else if (rowPin == 16 && columnPin == 8)
    return &this->keyboardButtons[33]; // CTRL
  else if (rowPin == 10 && columnPin == 6)
    return &this->keyboardButtons[34]; // FN1
  else if (rowPin == 10 && columnPin == 8)
    return &this->keyboardButtons[35];
  else if (rowPin == 10 && columnPin == 7)
    return &this->keyboardButtons[36];
  else if (rowPin == 16 && columnPin == 7)
    return &this->keyboardButtons[37]; // ALT

  return &this->noneButton;
}
