void initFunction(){
  Serial.begin(115200);
  SerialNano.begin(9600);
  delay(2000);
  serialInit();
  delay(3000);
  initWiFi();
  initRTC();
  getTimeRTC();
  SdFile::dateTimeCallback(fileDateTime);
  initSDCard();  
  SDCardInfo();
  initPLXDAQ();
}

void serialInit(){
  Serial.println(F("__     __    _                 _       __     ______        "));
  Serial.println(F("\\ \\   / /__ | | ___ __ _ _ __ (_) ___  \\ \\   / /___ \\  "));
  Serial.println(F(" \\ \\ / / _ \\| |/ __/ _` | '_ \\| |/ __|  \\ \\ / /  __) |"));
  Serial.println(F("  \\ V / (_) | | (_| (_| | | | | | (__    \\ V /  / __/     "));
  Serial.println(F("   \\_/ \\___/|_|\\___\\__,_|_| |_|_|\\___|    \\_/  |_____|"));
}
