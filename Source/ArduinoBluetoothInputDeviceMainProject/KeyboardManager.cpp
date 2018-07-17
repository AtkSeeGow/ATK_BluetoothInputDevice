//
//
//

#include <Keyboard.h>
#include "KeyboardButton.h"
#include "KeyboardManager.h"

KeyboardManager::KeyboardManager()
{
  int8_t bounceTime = 100;

  this->type = 0;

  this->keyboardButtons[0] = KeyboardButton(bounceTime, KEY_ESC);
  this->keyboardButtons[1] = KeyboardButton(bounceTime, KEY_TAB);
  this->keyboardButtons[2] = KeyboardButton(bounceTime, KEY_CAPS_LOCK);
  this->keyboardButtons[3] = KeyboardButton(bounceTime, KEY_DELETE);
  this->keyboardButtons[4] = KeyboardButton(bounceTime, KEY_BACKSPACE);
  this->keyboardButtons[5] = KeyboardButton(bounceTime, KEY_RETURN);
  this->keyboardButtons[6] = KeyboardButton();
  this->keyboardButtons[7] = KeyboardButton();
  this->keyboardButtons[8] = KeyboardButton();
  this->keyboardButtons[9] = KeyboardButton(bounceTime, KEY_LEFT_SHIFT);
  this->keyboardButtons[10] = KeyboardButton(bounceTime, KEY_LEFT_CTRL);
  this->keyboardButtons[11] = KeyboardButton(bounceTime, KEY_LEFT_GUI);
  this->keyboardButtons[12] = KeyboardButton(bounceTime, KEY_LEFT_ALT);
  this->keyboardButtons[13] = KeyboardButton();
  this->keyboardButtons[14] = KeyboardButton();
  this->keyboardButtons[15] = KeyboardButton();
  this->keyboardButtons[16] = KeyboardButton();
  this->keyboardButtons[17] = KeyboardButton();
  this->keyboardButtons[18] = KeyboardButton(bounceTime * 10, KEY_RIGHT_CTRL);
  this->keyboardButtons[19] = KeyboardButton();
  
  this->keyboardButtons[20] = KeyboardButton();
  this->keyboardButtons[21] = KeyboardButton();
  this->keyboardButtons[22] = KeyboardButton();
  this->keyboardButtons[23] = KeyboardButton();
  this->keyboardButtons[24] = KeyboardButton();
  this->keyboardButtons[25] = KeyboardButton();
  this->keyboardButtons[26] = KeyboardButton(bounceTime, '/');
  this->keyboardButtons[27] = KeyboardButton(bounceTime, '\\');
  this->keyboardButtons[28] = KeyboardButton(bounceTime, '.');
  this->keyboardButtons[29] = KeyboardButton(bounceTime, ',');
  this->keyboardButtons[30] = KeyboardButton(bounceTime, ';');
  this->keyboardButtons[31] = KeyboardButton(bounceTime, '`');
  this->keyboardButtons[32] = KeyboardButton(bounceTime, '-');
  this->keyboardButtons[33] = KeyboardButton(bounceTime, '=');
  this->keyboardButtons[34] = KeyboardButton(bounceTime, '[');
  this->keyboardButtons[35] = KeyboardButton(bounceTime, ']');
  this->keyboardButtons[36] = KeyboardButton(bounceTime, '\'');
  this->keyboardButtons[37] = KeyboardButton(bounceTime, ' ');
  this->keyboardButtons[38] = KeyboardButton();
  this->keyboardButtons[39] = KeyboardButton();
  this->keyboardButtons[40] = KeyboardButton();
  this->keyboardButtons[41] = KeyboardButton();
  this->keyboardButtons[42] = KeyboardButton();
  this->keyboardButtons[43] = KeyboardButton();
  this->keyboardButtons[44] = KeyboardButton();
  this->keyboardButtons[45] = KeyboardButton();
  this->keyboardButtons[46] = KeyboardButton();
  this->keyboardButtons[47] = KeyboardButton();
  this->keyboardButtons[48] = KeyboardButton(bounceTime, KEY_UP_ARROW);
  this->keyboardButtons[49] = KeyboardButton(bounceTime, KEY_DOWN_ARROW);
  this->keyboardButtons[50] = KeyboardButton(bounceTime, KEY_LEFT_ARROW);
  this->keyboardButtons[51] = KeyboardButton(bounceTime, KEY_RIGHT_ARROW);
  this->keyboardButtons[52] = KeyboardButton(bounceTime, '1');
  this->keyboardButtons[53] = KeyboardButton(bounceTime, '2');
  this->keyboardButtons[54] = KeyboardButton(bounceTime, '3');
  this->keyboardButtons[55] = KeyboardButton(bounceTime, '4');
  this->keyboardButtons[56] = KeyboardButton(bounceTime, '5');
  this->keyboardButtons[57] = KeyboardButton(bounceTime, '6');
  this->keyboardButtons[58] = KeyboardButton(bounceTime, '7');
  this->keyboardButtons[59] = KeyboardButton(bounceTime, '8');
  this->keyboardButtons[60] = KeyboardButton(bounceTime, '9');
  this->keyboardButtons[61] = KeyboardButton(bounceTime, '0');
  this->keyboardButtons[62] = KeyboardButton(bounceTime, KEY_F1);
  this->keyboardButtons[63] = KeyboardButton(bounceTime, KEY_F2);
  this->keyboardButtons[64] = KeyboardButton(bounceTime, KEY_F3);
  this->keyboardButtons[65] = KeyboardButton(bounceTime, KEY_F4);
  this->keyboardButtons[66] = KeyboardButton(bounceTime, KEY_F5);
  this->keyboardButtons[67] = KeyboardButton(bounceTime, KEY_F6);
  this->keyboardButtons[68] = KeyboardButton(bounceTime, KEY_F7);
  this->keyboardButtons[69] = KeyboardButton(bounceTime, KEY_F8);
  this->keyboardButtons[70] = KeyboardButton(bounceTime, KEY_F9);
  this->keyboardButtons[71] = KeyboardButton(bounceTime, KEY_F10);
  this->keyboardButtons[72] = KeyboardButton(bounceTime, KEY_F11);
  this->keyboardButtons[73] = KeyboardButton(bounceTime, KEY_F12);
  this->keyboardButtons[74] = KeyboardButton(bounceTime, 'a');
  this->keyboardButtons[75] = KeyboardButton(bounceTime, 'b');
  this->keyboardButtons[76] = KeyboardButton(bounceTime, 'c');
  this->keyboardButtons[77] = KeyboardButton(bounceTime, 'd');
  this->keyboardButtons[78] = KeyboardButton(bounceTime, 'e');
  this->keyboardButtons[79] = KeyboardButton(bounceTime, 'f');
  this->keyboardButtons[80] = KeyboardButton(bounceTime, 'g');
  this->keyboardButtons[81] = KeyboardButton(bounceTime, 'h');
  this->keyboardButtons[82] = KeyboardButton(bounceTime, 'i');
  this->keyboardButtons[83] = KeyboardButton(bounceTime, 'j');
  this->keyboardButtons[84] = KeyboardButton(bounceTime, 'k');
  this->keyboardButtons[85] = KeyboardButton(bounceTime, 'l');
  this->keyboardButtons[86] = KeyboardButton(bounceTime, 'm');
  this->keyboardButtons[87] = KeyboardButton(bounceTime, 'n');
  this->keyboardButtons[88] = KeyboardButton(bounceTime, 'o');
  this->keyboardButtons[89] = KeyboardButton(bounceTime, 'p');
  this->keyboardButtons[90] = KeyboardButton(bounceTime, 'q');
  this->keyboardButtons[91] = KeyboardButton(bounceTime, 'r');
  this->keyboardButtons[92] = KeyboardButton(bounceTime, 's');
  this->keyboardButtons[93] = KeyboardButton(bounceTime, 't');
  this->keyboardButtons[94] = KeyboardButton(bounceTime, 'u');
  this->keyboardButtons[95] = KeyboardButton(bounceTime, 'v');
  this->keyboardButtons[96] = KeyboardButton(bounceTime, 'w');
  this->keyboardButtons[97] = KeyboardButton(bounceTime, 'x');
  this->keyboardButtons[98] = KeyboardButton(bounceTime, 'y');
  this->keyboardButtons[99] = KeyboardButton(bounceTime, 'z');
  this->keyboardButtons[100] = KeyboardButton();
}

