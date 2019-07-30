float MQ139Sampling(int jumlahSampling,int waktu){
  long sumADC = 0;
  float volt = 0;
  for (int i = 0 ; i < jumlahSampling ; i++){
    int a = analogRead(pinMQ136);
    sumADC += a;
    SerialFlash("ADC = ");Serial.print(a);SerialFlash("\tsumADC = ");Serial.println(sumADC);
    delay(waktu);
  }
  float averageADC;
  float ppm;
  averageADC = (float)sumADC/(float)jumlahSampling;
  volt = (adcTomiliVolt * averageADC)/1000.0;
  ppm = convertToPPM(volt);
  SerialFlash("Sum V ADC     = ");Serial.println(sumADC);
  SerialFlash("Average V ADC = ");Serial.println(averageADC);
  SerialFlash("Voltage       = ");Serial.println(volt);
  SerialFlash("PPM           = ");Serial.println(ppm);
  return volt;
}

float convertToPPM(float x){
  float x5,x4,x3,x2,x1,c,y;
  x5 = 328.86 * pow(x,5);
  x4 = 2146.2 * pow(x,4);
  x3 = 5604.9 * pow(x,3);
  x2 = 7213.1 * pow(x,2);
  x1 = 4534.8 * x;
  c  = 1105.2;  
  
  y = x5 - x4 + x3 - x2 + x1 - c;
  SerialFlash("X5 = ");Serial.println(x5);
  SerialFlash("X4 = ");Serial.println(x4);
  SerialFlash("X3 = ");Serial.println(x3);
  SerialFlash("X2 = ");Serial.println(x2);
  SerialFlash("X1 = ");Serial.println(x1);
  SerialFlash("Y  = ");Serial.println(c);
  if (x < 0.73){
    return (-1*y)/400.0;
  } else {
    return y;
  }
}
