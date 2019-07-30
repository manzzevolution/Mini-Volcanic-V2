void pumpOn(){
  for(int i = 0;i<=255;i++){
    analogWrite(pinPump,i);
    delay(10);
  }
}

void pumpOff(){
  for(int i = 255;i>=0;i--){
    analogWrite(pinPump,i);
    delay(10);
  }
}

void delayProgress(int waktu){
  long lamanya = waktu * 1000;
  for(int i = 0;i<=100;i++){
//    lcdPrintXY(i,12,1);lcd.print("%");
    float waktuTunggu = lamanya/100;
    if (i % 10 == 0){
//      serialPrint(i);
//      serialPrintln(" % ");
    }
    delay(waktuTunggu);
  }  
}
