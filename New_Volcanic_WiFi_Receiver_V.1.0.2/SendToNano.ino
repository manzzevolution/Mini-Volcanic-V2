void SendToNano(String text){
  int batPersen = getBatteryLevel();
  Serial.print(">>>>"); Serial.println(batPersen);
  getTimeRTC();
  String dateTime = String(tahun) + "," + String(bulan) + "," + String(tanggal) + "," +  String(jam) + "," + String(menit) + "," + String(detik) + "," ;
  String sendDataString = dateTime + text + batPersen + "," + rssiToPercentage(rssi) ;
  Serial.println("Nano Table   : | Tahun | Bulan | Tanggal | Jam | Menit | Detik | CH4 | H2S | % Battery | RSSI |");
  Serial.print  ("Send to Nano : ");Serial.println(sendDataString);
  SerialNano.println(sendDataString);
}