void KeyboardManager::OperationState(int8_t rowPin, int8_t columnPin, bool currentState)
{
  unsigned long now = millis();

  KeyboardButton *keyboardButton = this->GetMapping(rowPin, columnPin);

  if (keyboardButton->KeyValue == KEY_RIGHT_CTRL)
  {
    if (currentState == LOW && keyboardButton->IsMoreBounceTime())
    {
      this->type = this->type + 1;

      if (this->type > 2)
        this->type = 0;

      keyboardButton->LastChangeStateTime = now;
    }

    return;
  }

  if (currentState != keyboardButton->CurrentState)
  {
    if (keyboardButton->IsMoreBounceTime())
    {
      keyboardButton->LastChangeStateTime = now;
      keyboardButton->CurrentState = currentState;
    }
  }
}

void KeyboardManager::Execution()
{
  for (int8_t i = 0; i < 101; i++)
  {
    KeyboardButton keyboardButton = this->keyboardButtons[i];

    if (keyboardButton.KeyValue == 0)
      continue;

    if (keyboardButton.KeyValue == KEY_RIGHT_CTRL)
      continue;

    keyboardButton.OperationPress();
    keyboardButton.OperationRelease();
  }
}

KeyboardButton *KeyboardManager::GetMapping(int8_t rowPin, int8_t columnPin)
{
  if (this->type == 0)
    return this->getLeftMapping(rowPin, columnPin);
  else if (this->type == 1)
    return this->getRightMapping(rowPin, columnPin);
  else if (this->type == 2)
    return this->getNumberMapping(rowPin, columnPin);

  return this->getLeftMapping(rowPin, columnPin);
}

