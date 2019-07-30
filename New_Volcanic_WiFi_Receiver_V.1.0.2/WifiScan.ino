void wifiScan(){
  Serial.println("------------------ Scan Wifi ------------------");
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.println(")");
      if (WiFi.SSID(i) == "Volcanic Transmitter"){
        rssi = WiFi.RSSI(i);
        rssiToPercentage(rssi);
        Serial.println("Found Transmitter !");
      }
    }
  }
  Serial.println("---------------------------------");
}

int rssiToPercentage(int rssinya){
  // =-0.0134*POWER(x;2)-0.2228*x+100.2       
  Serial.println(" ------------ HITUNG RSSI ---------------");
  if (rssinya == 0) {
    return 0;
  }
  Serial.print("RSSI : ");Serial.println(rssinya);
  float hasilnya = (-0.0134*rssinya*rssinya) - 0.2228 * rssinya + 100.2;
  if (hasilnya < 0){
    hasilnya = 0;
  }
  if (hasilnya > 100){
    hasilnya = 100;
  }
  Serial.print("Persen RSSI : ");Serial.println(hasilnya);
  Serial.println(" ------------ END RSSI ---------------");
  return (int)hasilnya;
}
