void buzzerOn(){
  digitalWrite(pinBuzzer,LOW);
}
void buzzerOff(){
  digitalWrite(pinBuzzer,HIGH);
}

void buzzerTempOn(long timeX){
  buzzerOn();
  delay(timeX);
  buzzerOff();
  delay(timeX);
}
