// ----------------------------------------- Wifi AP Init --------------------------
#include <ESP8266WiFi.h>
WiFiServer server(80);
IPAddress IP(192,168,1,15);
IPAddress mask(255, 255, 255, 0);

// ----------------------------------------------------------------------------

#include <SoftwareSerial.h>
SoftwareSerial SerialNano(D4, D3); // RX, TX

byte ledPin = 2;

String request = "";

unsigned long waktuLama = 0;
unsigned long waktuLamaLED = 0;

int detik,menit,jam,tanggal,bulan,tahun;
float voltageBattery = 0;
int persenBattery = 0;
int rssi = 0;
// ----------------------------------------- SDCard Init -----------------------------------------
// include the SD library:
#include <SPI.h>
#include <SD.h>

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = D8;
// ---------------------------------------------------------------------------------------------

 // ----------------------------------------- RTC ds3231 Init ----------------------------

#include <Wire.h>
#include <DS3231.h>

DS3231 rtc;
RTCDateTime dt;
// ---------------------------------------------------------------------------------------------
