#include "button.h"

Button::Button() {
  ButtonPin = 10;
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

void Button ::ButtonInit() {
  pinMode(ButtonPin, OUTPUT);
}

const int Button::GetMode() {
  return Mode;
}

void Button::NextMode() {
  if (Mode >= 2) {
    Mode = 0;
    return;
  }
  Mode++;
}