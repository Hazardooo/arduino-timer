#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>

class Display {
public:
  Display();
  void ShowDigit(int digit);
  void DisplayInit();
private:
  //{A, B, C, D, E, F, G, DP} - распиновка сегментов
  int Digits[10][8] = {
    { 1, 1, 1, 0, 1, 1, 1, 0 },  //Цифра 0
    { 0, 0, 1, 0, 0, 0, 1, 0 },  //Цифра 1
    { 0, 1, 1, 1, 1, 1, 0, 0 },  //Цифра 2
    { 0, 1, 1, 1, 0, 1, 1, 0 },  //Цифра 3
    { 1, 0, 1, 1, 0, 0, 1, 0 },  //Цифра 4
    { 1, 1, 0, 1, 0, 1, 1, 0 },  //Цифра 5
    { 0, 0, 1, 1, 1, 1, 1, 0 },  //Цифра 6
    { 0, 1, 1, 0, 0, 0, 1, 0 },  //Цифра 7
    { 1, 1, 1, 1, 1, 1, 1, 0 },  //Цифра 8
    { 1, 1, 1, 1, 0, 1, 1, 0 }   //Цифра 9
  };
  int anodPins[4] = { A1, A2, A3, A4 };
  int segmentsPins[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
};

#endif