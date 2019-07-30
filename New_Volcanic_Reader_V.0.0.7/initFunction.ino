void initFunction(){
  SerialMonitor.begin(115200);\
  pinMode(pinBuzzer,OUTPUT);
  pinMode(pinPump,OUTPUT);
  pinMode(pinESPReset,OUTPUT);
  digitalWrite(pinESPReset,HIGH);
  
  buzzerTempOn(500);
  logo();
  //--- Oled Init
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Adafruit5x7);
  oled.clear();
  oled.setCursor(0,0);
  oled.set2X();
  oledFlashln("Sensync");
  SerialFlashln("Sensync Volcanic 2.0");
  oled.set1X();
  oledFlashln("Volcanic 2.0");
  for (int i = 0;i <=15;i++){
    oledFlash("-");
    delay(100);
  }
  delay(1000);
  //--- CH4 init
  oled.println();
  oledFlashln("Initializing");
  delay(2000);
  SerialFlashln("Init CH4");
  WinsenCH4Port.begin(9600);
  WinsenCH4Port.setTimeout(3000);
  oledFlashln("CH4 OK!");
  delay(2000);
  //--- H2S init
  SerialFlashln("Init H2S");
  WinsenH2SPort.begin(9600);
  WinsenH2SPort.setTimeout(3000);
  oledFlashln("H2S OK!");
  delay(2000);

  // WiFi init 
  SerialFlashln("Init WiFi");
  WiFiPort.begin(9600);
  oledFlashln("WiFi OK!");
  WiFiPort.setTimeout(3000);
  delay(2000);
}

void logo(){
  SerialFlashln("      __");
  SerialFlashln("    /    )");
  SerialFlashln("    \\        __    __   __          __    __");
  SerialFlashln("     \\     /___) /   ) (_ ` /   / /   ) /    ");
  SerialFlashln("_(____/___(___ _/   /_(__)_(___/_/   /_(___ _");
  SerialFlashln("                              /");
  SerialFlashln("                          (_ / ");
}
