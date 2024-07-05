#include "display.h"

Display::Display(){};

void Display::ShowDigit(int digit) {
  for (int i = 0; i < 4; i++) {    // Каждый разряд по очереди
    for (int k = 0; k < 8; k++) {  // Каждый сегмент по очереди - исходя из заданной карты
      digitalWrite(segmentsPins[k], !Digits[digit][k]);
    }
    digitalWrite(anodPins[i], HIGH);
    if (millis() - DisplayDelay > 1000) {
      DisplayDelay = millis();
      digitalWrite(anodPins[i], LOW);
    }
  }
}
void Display::DisplayInit() {
  for (int i = 0; i < 4; i++) {
    pinMode(anodPins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(segmentsPins[i], OUTPUT);
  }
}