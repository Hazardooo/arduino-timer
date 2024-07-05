#include "rgb.h"

RGB::RGB() {
  RedPin = 13;
  GreenPin = 12;
  BluePin = 11;
};

void RGB::RGBInit() {
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void RGB::Red() {
  digitalWrite(RedPin, 1);
  digitalWrite(GreenPin, 0);
  digitalWrite(BluePin, 0);
}
void RGB::Green() {
  digitalWrite(RedPin, 0);
  digitalWrite(GreenPin, 1);
  digitalWrite(BluePin, 0);
}
void RGB::Blue() {
  digitalWrite(RedPin, 0);
  digitalWrite(GreenPin, 0);
  digitalWrite(BluePin, 1);
}