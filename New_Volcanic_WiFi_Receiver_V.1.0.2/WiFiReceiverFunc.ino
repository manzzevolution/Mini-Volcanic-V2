void initWiFi(){
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("Volcanic Receiver", "Volcanic2019");
  WiFi.softAPConfig(IP, IP, mask);
  server.begin();
  Serial.println();
  Serial.println("accesspoint_bare_01.ino");
  Serial.println("Server started.");
  Serial.print("IP: "); Serial.println(WiFi.softAPIP());
  Serial.print("MAC:"); Serial.println(WiFi.softAPmacAddress());
}

void getWiFiData(){
  WiFiClient client = server.available();
  request = "";
  yield();
  client.setTimeout(10000`);
  if (client) {
    request = client.readStringUntil('\r');
    Serial.println("********************************");
    Serial.println("From the station: " + request);
    client.flush();
    Serial.print("Byte sent to the station: ");
    Serial.println(client.println("OK\r"));
    wifiScan();
    getBatteryLevel();
    SendToPLXDAQ(request);
    SaveToSDCard(request,".csv");
    SendToNano(request);
    Serial.println("Waiting Data.. !");
    if (request != ""){
      waktuLama = millis();
      yield();
    }
  } else {
    if(millis() - waktuLama > 40000){
      waktuLama = millis();
      Serial.println("No Responses");
      wifiScan();
      getBatteryLevel();
      SendToNano("-1,-1,");
      if (request != ""){
        Serial.println("Empty Data");
      }
    }
      
  }
}
