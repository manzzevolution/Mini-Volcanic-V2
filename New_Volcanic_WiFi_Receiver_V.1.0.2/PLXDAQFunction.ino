void initPLXDAQ(){
  Serial.println("Init PLX-DAQ");
  Serial.println("CLEARDATA");//clear excel sheet
  Serial.println("LABEL,Waktu,CH4 ppm,H2S ppm");
}

void SendToPLXDAQ(String txt){
  Serial.println("Send to PLX-DAQ");
  Serial.print("DATA,TIME,");
  Serial.println(txt);//random number generator from 0 to 100
}
