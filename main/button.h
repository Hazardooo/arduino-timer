#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button {
public:
  Button(int buttonPin);
  bool isButtonPressed();
  void NextMode();
  int GetMode();
private:
  bool NextModeBlock;
  int ButtonPin;
  int Mode;
  unsigned long ButtonDelay;
};

#endif
