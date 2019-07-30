void samplingRoutine(){
  clearToTop;
  buzzerTempOn(50);
  oledFlash("Sampling No.");oled.println(numSampling+1);
  SerialFlash("Sampling No.");SerialMonitor.println(numSampling+1);
  oledFlashln("Pump On.");
  pumpOn();
  delay(2000);
  oledFlashln("Pump Off.");
  pumpOff();
  for(int i = 0; i < 3;i++){
    CH4ppm = WinsenCH4(withDebug);
    if ((MH440D[0] == 0xFF) && (MH440D[1] == 0x86)){
      break;
    }
    SerialFlashln("Retry");
  }
  oledFlashln("CH4 Done!");
  SerialFlashln("CH4 Done!");
  oledFlash("H2S Sampling");
  waitDelay(5);
  teganganMQ139 = MQ139Sampling(1000,1);
  H2Sppm = convertToPPM(teganganMQ139);
  oledFlashln("H2S Done!");
  SerialFlashln("H2S Done!");
  delay(1000);
  numSampling++;
  clearToTop;
  oledFlash("Displaying Data");
  delay(2000);
  displayData();
  oledFlashln("Sending Data !");
  SerialFlashln("Sending Data !");
  sendToWiFi(allData);
  oledFlashln("Done !");
  SerialFlashln("Done !");
  delay(3000);
  for(int i = 0 ; i< 3; i++){
    buzzerTempOn(50);
  }
}

void displayData(){
  clearToTop;
  allData = "";
  oledFlash("Sample No.");oled.println(numSampling);
  oledFlashln("--------------");
  oledFlash("CH4 = ");oled.print(CH4ppm);oledFlashln(" ppm");
  oledFlash("H2S = ");oled.print(H2Sppm);oledFlashln(" ppm");
  oledFlashln("--------------");

  
  SerialFlashln("Displaying Data");
  SerialFlash("Sample No.");SerialMonitor.println(numSampling);
  SerialFlashln("--------------");
  SerialFlash("CH4 = ");SerialMonitor.print(CH4ppm);SerialFlashln(" ppm");
  SerialFlash("H2S = ");SerialMonitor.print(H2Sppm);SerialFlashln(" ppm");
  SerialFlashln("--------------");
  allData = String(CH4ppm) + "," + String(H2Sppm) + ",";
  SerialMonitor.println(allData);
  for (int i = 0;i <=10;i++){
    oledFlash("-");
    delay(100);
  }
  oledFlashln("");
}
