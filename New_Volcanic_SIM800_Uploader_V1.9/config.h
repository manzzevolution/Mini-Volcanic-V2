#define SerialFlashln(x) Serial.println(F(x))
#define SerialFlash(x) Serial.print(F(x))
// Select your modem:

#define SerialMon Serial
#include <SoftwareSerial.h>

SoftwareSerial SerialAT(7, 8); // RX, TX
SoftwareSerial SerialESP(9, 10); // RX, TX

String response;
const String apn = "internet";
const String user = "";
const String pass = "";

float CH4ppm,H2Sppm;

int detik,menit,jam,tanggal,bulan,tahun;
String tanggalAja = "";
String jamAja = "";
String rawDataESP;
byte jumlahKoma;
byte persenBatre;
byte persenSignal;
bool isSignalAvailable = false;
byte signalValue;
bool isSIMAvailable = false;
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#define TFT_CS     3
#define TFT_RST    -1  // you can also connect this to the Arduino reset
#define TFT_DC     2

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

String serialData[6];
unsigned long jumlahData = 0;
