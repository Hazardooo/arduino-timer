#include "timer.h"

TimerLogic::TimerLogic() {
  Tick = 0;
  Limit = 60;
  StopFlag = false;
};

void TimerLogic::Start() {
  if (millis() - TimerDelay > 1000) {
    TimerDelay = millis();
    if (Tick < Limit) {
      if (!StopFlag) {
        Tick++;
        return;
      }
    } else {
      Stop();
      return;
    }
  }
}

void TimerLogic::Stop() {
  StopFlag = true;
}

void TimerLogic::Restart() {
  Tick = 0;
  TimerDelay = 0;
  StopFlag = false;
}

const int TimerLogic::GetTick() {
  return Tick;
}