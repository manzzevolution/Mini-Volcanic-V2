void initFunction(){
  Serial.begin(115200);
  SerialNano.begin(9600);
  WiFi.mode(WIFI_AP_STA);
  WiFi.disconnect(true);
  WiFi.begin(ssidReceiver, passReceiver);           // connects to the WiFi AP
  Serial.println();
  Serial.println("Connection to the AP");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(2000);
    WiFi.begin(ssidReceiver, passReceiver);           // connects to the WiFi AP
  }
  
  WiFi.softAPConfig(ip, gateway, mask);
  WiFi.softAP(ssidTransmitter, passTransmitter);
  
  
  client.setTimeout(5000);
  Serial.println();
  Serial.println("Connected");
  Serial.println("station_bare_01.ino");
  Serial.print("LocalIP:"); Serial.println(WiFi.localIP());
  Serial.println("MAC:" + WiFi.macAddress());
  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
}