KeyboardButton * KeyboardManager::getLeftMapping(int8_t rowPin, int8_t columnPin)
{
  // 1
  if (rowPin == 16 && columnPin == 15)
    return &this->keyboardButtons[12];
  else if (rowPin == 9 && columnPin == 15)
    return &this->keyboardButtons[3];
  else if (rowPin == 10 && columnPin == 15)
    return &this->keyboardButtons[18];

  // 2
  else if (rowPin == 10 && columnPin == 18)
    return &this->keyboardButtons[90];
  else if (rowPin == 9 && columnPin == 18)
    return &this->keyboardButtons[74];
  else if (rowPin == 14 && columnPin == 15)
    return &this->keyboardButtons[99];

  // 3
  else if (rowPin == 14 && columnPin == 7)
    return &this->keyboardButtons[96];
  else if (rowPin == 16 && columnPin == 7)
    return &this->keyboardButtons[92];
  else if (rowPin == 16 && columnPin == 18)
    return &this->keyboardButtons[97];
  else if (rowPin == 8 && columnPin == 15)
    return &this->keyboardButtons[4];

  // 4
  else if (rowPin == 10 && columnPin == 6)
    return &this->keyboardButtons[78];
  else if (rowPin == 8 && columnPin == 7)
    return &this->keyboardButtons[77];
  else if (rowPin == 8 && columnPin == 18)
    return &this->keyboardButtons[76];
  else if (rowPin == 14 && columnPin == 18)
    return &this->keyboardButtons[5];

  // 5
  else if (rowPin == 14 && columnPin == 6)
    return &this->keyboardButtons[91];
  else if (rowPin == 10 && columnPin == 7)
    return &this->keyboardButtons[79];
  else if (rowPin == 9 && columnPin == 7)
    return &this->keyboardButtons[95];

  // 6
  else if (rowPin == 8 && columnPin == 6)
    return &this->keyboardButtons[93];
  else if (rowPin == 16 && columnPin == 6)
    return &this->keyboardButtons[80];
  else if (rowPin == 9 && columnPin == 6)
    return &this->keyboardButtons[75];

  // 7
  else if (rowPin == 10 && columnPin == 5)
    return &this->keyboardButtons[11];
  else if (rowPin == 16 && columnPin == 5)
    return &this->keyboardButtons[9];
  else if (rowPin == 8 && columnPin == 5)
    return &this->keyboardButtons[10];
  else if (rowPin == 9 && columnPin == 5)
    return &this->keyboardButtons[2];
}

