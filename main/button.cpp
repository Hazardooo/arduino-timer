#include "button.h"

Button::Button(int buttonPin)
  : ButtonPin(buttonPin) {
  Mode = 2;
  NextModeBlock = false;
}

bool Button::isButtonPressed() {
  if (millis() - ButtonDelay > 3000) {
    ButtonDelay = millis();
    NextModeBlock = false;
  }
  if (!NextModeBlock) {
    if (digitalRead(ButtonPin)) {
      NextMode();
      NextModeBlock = true;
    }
  }
}

int Button::GetMode() {
  return Mode;
}

void Button::NextMode() {
  if (Mode >= 2) {
    Mode = 0;
    return;
  }
  Mode++;
}