float WinsenCH4(bool debug){
  long hasilPPM;
  SerialFlashln("Waiting Data From MH440D.."); 
  for (int i = 0 ; i<9 ; i++){
    MH440D[i] = 0;
  }
  WinsenCH4Port.listen();
  WinsenCH4Port.write(MH440DCommand, sizeof(MH440DCommand));
  WinsenCH4Port.readBytes(MH440D,CH4DataLength);    
  for(int i = 0;i < CH4DataLength;i++){
    SerialMonitor.print(i);SerialFlash(". ");SerialMonitor.println(MH440D[i],HEX);
  }    
  hasilPPM = ((MH440D[2]<<8) + MH440D[3]);  
  if (hasilPPM > 0){
    SerialFlash("CH4 Concentration = ");SerialMonitor.print(hasilPPM);SerialFlashln(" ppm");
  } else {
    hasilPPM = 0;
  }
  return ((float)hasilPPM);
}
