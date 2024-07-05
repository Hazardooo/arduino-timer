#ifndef RGB_H
#define RGB_H
#include <Arduino.h>

class RGB {
public:
  RGB();
  void RGBInit();
  void Red();
  void Green();
  void Blue();
private:
  int RedPin;
  int GreenPin;
  int BluePin;
};

#endif