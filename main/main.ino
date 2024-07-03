#include "button.h"
#include "display.h"

int buttonPin = 10;
Button ModeButton(buttonPin);
Display TimerDisplay;
int digid = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, OUTPUT);
  TimerDisplay.DisplayInit();
}

void loop() {
  ModeButton.isButtonPressed();
  Serial.println(ModeButton.GetMode());
  TimerDisplay.ShowDigit(8);
}
