#include "WiFi.h"
#include "ThingSpeak.h"

const char* ssid = "Wokwi-GUEST";  
const char* password = "";  
WiFiClient  client;

unsigned long hello2 = 2;
unsigned long hello1 = 1;

const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

void setup() {

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
  ThingSpeak.begin(client);  

}

void loop() {

int number1 = random(10,101);
int number2 = random(10,101);
int number3 = random(10,101);
int number4 = random(10,101);
int number5 = random(10,101);
int number6 = random(10,101);
int number7 = random(10,101);
int number8 = random(1,14);
int number9 = random(10,101);
int number10 = random(10,101);
int number11 = random(10,101);
int number12 = random(10,101);
int number13 = random(10,101);
int number14 = random(10,101);
int number15 = random(10,101);
int number16 = random(10,101);
int number17 = random(10,101);
int number18 = random(10,101);
int number19 = random(10,101);
int number20 = random(10,101);
int number21 = random(10,101);
int number22 = random(10,101);
int number23 = random(10,101);
int number24 = random(10,101);
  if ((millis() - lastTime) > timerDelay) {
    ThingSpeak.setField(1, number1);
    ThingSpeak.setField(2, number2);
    ThingSpeak.setField(3, number3);
    ThingSpeak.setField(4, number4);
    ThingSpeak.setField(5, number5);
    ThingSpeak.setField(6, number6);
    ThingSpeak.setField(7, number7);
    ThingSpeak.setField(8, number8);
  int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);
    ThingSpeak.setField(1, number9);
    ThingSpeak.setField(2, number10);
    ThingSpeak.setField(3, number11);
    ThingSpeak.setField(4, number12);
    ThingSpeak.setField(5, number13);
    ThingSpeak.setField(6, number14);
    ThingSpeak.setField(7, number15);
    ThingSpeak.setField(8, number16);
  int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
 
    lastTime = millis();
  }
}