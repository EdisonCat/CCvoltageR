/*
This is not the real Arduino.h, it is used to ensure that you can successfully debug on Visual Studio
*/
#ifndef ARDUINO_H
#define ARDUINO_H
void pinMode(int, bool);
void digitalWrite(int, bool);
int digitalRead(int);
int analogRead(int);
void analogWrite(int, bool);
void delay(int);
float map(int,int,int,int,int);
void setup();
void loop();
const bool INPUT = false;
const bool OUTPUT = true;
const bool HIGH = true;
const bool LOW = false;
#endif