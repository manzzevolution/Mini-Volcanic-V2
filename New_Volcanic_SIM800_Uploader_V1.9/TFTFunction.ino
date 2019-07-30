void TFTprintStartUp(){
  tft.setTextWrap(false);
  displayClear();
  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(3);

  for (int i = 160 ; i>15 ; i = i-5){
    tft.fillRect(i,20,160,22,ST77XX_BLACK);
    tft.setCursor(i, 20);
    tft.println("SENSYNC");
    delay(75);
  }
  tft.setCursor(43, 50);
  tft.println("MINI");
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(30, 80);
  tft.println("VOLCANIC");
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(0);
  tft.setCursor(35, 115);
  tft.println("VLCNC-V2-M4N22");
  clearData();
  delay(3000);
}

void displayClear(){
  tft.fillScreen(ST77XX_BLACK);
}

void displayMain(){
  displayClear();
  displayTime();
  displayOnline();
  batteryPercentage(persenBatre);
  signalStrength(persenSignal);
  displayAllData();
}

void batteryPercentage(int persen){
  float panjang = (((float)persen) / 100.0) * 40;
  tft.fillRect(119,1,(int)panjang,10,ST77XX_GREEN);
  tft.drawRect(119,1,40,10,ST77XX_WHITE);
  tft.setCursor(94,2);
  tft.setTextSize(0);
  tft.print(persen);tft.print("%");
}
void displayOnline(){
  if (isSIMAvailable && isSignalAvailable){
    tft.fillCircle(78,12,6,ST77XX_GREEN);
  } else {
    tft.fillCircle(78,12,6,ST77XX_RED);
  }
    
}
void signalStrength(int persen){
  int jumbar = persen / 10;
  tft.setCursor(94,17);
  tft.setTextSize(0);
  tft.print(persen);tft.print("%");
  for (int i = 0 ; i < jumbar ; i++){
    tft.fillRect(119 + (i * 4),15,2,11,ST77XX_CYAN);
  }
}

void displayTime(){
  displayData();
  jamAja.remove(5);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.setCursor(0,20);
  tft.println(tanggalAja);
  tft.setTextSize(2);
  tft.setCursor(0,0);
  tft.println(jamAja);
  tft.drawLine(0,30,160,30,ST77XX_WHITE);
}

void displayAllData(){
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(2);
  tft.setCursor(20,35);
  tft.println("CH4");
  tft.setCursor(10,55);
  tft.println(CH4ppm,1);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(100,35);
  tft.println("H2S");
  tft.setCursor(85,55);
  tft.println(H2Sppm,2);
  tft.drawLine(0,75,160,75,ST77XX_WHITE);
}

void displaySerial(String txt){
  tft.fillRect(0,76,160,52,ST77XX_BLACK);
  for (int i = 5 ; i >= 1 ; i--){
    serialData[i] = serialData[i-1];
  }
  serialData[0] = txt;
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.setCursor(0,77);
  for (int i = 0 ; i < 6 ; i++){
    if (serialData[i] != ""){
      tft.print("> ");tft.println(serialData[i]);  
    }
  }
}

void clearData(){
  for (int i = 0 ; i < 6 ; i++){
    serialData[i] = "";
  }
}
