void initRTC(){
  Serial.println(F("Init RTC"));
  rtc.begin();

  // Set sketch compiling time
  // rtc.setDateTime(__DATE__, __TIME__);

  // Set from UNIX timestamp
  // rtc.setDateTime(1397408400);

  // Manual (YYYY, MM, DD, HH, II, SS
  // rtc.setDateTime(2014, 4, 13, 19, 21, 00);
}

String getTimeRTC(){
  String fullFormat;
  dt = rtc.getDateTime();
  fullFormat = String(dt.year) + "-" + String(dt.month) + "-" + String(dt.day) + " " + String(dt.hour) + ":" + String(dt.minute) + ":" + String(dt.second);
  Serial.print("Raw data from RTC: ");
  Serial.println(fullFormat);
  tahun = (dt.year);   
  bulan = (dt.month);  
  tanggal = (dt.day);    
  jam = (dt.hour);   
  menit = (dt.minute); 
  detik =(dt.second); 
  return fullFormat;
}
