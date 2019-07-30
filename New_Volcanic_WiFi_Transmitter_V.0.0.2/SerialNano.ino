String getDataFromNano(){
  bool quit = false;
  String seriesData;
  SerialFlashln("Waiting data from Nano");
  waktuLama = millis();
  while ((!quit) && (millis() - waktuLama <= timeout)){
    if (millis() % 1000 == 0){
      SerialFlash(".");
      delay(1);
    }
    if (SerialNano.available() > 0){
      char x = SerialNano.read();
      if (x == '\n'){
        quit = true;
      } else {
        if (x != ' '){
          seriesData += x;
        }
      }
    }
  }
  if (millis() - waktuLama >= timeout){
    cekTimeout = true;
  } else {
    cekTimeout = false;
  }
  Serial.println();
  SerialFlash("Raw Data : ");Serial.print(seriesData);SerialFlash(" Timeout Checker: ");Serial.println(cekTimeout);
  SerialNano.flush();
  return seriesData;
}
