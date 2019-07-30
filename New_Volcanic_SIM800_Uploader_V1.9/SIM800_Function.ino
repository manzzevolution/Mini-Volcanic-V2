void SendToThingspeak(){
  SerialAT.listen();
  if(isSIMAvailable){
    sendCommand(F("AT"),"OK",5);
    sendCommand(F("AT+CREG?"),"OK",5);
    sendCommand(F("AT+COPS=?"),"+COPS:",20);
    signalValue = parsingSignal(sendCommand(F("AT+CSQ"),"OK",5));
    displaySerial("Signal = " + signalValue);
    if (signalValue < 15){
      isSignalAvailable = false;
      displaySerial(F("Signal Unavailable"));
    } else {
      isSignalAvailable = true;
      displaySerial(F("Signal Available"));
      displaySerial(F("Continue Upload"));
    }
    displayOnline();
    delay(2000);
    if(isSignalAvailable){
      sendCommand(F("AT+CIPSHUT"),"SHUT",5);
      sendCommand(F("AT+CIPMUX=0"),"OK",5);
      sendCommand(F("AT+CGATT=1"),"OK",5);
      sendCommand("AT+CSTT=\"" + apn + "\",\"" + user + "\",\"" + pass + "\"","OK",5);
      sendCommand(F("AT+CIICR"),"OK",20);
      sendCommand(F("AT+CIFSR"),".",20);
      sendCommand(F("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\""),"CONNECT",20);
      sendCommand(F("AT+CIPSEND"),">",20);
      sendCommand("GET /update?key=FVYVUH38SLDQ9644&field1=" + String(CH4ppm) +"&field2=" + String(H2Sppm),"SEND",5);
      sendChar26 (F("SEND"),20);
      waitResponse("CLOSED",20);
      sendCommand(F("AT+CIPSHUT"),"SHUT",5);
    }
  }
  displaySerial("Done !");
}

String sendCommand(String cmd, String resp, int timeout){
  String gsmString;
  Serial.print("Send Command > ");Serial.println(cmd);
  SerialAT.println(cmd);
  SerialAT.setTimeout(500);
  for (int i=0 ; i<(timeout*2) ; i++){
    gsmString = SerialAT.readString();
    if (gsmString !=""){
      Serial.print("> ");Serial.println(gsmString);
      if (gsmString.indexOf(resp) > 0){
        Serial.println("True");
        displaySerial(gsmString);
        return gsmString;
        break;
      } else {
        Serial.println("False");
      }  
    displaySerial(gsmString);
    } else {
      Serial.print("> ");Serial.println("Empty");
    }
  }
  return "null";
}

String sendChar26(String resp, int timeout){
  Serial.println("Wait Response !");
  String gsmString;
  SerialAT.println((char)26);  //-- sending
  SerialAT.setTimeout(500);
  for (int i=0 ; i<(timeout*2) ; i++){
    gsmString = SerialAT.readString();
    if (gsmString !=""){
      Serial.print("> ");Serial.println(gsmString);
      if (gsmString.indexOf(resp) > 0){
        Serial.println("True");
        displaySerial(gsmString);
        return gsmString;
        break;
      } else {
        Serial.println("False");
      }
    displaySerial(gsmString);
    } else {
      Serial.print("> ");Serial.println("Empty");
    }
  }
  return "null";
}

String waitResponse(String resp, int timeout){
  String gsmString;
  for (int i=0 ; i<(timeout*2) ; i++){
    gsmString = SerialAT.readString();
    if (gsmString !=""){
      Serial.print("> ");Serial.println(gsmString);
      if (gsmString.indexOf(resp) > 0){
        Serial.println("True");
          displaySerial(gsmString);
        return gsmString;
        break;
      } else {
        Serial.println("False");
      }
    displaySerial(gsmString);
    } else {
      Serial.print("> ");Serial.println("Empty");
    }
  }
  return "null";
}

int parsingSignal(String txt){
  String dataCSQ = "";
  String numCSQ = "";
  bool isDataCSQ = false;
  bool isSignalStr = false;
  for(int i = 0 ; i < txt.length() ; i++){
    if (txt[i] == '+'){
      isDataCSQ = true;
    }
    if (txt[i] == '\n'){
      isDataCSQ = false;
    }
    if (isDataCSQ){
      if(txt[i] == ':'){
        isSignalStr = true;
        i++;
        i++;
      }
      if(txt[i] == ','){
        isSignalStr = false;
      }
      if (isSignalStr){
        numCSQ += txt[i];
      }
      dataCSQ += txt[i];
    }
  }
  SerialFlash("Raw Signal = ");Serial.println(dataCSQ);
  SerialFlash("Signal     = ");Serial.println(numCSQ);
  return numCSQ.toInt();
}
