#include "config.h"
void setup() {
  initFunction();
}

void loop() {
  ESPReset();
  samplingRoutine();
  delay(5000);
} 
