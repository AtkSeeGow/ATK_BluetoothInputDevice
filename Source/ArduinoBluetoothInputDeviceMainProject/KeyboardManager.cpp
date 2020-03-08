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

  this->liquidCrystalI2C = liquidCrystalI2C;

  this->keyboardButtons[0] = KeyboardButton(bounceTime, KEY_ESC, KeyboardType);
  this->keyboardButtons[1] = KeyboardButton(bounceTime, KEY_TAB, KeyboardType);
  this->keyboardButtons[2] = KeyboardButton(bounceTime, KEY_CAPS_LOCK, KeyboardType);
  this->keyboardButtons[3] = KeyboardButton(bounceTime, KEY_DELETE, KeyboardType);
  this->keyboardButtons[4] = KeyboardButton(bounceTime, KEY_BACKSPACE, KeyboardType);
  this->keyboardButtons[5] = KeyboardButton(bounceTime, KEY_RETURN, KeyboardType);
  this->keyboardButtons[6] = KeyboardButton(bounceTime, KEY_END, KeyboardType);
  this->keyboardButtons[7] = KeyboardButton(bounceTime, KEY_HOME, KeyboardType);
  this->keyboardButtons[8] = KeyboardButton();
  this->keyboardButtons[9] = KeyboardButton(bounceTime, KEY_LEFT_SHIFT, KeyboardType);
  this->keyboardButtons[10] = KeyboardButton(bounceTime, KEY_LEFT_CTRL, KeyboardType);
  this->keyboardButtons[11] = KeyboardButton(bounceTime, KEY_LEFT_GUI, KeyboardType);
  this->keyboardButtons[12] = KeyboardButton(bounceTime, KEY_LEFT_ALT, KeyboardType);
  this->keyboardButtons[13] = KeyboardButton();
  this->keyboardButtons[14] = KeyboardButton();
  this->keyboardButtons[15] = KeyboardButton(bounceTime, 1, FunctionType);
  this->keyboardButtons[16] = KeyboardButton();
  this->keyboardButtons[17] = KeyboardButton();
  this->keyboardButtons[18] = KeyboardButton(bounceTime, KEY_RIGHT_CTRL, KeyboardType);
  this->keyboardButtons[19] = KeyboardButton();
  this->keyboardButtons[20] = KeyboardButton(bounceTime, MOUSE_LEFT, MouseType);
  this->keyboardButtons[21] = KeyboardButton(bounceTime, MOUSE_RIGHT, MouseType);
  this->keyboardButtons[22] = KeyboardButton(bounceTime, MOUSE_MIDDLE, MouseType);
  this->keyboardButtons[23] = KeyboardButton();
  this->keyboardButtons[24] = KeyboardButton();
  this->keyboardButtons[25] = KeyboardButton();
  this->keyboardButtons[26] = KeyboardButton(bounceTime, '/', KeyboardType);
  this->keyboardButtons[27] = KeyboardButton(bounceTime, '\\', KeyboardType);
  this->keyboardButtons[28] = KeyboardButton(bounceTime, '.', KeyboardType);
  this->keyboardButtons[29] = KeyboardButton(bounceTime, ',', KeyboardType);
  this->keyboardButtons[30] = KeyboardButton(bounceTime, ';', KeyboardType);
  this->keyboardButtons[31] = KeyboardButton(bounceTime, '`', KeyboardType);
  this->keyboardButtons[32] = KeyboardButton(bounceTime, '-', KeyboardType);
  this->keyboardButtons[33] = KeyboardButton(bounceTime, '=', KeyboardType);
  this->keyboardButtons[34] = KeyboardButton(bounceTime, '[', KeyboardType);
  this->keyboardButtons[35] = KeyboardButton(bounceTime, ']', KeyboardType);
  this->keyboardButtons[36] = KeyboardButton(bounceTime, '\'', KeyboardType);
  this->keyboardButtons[37] = KeyboardButton(bounceTime, ' ', KeyboardType);
  this->keyboardButtons[38] = KeyboardButton(bounceTime, '`', KeyboardType);
  this->keyboardButtons[39] = KeyboardButton(bounceTime, '\'', KeyboardType);
  this->keyboardButtons[40] = KeyboardButton();
  this->keyboardButtons[41] = KeyboardButton();
  this->keyboardButtons[42] = KeyboardButton();
  this->keyboardButtons[43] = KeyboardButton();
  this->keyboardButtons[44] = KeyboardButton();
  this->keyboardButtons[45] = KeyboardButton();
  this->keyboardButtons[46] = KeyboardButton();
  this->keyboardButtons[47] = KeyboardButton();
  this->keyboardButtons[48] = KeyboardButton(bounceTime, KEY_UP_ARROW, KeyboardType);
  this->keyboardButtons[49] = KeyboardButton(bounceTime, KEY_DOWN_ARROW, KeyboardType);
  this->keyboardButtons[50] = KeyboardButton(bounceTime, KEY_LEFT_ARROW, KeyboardType);
  this->keyboardButtons[51] = KeyboardButton(bounceTime, KEY_RIGHT_ARROW, KeyboardType);
  this->keyboardButtons[52] = KeyboardButton(bounceTime, '1', KeyboardType);
  this->keyboardButtons[53] = KeyboardButton(bounceTime, '2', KeyboardType);
  this->keyboardButtons[54] = KeyboardButton(bounceTime, '3', KeyboardType);
  this->keyboardButtons[55] = KeyboardButton(bounceTime, '4', KeyboardType);
  this->keyboardButtons[56] = KeyboardButton(bounceTime, '5', KeyboardType);
  this->keyboardButtons[57] = KeyboardButton(bounceTime, '6', KeyboardType);
  this->keyboardButtons[58] = KeyboardButton(bounceTime, '7', KeyboardType);
  this->keyboardButtons[59] = KeyboardButton(bounceTime, '8', KeyboardType);
  this->keyboardButtons[60] = KeyboardButton(bounceTime, '9', KeyboardType);
  this->keyboardButtons[61] = KeyboardButton(bounceTime, '0', KeyboardType);
  this->keyboardButtons[62] = KeyboardButton(bounceTime, KEY_F1, KeyboardType);
  this->keyboardButtons[63] = KeyboardButton(bounceTime, KEY_F2, KeyboardType);
  this->keyboardButtons[64] = KeyboardButton(bounceTime, KEY_F3, KeyboardType);
  this->keyboardButtons[65] = KeyboardButton(bounceTime, KEY_F4, KeyboardType);
  this->keyboardButtons[66] = KeyboardButton(bounceTime, KEY_F5, KeyboardType);
  this->keyboardButtons[67] = KeyboardButton(bounceTime, KEY_F6, KeyboardType);
  this->keyboardButtons[68] = KeyboardButton(bounceTime, KEY_F7, KeyboardType);
  this->keyboardButtons[69] = KeyboardButton(bounceTime, KEY_F8, KeyboardType);
  this->keyboardButtons[70] = KeyboardButton(bounceTime, KEY_F9, KeyboardType);
  this->keyboardButtons[71] = KeyboardButton(bounceTime, KEY_F10, KeyboardType);
  this->keyboardButtons[72] = KeyboardButton(bounceTime, KEY_F11, KeyboardType);
  this->keyboardButtons[73] = KeyboardButton(bounceTime, KEY_F12, KeyboardType);
  this->keyboardButtons[74] = KeyboardButton(bounceTime, 'a', KeyboardType);
  this->keyboardButtons[75] = KeyboardButton(bounceTime, 'b', KeyboardType);
  this->keyboardButtons[76] = KeyboardButton(bounceTime, 'c', KeyboardType);
  this->keyboardButtons[77] = KeyboardButton(bounceTime, 'd', KeyboardType);
  this->keyboardButtons[78] = KeyboardButton(bounceTime, 'e', KeyboardType);
  this->keyboardButtons[79] = KeyboardButton(bounceTime, 'f', KeyboardType);
  this->keyboardButtons[80] = KeyboardButton(bounceTime, 'g', KeyboardType);
  this->keyboardButtons[81] = KeyboardButton(bounceTime, 'h', KeyboardType);
  this->keyboardButtons[82] = KeyboardButton(bounceTime, 'i', KeyboardType);
  this->keyboardButtons[83] = KeyboardButton(bounceTime, 'j', KeyboardType);
  this->keyboardButtons[84] = KeyboardButton(bounceTime, 'k', KeyboardType);
  this->keyboardButtons[85] = KeyboardButton(bounceTime, 'l', KeyboardType);
  this->keyboardButtons[86] = KeyboardButton(bounceTime, 'm', KeyboardType);
  this->keyboardButtons[87] = KeyboardButton(bounceTime, 'n', KeyboardType);
  this->keyboardButtons[88] = KeyboardButton(bounceTime, 'o', KeyboardType);
  this->keyboardButtons[89] = KeyboardButton(bounceTime, 'p', KeyboardType);
  this->keyboardButtons[90] = KeyboardButton(bounceTime, 'q', KeyboardType);
  this->keyboardButtons[91] = KeyboardButton(bounceTime, 'r', KeyboardType);
  this->keyboardButtons[92] = KeyboardButton(bounceTime, 's', KeyboardType);
  this->keyboardButtons[93] = KeyboardButton(bounceTime, 't', KeyboardType);
  this->keyboardButtons[94] = KeyboardButton(bounceTime, 'u', KeyboardType);
  this->keyboardButtons[95] = KeyboardButton(bounceTime, 'v', KeyboardType);
  this->keyboardButtons[96] = KeyboardButton(bounceTime, 'w', KeyboardType);
  this->keyboardButtons[97] = KeyboardButton(bounceTime, 'x', KeyboardType);
  this->keyboardButtons[98] = KeyboardButton(bounceTime, 'y', KeyboardType);
  this->keyboardButtons[99] = KeyboardButton(bounceTime, 'z', KeyboardType);
  this->keyboardButtons[100] = KeyboardButton();
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
  for (int8_t i = 0; i < 101; i++)
  {
    KeyboardButton keyboardButton = this->keyboardButtons[i];
    keyboardButton.OperationPress();
    keyboardButton.OperationRelease();
  }
}

