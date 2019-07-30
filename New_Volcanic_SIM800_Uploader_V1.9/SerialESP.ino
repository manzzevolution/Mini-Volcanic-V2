String waitCommandESP(int timeout){
  String dataESP = "";
  SerialESP.listen();
  Serial.println(F("Waiting Data !"));
  displaySerial(F("Waiting Data !"));
  for (int i = 0 ; i < timeout;i++){
    SerialESP.setTimeout(1000);
    dataESP = SerialESP.readStringUntil('\n');
    if (dataESP != ""){
      Serial.println();
      Serial.println(F("> Received"));
      break;
    } else {
      Serial.print(".");
    }
  }
  if (dataESP != ""){
    return dataESP;
  } else{
    return "null";
  }
}

void parsingData(String txt){
  String text = txt + ",";
  String arrayData[20];
  jumlahKoma = 0;
  int datake = 0;
  for(int i = 0; i < text.length();i++){
    if (text[i] != ','){
      arrayData[datake] += text[i];
      Serial.println(text[i]);
    } else {
      datake++;
      jumlahKoma++;
    }
  }
//  for checking data array
  for(int i = 0; i < 11; i++){
    Serial.print(i+1);SerialFlash(". ");Serial.println(arrayData[i]);
  }  
  if (arrayData[0].toInt() != 0){
    tahun = arrayData[0].toInt();
  }  
  if (arrayData[1].toInt() != 0){
    bulan = arrayData[1].toInt();
  }  
  if (arrayData[2].toInt() != 0){
    tanggal = arrayData[2].toInt();
  }  
  if (arrayData[3].toInt() != 0){
    jam = arrayData[3].toInt();
  }  
  if (arrayData[4].toInt() != 0){
    menit = arrayData[4].toInt();
  }  
  if (arrayData[5].toInt() != 0){
    detik = arrayData[5].toInt();
  }
  CH4ppm = arrayData[6].toFloat();
  H2Sppm = arrayData[7].toFloat();
  
  persenBatre = arrayData[8].toInt();
  persenSignal = arrayData[9].toInt();
}

void displayData(){
  tanggalAja = "";  
  jamAja = "";
  if (bulan < 10){
    if (tanggal < 10){
      tanggalAja = String(tahun) + "/0" + String(bulan) + "/0" + String(tanggal);
    } else {
      tanggalAja = String(tahun) + "/0" + String(bulan) + "/" + String(tanggal);
    }
  } else {
    if (tanggal < 10){
      tanggalAja = String(tahun) + "/" + String(bulan) + "/0" + String(tanggal);
    } else {
      tanggalAja = String(tahun) + "/" + String(bulan) + "/"+ String(tanggal);
    }
  }
  if (jam < 10){
    if (menit < 10){
      if (detik < 10){
        jamAja = "0" + String(jam) + ":0" + String(menit) + ":0" + String(detik);
      } else {
        jamAja = "0" + String(jam) + ":0" + String(menit) + ":" + String(detik);
      }
    } else {
      if (detik < 10){
        jamAja = "0" + String(jam) + ":" + String(menit) + ":0" + String(detik);
      } else {
        jamAja = "0" + String(jam) + ":" + String(menit) + ":" + String(detik);
      }      
    }
  } else {
    if (menit < 10){
      if (detik < 10){
        jamAja = String(jam) + ":0" + String(menit) + ":0" + String(detik);
      } else {
        jamAja = String(jam) + ":0" + String(menit) + ":" + String(detik);
      }
    } else {
      if (detik < 10){
        jamAja = String(jam) + ":" + String(menit) + ":0" + String(detik);
      } else {
        jamAja = String(jam) + ":" + String(menit) + ":" + String(detik);
      }      
    }    
  }
    
  
  SerialFlashln("----------------------------");
  SerialFlash("Tanggal : ");Serial.println(tanggalAja);
  SerialFlash("Jam     : ");Serial.println(jamAja);
  SerialFlash("CH4 ppm : ");Serial.println(CH4ppm);
  SerialFlash("H2S ppm : ");Serial.println(H2Sppm);
  SerialFlashln("----------------------------");
}
