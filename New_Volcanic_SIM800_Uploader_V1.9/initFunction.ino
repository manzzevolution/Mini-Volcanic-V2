void initFunction(){
  String checkSIM;
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  Serial.begin(115200);
  SerialAT.begin(9600);
  SerialESP.begin(9600);
  Serial.println("Begin !");
  tft.setRotation(3);
  TFTprintStartUp();
  displayMain();
  initPLXDAQ();
  SerialAT.listen();
  sendCommand("AT+CFUN=0","OK",5);
  checkSIM = sendCommand("AT+CFUN=1","OK",5);
  if (checkSIM.indexOf("NOT INSERT") > 0){
    isSIMAvailable = false;
    displaySerial(F("Please Check SIM Card"));
    displaySerial(F("Offline Mode"));
  } else {
    isSIMAvailable = true;
  }
  delay(500);
}
