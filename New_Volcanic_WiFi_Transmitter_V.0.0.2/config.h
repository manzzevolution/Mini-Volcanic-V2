#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#define SerialFlashln(x) Serial.println(F(x))
#define SerialFlash(x) Serial.print(F(x))
unsigned long waktuLama = 0;
unsigned long timeout = 1000 * 30 ;
int jumlahKoma = 0;
bool cekTimeout = false;
String allData;

SoftwareSerial SerialNano(D4, D3);

byte ledPin = 2;
char ssidReceiver[] = "Volcanic Receiver";           // ssidReceiver of your AP
char passReceiver[] = "Volcanic2019";         // passReceiverword of your AP
IPAddress server(192,168,1,15);     // IP address of the AP
WiFiClient client;


char ssidTransmitter[] = "Volcanic Transmitter";           // ssidReceiver of your AP
char passTransmitter[] = "Volcanic2019";         // passReceiverword of your AP
IPAddress ip(192,168,11,15);
IPAddress gateway(192,168,11,15);
IPAddress mask(255, 255, 255, 0);
