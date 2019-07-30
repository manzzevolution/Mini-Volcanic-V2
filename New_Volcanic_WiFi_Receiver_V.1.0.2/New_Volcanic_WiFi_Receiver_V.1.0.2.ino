#include "config.h"
void setup() {
  initFunction();
}
void loop() {
  getWiFiData();
  yield();
}