KeyboardButton *KeyboardManager::GetMapping(int8_t rowPin, int8_t columnPin)
{
  if (this->keyboardButtons[15].CurrentState == LOW) {
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
  if (this->keyboardButtons[15].CurrentState == LOW) {
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
    return &this->keyboardButtons[31]; //
  else if (rowPin == 21 && columnPin == 5)
    return &this->keyboardButtons[1]; // TAB
  else if (rowPin == 21 && columnPin == 6)
    return &this->keyboardButtons[2]; // CAPS_LOCK
  else if (rowPin == 21 && columnPin == 7)
    return &this->keyboardButtons[9]; // SHIFT
  else if (rowPin == 21 && columnPin == 8)
    return &this->keyboardButtons[11]; // GUI

  // 2
  if (rowPin == 20 && columnPin == 4)
    return &this->keyboardButtons[52]; // 1
  else if (rowPin == 20 && columnPin == 5)
    return &this->keyboardButtons[90]; // Q
  else if (rowPin == 20 && columnPin == 6)
    return &this->keyboardButtons[74]; // A
  else if (rowPin == 20 && columnPin == 7)
    return &this->keyboardButtons[99]; // Z
  else if (rowPin == 20 && columnPin == 8)
    return &this->keyboardButtons[62]; // F1

  // 3
  if (rowPin == 19 && columnPin == 4)
    return &this->keyboardButtons[53]; // 2
  else if (rowPin == 19 && columnPin == 5)
    return &this->keyboardButtons[96]; // W
  else if (rowPin == 19 && columnPin == 6)
    return &this->keyboardButtons[92]; // S
  else if (rowPin == 19 && columnPin == 7)
    return &this->keyboardButtons[97]; // X
  else if (rowPin == 19 && columnPin == 8)
    return &this->keyboardButtons[63]; // F2

  // 4
  if (rowPin == 18 && columnPin == 4)
    return &this->keyboardButtons[54]; // 3
  else if (rowPin == 18 && columnPin == 5)
    return &this->keyboardButtons[78]; // E
  else if (rowPin == 18 && columnPin == 6)
    return &this->keyboardButtons[77]; // D
  else if (rowPin == 18 && columnPin == 7)
    return &this->keyboardButtons[76]; // C
  else if (rowPin == 18 && columnPin == 8)
    return &this->keyboardButtons[64]; // F3

  // 5
  if (rowPin == 15 && columnPin == 4)
    return &this->keyboardButtons[55]; // 4
  else if (rowPin == 15 && columnPin == 5)
    return &this->keyboardButtons[91]; // R
  else if (rowPin == 15 && columnPin == 6)
    return &this->keyboardButtons[79]; // F
  else if (rowPin == 15 && columnPin == 7)
    return &this->keyboardButtons[95]; // V
  else if (rowPin == 15 && columnPin == 8)
    return &this->keyboardButtons[65]; // F4

  // 6
  if (rowPin == 14 && columnPin == 4)
    return &this->keyboardButtons[56]; // 5
  else if (rowPin == 14 && columnPin == 5)
    return &this->keyboardButtons[93]; // T
  else if (rowPin == 14 && columnPin == 6)
    return &this->keyboardButtons[80]; // G
  else if (rowPin == 14 && columnPin == 7)
    return &this->keyboardButtons[75]; // B

  // 7
  if (rowPin == 16 && columnPin == 4)
    return &this->keyboardButtons[0]; // ESC
  else if (rowPin == 16 && columnPin == 5)
    return &this->keyboardButtons[67]; // F6
  else if (rowPin == 16 && columnPin == 6)
    return &this->keyboardButtons[66]; // F5

  // 8
  if (rowPin == 14 && columnPin == 8)
    return &this->keyboardButtons[37]; // ' '
  else if (rowPin == 16 && columnPin == 8)
    return &this->keyboardButtons[10]; // CTRL
  else if (rowPin == 10 && columnPin == 6)
    return &this->keyboardButtons[15]; // FN1
  else if (rowPin == 10 && columnPin == 8)
    return &this->keyboardButtons[100];
  else if (rowPin == 10 && columnPin == 7)
    return &this->keyboardButtons[100];
  else if (rowPin == 16 && columnPin == 7)
    return &this->keyboardButtons[12]; // ALT

  return &this->keyboardButtons[100];
}

KeyboardButton *KeyboardManager::getExtendMapping(int8_t rowPin, int8_t columnPin)
{
  // 1
  if (rowPin == 21 && columnPin == 4)
    return &this->keyboardButtons[31]; //
  else if (rowPin == 21 && columnPin == 5)
    return &this->keyboardButtons[1]; // TAB
  else if (rowPin == 21 && columnPin == 6)
    return &this->keyboardButtons[2]; // CAPS_LOCK
  else if (rowPin == 21 && columnPin == 7)
    return &this->keyboardButtons[9]; // SHIFT
  else if (rowPin == 21 && columnPin == 8)
    return &this->keyboardButtons[11]; // GUI

  // 2
  if (rowPin == 20 && columnPin == 4)
    return &this->keyboardButtons[100];
  else if (rowPin == 20 && columnPin == 5)
    return &this->keyboardButtons[100];
  else if (rowPin == 20 && columnPin == 6)
    return &this->keyboardButtons[100];
  else if (rowPin == 20 && columnPin == 7)
    return &this->keyboardButtons[100];
  else if (rowPin == 20 && columnPin == 8)
    return &this->keyboardButtons[100];

  // 3
  if (rowPin == 19 && columnPin == 4)
    return &this->keyboardButtons[100];
  else if (rowPin == 19 && columnPin == 5)
    return &this->keyboardButtons[20];
  else if (rowPin == 19 && columnPin == 6)
    return &this->keyboardButtons[100];
  else if (rowPin == 19 && columnPin == 7)
    return &this->keyboardButtons[100];
  else if (rowPin == 19 && columnPin == 8)
    return &this->keyboardButtons[100];

  // 4
  if (rowPin == 18 && columnPin == 4)
    return &this->keyboardButtons[100];
  else if (rowPin == 18 && columnPin == 5)
    return &this->keyboardButtons[22];
  else if (rowPin == 18 && columnPin == 6)
    return &this->keyboardButtons[100];
  else if (rowPin == 18 && columnPin == 7)
    return &this->keyboardButtons[50];
  else if (rowPin == 18 && columnPin == 8)
    return &this->keyboardButtons[100];

  // 5
  if (rowPin == 15 && columnPin == 4)
    return &this->keyboardButtons[100];
  else if (rowPin == 15 && columnPin == 5)
    return &this->keyboardButtons[21];
  else if (rowPin == 15 && columnPin == 6)
    return &this->keyboardButtons[48];
  else if (rowPin == 15 && columnPin == 7)
    return &this->keyboardButtons[49];
  else if (rowPin == 15 && columnPin == 8)
    return &this->keyboardButtons[100];

  // 6
  if (rowPin == 14 && columnPin == 4)
    return &this->keyboardButtons[100];
  else if (rowPin == 14 && columnPin == 5)
    return &this->keyboardButtons[4]; // BACK
  else if (rowPin == 14 && columnPin == 6)
    return &this->keyboardButtons[5]; // RETURN
  else if (rowPin == 14 && columnPin == 7)
    return &this->keyboardButtons[51];

  // 7
  if (rowPin == 16 && columnPin == 4)
    return &this->keyboardButtons[100];
  else if (rowPin == 16 && columnPin == 5)
    return &this->keyboardButtons[100];
  else if (rowPin == 16 && columnPin == 6)
    return &this->keyboardButtons[100];

  // 8
  if (rowPin == 14 && columnPin == 8)
    return &this->keyboardButtons[37]; // ' '
  else if (rowPin == 16 && columnPin == 8)
    return &this->keyboardButtons[10]; // CTRL
  else if (rowPin == 10 && columnPin == 6)
    return &this->keyboardButtons[15]; // FN1
  else if (rowPin == 10 && columnPin == 8)
    return &this->keyboardButtons[100];
  else if (rowPin == 10 && columnPin == 7)
    return &this->keyboardButtons[100];
  else if (rowPin == 16 && columnPin == 7)
    return &this->keyboardButtons[12]; // ALT

  return &this->keyboardButtons[100];
}
