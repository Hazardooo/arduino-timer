#ifndef TIMER_H
#define TIMER_H
#include <Arduino.h>

class TimerLogic {
public:
  TimerLogic();
  void Start();
  const int GetTick();
  void Restart();
  void Stop();
private:
  int Tick;
  int Limit;
  unsigned long TimerDelay;
  bool StopFlag;
};
#endif