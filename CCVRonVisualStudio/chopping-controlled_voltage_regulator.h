#ifndef CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#define CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#include "LiquidCrystal.h"
#include "Arduino.h"



class voltage {
public:

	//bool flag=false; not used
	int time=200;//time for method delay()
	float voltage_set;
	float voltage_current;
	LiquidCrystal lcd1;
	
	voltage(){
		voltage_set=4.5;
		voltage_current=map(analogRead(pin),0,255,0,5);
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
	void switchOn(int time){
		digitalWrite(pin,HIGH);
		digitalWrite(pin,LOW);
		delay(time);
	}

	/*
	This method is not used

	void changeFlag(){
		switch(flag){
			case(true):flag=false;break;
			default:flag=true;
		}
	}
	*/

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
		if (analogRead(pin)) {
			voltage_set += 0.1;
			return voltage_set;
		}
		else
			return voltage_set;
	}
};

#endif