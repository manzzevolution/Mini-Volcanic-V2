void sendToWiFi(String msg){
  WiFiPort.listen();
  for (int i = 0 ; i < 5 ; i++){
    WiFiPort.println(msg); 
    delay(250);
  }
}

void ESPReset(){
  if (millis() - waktuLamaESP >= intervalESP){
    waktuLamaESP = millis();
    SerialFlashln("Routine - ESP Resetting");
    digitalWrite(pinESPReset,LOW);
    delay(10);
    digitalWrite(pinESPReset,HIGH);
  }
}
