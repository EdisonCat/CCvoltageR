#ifndef CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#define CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#include "LiquidCrystal.h"
#include "Arduino.h"
#include "chopping-controlled_voltage_regulator.h"
#include <sstream>

/*
Set up your pins here
*/
const int pinButton1 = 1;
const int pinButton2 = 1;
const int pinFlag = 1;
const int pinCurrentV = 1;
const int pinSwitch1 = 1;
const int pinSwitch2 = 1;
const int pinLCDVCC = 1;
const int pinLCDGND = 1;
const int pinLCDE = 1;
const int pinLCDRS = 1;
const int pinLCDRW = 1;
const int pinLCDD7 = 1;
const int pinLCDD6 = 1;
const int pinLCDD5 = 1;
const int pinLCDD4 = 1;




class Voltage {
public:

	bool flag=false;
	int flagValue;
	int time=200;//time for method delay()
	float voltage_set;
	float voltage_current;
	LiquidCrystal *lcd=new LiquidCrystal(pinLCDRS,pinLCDE,pinLCDD4,pinLCDD5,pinLCDD6,pinLCDD7);
	
	Voltage(){
		voltage_set=4.5;
		voltage_current=map(analogRead(pinCurrentV),0,255,0,5);
		printVoltage(voltage_current,voltage_set);
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
	void printVoltage(float voltage_current, float voltage_set){
		ostringstream ossCurrent;
		ostringstream ossSet;
		ossCurrent << voltage_current;
		ossSet << voltage_set;
		string tempCurrent(ossCurrent.str());
		string tempSet(ossSet.str());
		lcd->print("Current Voltage:"+tempCurrent+" ");
		lcd->print("Voltage Set:" +tempSet);
	}

	/*
	To check if the buttons are pressed.
	voltage_set varies according to the status of the buttons
	*/
	float checkStatus(float voltage_set){
		if (digitalRead(pinButton1)) {
			voltage_set += 0.1;
			delay(200);//In case errors appear
			return voltage_set;
		}
		else if (digitalRead(pinButton2)) {
			voltage_set -= 0.1;
			delay(200);
			return voltage_set;
		}
		else
			return voltage_set;
	}
};
#endif