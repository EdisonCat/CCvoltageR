#ifndef CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#define CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#include "LiquidCrystal.h"
#include "Arduino.h"

/*
Set up your pins here
*/
const int pinButton1 = 1;
const int pinButton2 = 1;
const int pinFlag = 1;
const int pinCurrentV = 1;
const int pinSwitch1 = 1;
const int pinSwitch2 = 1;
const int pinLCD = 1;



class Voltage {
public:

	bool flag=false;
	int flagValue;
	int time=200;//time for method delay()
	float voltage_set;
	float voltage_current;
	LiquidCrystal lcd1;
	
	Voltage(){
		voltage_set=4.5;
		voltage_current=map(analogRead(pinCurrentV),0,255,0,5);
		//lcd lcd1;
		printVoltage();
	}

	/*
	Check if voltage_current equals to voltage_set
	*/
	int checkVoltage(){
		if(voltage_current>voltage_set){
			return time--;
		}
		else if(voltage_current<voltage_set){
			return time++;
		}
		else
			return time;
	}

	/*
	Switch mosfet on or off
	*/
	void switchOn(bool flag, int time){
		if (flag) {
			digitalWrite(pinSwitch1, HIGH);
			digitalWrite(pinSwitch2, LOW);
			delay(time);
		}
		else
			;
	}



	bool changeFlag(){
		flag = false;
		flagValue = analogRead(pinFlag);
		if (flagValue > 100) {
			flag = true;
		}
		else
			flag = false;
		return 0;
	}


	/*
	Print the message according to your need
	*/
	void printVoltage(){
		//lcd1.print("current voltage:" + voltage_current);
		//lcd1.print("target voltage:"+voltage_set);
	}

	/*
	To check if the buttons are pressed.
	voltage_set varies according to the status of the buttons
	*/
	float checkStatus(float voltage_set){
		if (analogRead(pinButton1)) {
			voltage_set += 0.1;
			return voltage_set;
		}
		else if (analogRead(pinButton2)) {
			voltage_set -= 0.1;
			return voltage_set;
		}
		else
			return voltage_set;
	}
};

#endif