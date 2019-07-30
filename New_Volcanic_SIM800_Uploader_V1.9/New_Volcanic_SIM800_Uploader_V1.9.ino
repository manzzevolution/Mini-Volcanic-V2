#include "config.h"
void setup() {
  // Set console baud rate
  initFunction();

}

void loop() {
  rawDataESP = "";
  rawDataESP = waitCommandESP(60);
  Serial.print(F("Raw Data : "));
  Serial.println(rawDataESP);
  if(rawDataESP.length() > 10){
    parsingData(rawDataESP);
  }
  displayMain();
  displaySerial("Raw Data :" + rawDataESP);
  if (jumlahKoma > 7){
    if ((CH4ppm >= 0) || (H2Sppm >= 0)){
      displayData();
      SendToPLXDAQ(String(CH4ppm) + "," + String(H2Sppm));
      SendToThingspeak();
      delay(5000);
    } else {
      displayData();
      displaySerial(F("Invalid Data"));
    }
  }else {
    displaySerial(F("Invalid Data"));
  }
}
