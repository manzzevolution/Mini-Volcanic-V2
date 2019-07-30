void waitDelay(int delaynya){
  Serial.print("Waiting Sensor");
  for (int i = 0 ; i < delaynya ; i++){
    oledFlash(".");
    Serial.print(".");
    delay(1000);
  }
  oledFlashln("");
  Serial.println();
}
