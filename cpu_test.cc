#include <chrono>
#include <iostream>
#include <thread>

#include "CPUSnapshot.h"

int main() {
  CPUSnapshot previousSnap;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  CPUSnapshot curSnap;

  const float ACTIVE_TIME =
      curSnap.GetActiveTimeTotal() - previousSnap.GetActiveTimeTotal();
  const float IDLE_TIME =
      curSnap.GetIdleTimeTotal() - previousSnap.GetIdleTimeTotal();
  const float TOTAL_TIME = ACTIVE_TIME + IDLE_TIME;
  int usage = 100.f * ACTIVE_TIME / TOTAL_TIME;
  std::cout << "total cpu usage: " << usage << " %" << std::endl;
}