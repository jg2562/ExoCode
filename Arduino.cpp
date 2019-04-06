#include "Arduino.hpp"
#ifndef ARDUINO
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


Adafruit_BNO055::Adafruit_BNO055(int, int, unsigned int, int, i2c_pins, int, int, int){}
bool Adafruit_BNO055::begin(){return true;}
void Adafruit_BNO055::getCalibration(uint8_t*, uint8_t*, uint8_t*, uint8_t*){}
bool Adafruit_BNO055::isFullyCalibrated(){return true;}
void Adafruit_BNO055::getEvent(sensors_event_t* event){
  event->orientation.x = 0;
  event->orientation.y = 0;
  event->orientation.z = 0;
}

void delay(double time){usleep(1000 * time);}
double max(double a, double b){return (a>b) ? a : b;}
double min(double a, double b){return (a<b) ? a : b;}
unsigned long int millis(){
  struct timeval tv;

  gettimeofday(&tv, NULL);

  unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;

  return millisecondsSinceEpoch;
}
void analogReadResolution(int){}
void analogWriteResolution(int){}
#ifndef ROS
void pinMode(int, int){}
int analogRead(int){return 0;}
void analogWrite(int, int){}
int digitalRead(int){return 0;}
void digitalWrite(int, int){}

SoftwareSerial Serial = SoftwareSerial(0,0);

SoftwareSerial::SoftwareSerial(int, int){
  readStr = NULL;
  strLen = -1;
  charIndex = 0;
}
bool SoftwareSerial::begin(int){return true;}
void SoftwareSerial::write(char str){
  printf("%c", str);
}
void SoftwareSerial::write(const char* str){
  printf("%s", str);
}

void SoftwareSerial::print(const char* str){
  printf("%s", str);
}

void SoftwareSerial::print(double val){
  printf("%lf", val);
}

void SoftwareSerial::println(){
  printf("\n");
}

void SoftwareSerial::println(const char* str){
  printf("%s\n", str);
}

void SoftwareSerial::println(double val){
  printf("%lf\n", val);
}

void SoftwareSerial::setReadString(const char* str){
  readStr = str;
  strLen = 0;
  while (readStr[strLen] != '\0'){strLen++;}
  charIndex = 0;
}

int SoftwareSerial::read(){
  if (strLen <= 0){
    return -1;
  }

  int val = readStr[charIndex++];
  if (charIndex >= strLen){
    readStr = NULL;
    strLen = -1;
    charIndex = 0;
  }
  return val;
}

int SoftwareSerial::available(){return strLen;}

#endif
#endif
