long WinsenH2S(bool debug){
  long hasilPPM;
  SerialFlashln("Waiting Data From ZE03.."); 
  for (int i = 0 ; i<9 ; i++){
    ZE03[i] = 0;
  }
  WinsenH2SPort.listen();
  WinsenH2SPort.readBytes(ZE03,H2SDataLength);
  if (debug){   
  SerialFlashln("Data from ZE03 :"); 
    for(int i = 0;i < H2SDataLength;i++){
      SerialMonitor.print(i);SerialFlash(". ");SerialMonitor.println(ZE03[i],HEX);
    }
  }
  hasilPPM = ((ZE03[2]<<8) + ZE03[3]);  
  if (hasilPPM > 0){
    SerialFlash("H2S Concentration = ");SerialMonitor.print(hasilPPM);SerialFlashln(" ppm");
  } else {
    hasilPPM = 0;
  }
  return hasilPPM;
}
