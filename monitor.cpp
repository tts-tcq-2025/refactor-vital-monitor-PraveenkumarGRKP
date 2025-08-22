#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void sleep() {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
  cout << "\r  \r" << flush;
}

int messagereturn(const char* message) {
    cout << message << "\n";
    sleep();
    return 0;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (temperature > 102 || temperature < 95) {
   return messagereturn(Temperature is critical!");
  }
  if (pulseRate < 60 || pulseRate > 100) {
   return messagereturn("Pulse Rate is out of range!");
  }
  if (spo2 < 90) {
   return messagereturn("Oxygen Saturation out of range!");
  }
  return 1;
}
