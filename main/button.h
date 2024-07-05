#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button {
public:
  Button();
  bool isButtonPressed();
  void NextMode();
  void ButtonInit();
  const int GetMode();
private:
  bool NextModeBlock;
  int ButtonPin;
  int Mode;
  unsigned long ButtonDelay;
};

#endif