KeyboardButton * KeyboardManager::getRightMapping(int8_t rowPin, int8_t columnPin)
{
  // 1
  if (rowPin == 16 && columnPin == 15)
    return &this->keyboardButtons[31];
  else if (rowPin == 9 && columnPin == 15)
    return &this->keyboardButtons[32];
  else if (rowPin == 10 && columnPin == 15)
    return &this->keyboardButtons[18];

  // 2
  else if (rowPin == 10 && columnPin == 18)
    return &this->keyboardButtons[98];
  else if (rowPin == 9 && columnPin == 18)
    return &this->keyboardButtons[81];
  else if (rowPin == 14 && columnPin == 15)
    return &this->keyboardButtons[87];

  // 3
  else if (rowPin == 14 && columnPin == 7)
    return &this->keyboardButtons[94];
  else if (rowPin == 16 && columnPin == 7)
    return &this->keyboardButtons[83];
  else if (rowPin == 16 && columnPin == 18)
    return &this->keyboardButtons[86];
  else if (rowPin == 8 && columnPin == 15)
    return &this->keyboardButtons[33];

  // 4
  else if (rowPin == 10 && columnPin == 6)
    return &this->keyboardButtons[82];
  else if (rowPin == 8 && columnPin == 7)
    return &this->keyboardButtons[84];
  else if (rowPin == 8 && columnPin == 18)
    return &this->keyboardButtons[29];
  else if (rowPin == 14 && columnPin == 18)
    return &this->keyboardButtons[27];

  // 5
  else if (rowPin == 14 && columnPin == 6)
    return &this->keyboardButtons[88];
  else if (rowPin == 10 && columnPin == 7)
    return &this->keyboardButtons[85];
  else if (rowPin == 9 && columnPin == 7)
    return &this->keyboardButtons[28];

  // 6
  else if (rowPin == 8 && columnPin == 6)
    return &this->keyboardButtons[89];
  else if (rowPin == 16 && columnPin == 6)
    return &this->keyboardButtons[30];
  else if (rowPin == 9 && columnPin == 6)
    return &this->keyboardButtons[26];

  // 7
  else if (rowPin == 10 && columnPin == 5)
    return &this->keyboardButtons[34];
  else if (rowPin == 16 && columnPin == 5)
    return &this->keyboardButtons[35];
  else if (rowPin == 8 && columnPin == 5)
    return &this->keyboardButtons[36];
  else if (rowPin == 9 && columnPin == 5)
    return &this->keyboardButtons[9];
}

KeyboardButton * KeyboardManager::getNumberMapping(int8_t rowPin, int8_t columnPin)
{
  // 1
  if (rowPin == 16 && columnPin == 15)
    return &this->keyboardButtons[12];
  else if (rowPin == 9 && columnPin == 15)
    return &this->keyboardButtons[3];
  else if (rowPin == 10 && columnPin == 15)
    return &this->keyboardButtons[18];

  // 2
  else if (rowPin == 10 && columnPin == 18)
    return &this->keyboardButtons[61];
  else if (rowPin == 9 && columnPin == 18)
    return &this->keyboardButtons[56];
  else if (rowPin == 14 && columnPin == 15)
    return &this->keyboardButtons[50];

  // 3
  else if (rowPin == 14 && columnPin == 7)
    return &this->keyboardButtons[52];
  else if (rowPin == 16 && columnPin == 7)
    return &this->keyboardButtons[57];
  else if (rowPin == 16 && columnPin == 18)
    return &this->keyboardButtons[48];
  else if (rowPin == 8 && columnPin == 15)
    return &this->keyboardButtons[49];

  // 4
  else if (rowPin == 10 && columnPin == 6)
    return &this->keyboardButtons[53];
  else if (rowPin == 8 && columnPin == 7)
    return &this->keyboardButtons[58];
  else if (rowPin == 8 && columnPin == 18)
    return &this->keyboardButtons[3];
  else if (rowPin == 14 && columnPin == 18)
    return &this->keyboardButtons[51];

  // 5
  else if (rowPin == 14 && columnPin == 6)
    return &this->keyboardButtons[54];
  else if (rowPin == 10 && columnPin == 7)
    return &this->keyboardButtons[59];
  else if (rowPin == 9 && columnPin == 7)
    return &this->keyboardButtons[4];

  // 6
  else if (rowPin == 8 && columnPin == 6)
    return &this->keyboardButtons[55];
  else if (rowPin == 16 && columnPin == 6)
    return &this->keyboardButtons[60];
  else if (rowPin == 9 && columnPin == 6)
    return &this->keyboardButtons[5];

  // 7
  else if (rowPin == 10 && columnPin == 5)
    return &this->keyboardButtons[11];
  else if (rowPin == 16 && columnPin == 5)
    return &this->keyboardButtons[9];
  else if (rowPin == 8 && columnPin == 5)
    return &this->keyboardButtons[10];
  else if (rowPin == 9 && columnPin == 5)
    return &this->keyboardButtons[2];
}
