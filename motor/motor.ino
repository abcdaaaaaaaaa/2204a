#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <SPI.h>
#include <Pixy.h>

const char* ssid = "****";
const char* password = "*****";
String xox;
const int IN2=2; 
const int IN1=4;
const int ENA=3;
const int IN4=7;
const int IN3=8;
const int ENB=5;

Pixy pixy;

float deadZone = 0.15;
int baseSpeed = 130;
int now = 0;
int cont = 0;
int signature, x, y, width, height;
float cx, cy, area;

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

int motor_value;
int gyro_value;
const char* serverNamexxx = "http://192.168.1.3/xxx";
const char* serverNamepot = "http://192.168.1.3/pot";

int minimum;
int maximum;
void setup(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 Serial.println(WiFi.localIP());

  Wire.begin();
  mpu.initialize();
  pinMode(IN2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(ENB,OUTPUT);
  pixy.init();
}
void loop(){
  vites();
switch(now) { 
  case 0:
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
gyro_value = map(ax, 0, 17000, minimum,maximum);
motor_value = abs(gyro_value);
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
if (httpGETRequest(serverNamexxx) == "1"){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,0);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,0);
    }
if (httpGETRequest(serverNamexxx) == "2"){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    analogWrite(ENB,motor_value);
    }
if (httpGETRequest(serverNamexxx) == "3"){
    digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,motor_value);
}
if (httpGETRequest(serverNamexxx) == "4"){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,motor_value);
}
if (httpGETRequest(serverNamexxx) == "5"){
    digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    analogWrite(ENB,motor_value);
    }
}       
else {
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,0);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,0);
    }
  }
  break;
 case 1:
  float turn = pixyCheck();
if(turn> -deadZone && turn < deadZone){
 turn = 0;
}
if (turn < 0) {
   digitalWrite(IN2,LOW); 
   digitalWrite(IN1,HIGH);
   analogWrite(ENA,80); 
   digitalWrite(IN4,HIGH);
   digitalWrite(IN3,LOW);
   analogWrite(ENB,170); 

}
else if (turn > 0) {
   digitalWrite(IN2,HIGH); 
   digitalWrite(IN1,LOW);
   analogWrite(ENA,170); 
   digitalWrite(IN4,LOW);
   digitalWrite(IN3,HIGH);
   analogWrite(ENB,80); 
}
else {
   digitalWrite(IN2,HIGH); 
   digitalWrite(IN1,LOW);
   analogWrite(ENA,70); 
   digitalWrite(IN4,HIGH);
   digitalWrite(IN3,LOW);
   analogWrite(ENB,70); 
}
 delay(1);  
 break;
}
void vites(){
  xox = httpGETRequest(serverNamepot);
      if (xox == "X"){
        now = 1;
      }
      else if (xox == "A"){
      minimum = 0;
      maximum = 100;
      now = 0;
     }
      else if (xox == "B"){
      minimum = 0;
      maximum = 150;
      now = 0;
      }
      else if (xox == "C"){
      minimum = 0;
      maximum = 200;
      now = 0;
      }
      else if (xox == "D"){
      minimum = 0;
      maximum = 255;
      now = 0;
      }
      else if (xox == "E"){
      minimum = 45;
      maximum = 255;
      now = 0;
      }
      else if (xox == "F"){
      minimum = 95;
      maximum = 255;
      now = 0;
      }
      else if (xox == "G"){
      minimum = 145;
      maximum = 255;
      now = 0;
      }
      else{
      minimum = 0;
      maximum = 255;
      now = 0;
      }
    }


float pixyCheck() {
 static int i = 0;
 int j;
 uint16_t blocks;
 char buf[32];
 blocks = pixy.getBlocks();

 if(blocks)
 {
   signature = pixy.blocks[0].signature;
   height = pixy.blocks[0].height;
   width = pixy.blocks[0].width;
   x = pixy.blocks[0].x;
   y = pixy.blocks[0].y;
   cx = (x + (width / 2));
   cy = (y + (height / 2));
   cx = mapfloat(cx, 0, 320, -1, 1);
   cy = mapfloat(cy, 0, 200, 1, -1);
   area = width * height;

}
else {
  cont += 1;
if (cont == 100) {
  cont = 0;
  cx = 0;
  }
 }
 return cx;
}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

 String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {

    payload = http.getString();
  }
  // Free resources
  http.end();

  return payload;
}
