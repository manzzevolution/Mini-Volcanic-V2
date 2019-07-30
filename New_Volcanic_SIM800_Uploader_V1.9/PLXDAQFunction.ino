void initPLXDAQ(){
  Serial.println(F("Init PLX-DAQ"));
  Serial.println(F("CLEARDATA"));//clear excel sheet
  Serial.println(F("LABEL,Waktu,CH4 ppm,H2S ppm"));
  displaySerial(F("Init PLX-DAQ"));
  displaySerial(F("LABEL,Waktu,CH4 ppm,H2S ppm"));
}

void SendToPLXDAQ(String txt){
  Serial.println(F("Send to PLX-DAQ"));
  Serial.print(F("DATA,TIME,"));
  Serial.println(txt);//random number generator from 0 to 100
  displaySerial(F("Send to PLX-DAQ"));
  displaySerial(F("DATA,TIME,"));
  displaySerial(txt);//random number generator from 0 to 100
}
