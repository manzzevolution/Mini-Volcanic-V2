int getBatteryLevel(){
  // 132.89x - 460.72
  long adc = 0;
  float adcVoltage = 0;
  for (int i = 0 ; i < 200 ; i++){
    adc += analogRead(A0);
    delay(1);
  }
  adcVoltage = (float)adc / 200;
  float tegangan = (adcVoltage / 1023.0 ) * 6.377;
  float percentage = (132.89*tegangan) - 460.72;
  Serial.println("---------- Battery ADC ------------");
  Serial.print("ADC       = ");Serial.println(adcVoltage);
  Serial.print("Voltage   = ");Serial.println(tegangan);
  Serial.print("Pecentage = ");Serial.println(percentage);
  Serial.println("-----------------------------------");
  if (percentage>100){
    percentage = 100;
  }
  if (percentage<0){
    percentage = 0;
  }
  return (int)percentage;
}
