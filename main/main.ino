#include "button.h"
#include "display.h"
#include "timer.h"
#include "rgb.h"

int buttonPin = 10;
Button ModeButton(buttonPin);
Display TimerDisplay;
TimerLogic Logic;
RGB RGBLed;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, OUTPUT);
  TimerDisplay.DisplayInit();
  RGBLed.RGBInit();
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