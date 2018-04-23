#ifndef CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#define CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#include "lcd.h"
#include "Arduino.h"



class voltage{
public:

	bool change_flag=false;
	int time=200;
	float voltage_set;
	float voltage_current;

	voltage(){
		voltage_set=4.5;
		voltage_current=map(analogRead(),0,255,0,5);
		printVoltage();
	}
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
	void switchOn(){
		digitalWrite(,HIGH);
		digitalWrite(,LOW);
		delay(time);

	}
	
	void changeFlag(){
		switch(change_flag){
			case(true):change_flag=false;break;
			default:change_flag=true;
		}
	}

	void printVoltage(){
		lcd.print("current voltage:"voltage_current);
		lcd.print("target voltage:"voltage_set);
	}

	void checkStatus(){
		if(analogRead()){

		}
	}
}





#endif