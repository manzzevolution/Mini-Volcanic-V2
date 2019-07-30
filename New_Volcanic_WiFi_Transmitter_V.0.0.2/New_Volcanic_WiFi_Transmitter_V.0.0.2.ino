#include "config.h"

void setup() {
  initFunction();
}
void loop() {
  allData = getDataFromNano();
  if(!cekTimeout){
    SerialNano.flush();
    SendToReceiver(allData);
  }
}

void SendToReceiver(String txt){
  SerialFlashln("Sending to Uploader");
  client.connect(server, 80);
  SerialFlashln("********************************");
  SerialFlashln("Byte sent to the AP: ");
  Serial.println(client.print(txt));
  String answer = client.readStringUntil('\r');
  Serial.println("From the AP: " + answer);
  yield();
  client.flush();
  client.stop();
  delay(2000);
}
