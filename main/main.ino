#include "button.h"
#include "display.h"
#include "timer.h"
#include "rgb.h"

Button ModeButton;
Display TimerDisplay;
TimerLogic Logic;
RGB RGBLed;

void setup() {
  Serial.begin(9600);
  TimerDisplay.DisplayInit();
  RGBLed.RGBInit();
  ModeButton.ButtonInit();
}

void loop() {
  ModeButton.isButtonPressed();
  if (ModeButton.GetMode() == 0) {
    RGBLed.Green();
    Logic.Start();
    TimerDisplay.ShowDigit(Logic.GetTick());
  } else if (ModeButton.GetMode() == 1) {
    RGBLed.Blue();
    Logic.Stop();
  } else {
    RGBLed.Red();
    Logic.Restart();
    TimerDisplay.ShowDigit(Logic.GetTick());
  }
}