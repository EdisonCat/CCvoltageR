/*
This is not the real Arduino.cpp, it is used to ensure that you can successfully debug on Visual Studio
*/
#include"Arduino.h"

void pinMode(int pin, bool status) {
}
void digitalWrite(int pin, bool status) {

}
int digitalRead(int pin) {
	return 0;
}
int analogRead(int pin) {
	return 0;
}
void analogWrite(int pin, bool status) {

}
void delay(int time) {

}
void delayMicroseconds(int time) {

}
float map(int value,int min1,int max1, int min2, int max2) {
	return value / 255 * 5;
}