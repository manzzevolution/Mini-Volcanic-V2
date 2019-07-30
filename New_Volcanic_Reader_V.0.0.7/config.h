#include <SoftwareSerial.h>
#define SerialMonitor Serial
#define SerialFlash(x)   SerialMonitor.print(F(x))
#define SerialFlashln(x) SerialMonitor.println(F(x))
#define oledFlash(x)   oled.print(x)
#define oledFlashln(x) oled.println(x)
#define clearToTop oled.clear(); \
                   oled.setCursor(0,0)

int numSampling = 0;
String allData;
#define pinBuzzer 12
#define pinESPReset 11
#define pinPump 9
#define pinMQ136 A0
#define adcTomiliVolt 4.87

SoftwareSerial WinsenH2SPort(4, 3); // RX, TX
#define H2SDataLength 9
#define withDebug true
#define noDebug false
byte ZE03[H2SDataLength];
float H2Sppm;
float teganganMQ139;

SoftwareSerial WinsenCH4Port(5, 6); // RX, TX
#define CH4DataLength 9
#define withDebug true
#define noDebug false
byte MH440D[CH4DataLength];
byte MH440DCommand[] = {0xFF ,0x01 ,0x86 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x79};
float CH4ppm;

#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;

SoftwareSerial WiFiPort(7, 8); // RX, TX

unsigned long waktuLamaESP;
#define intervalESP 60000
