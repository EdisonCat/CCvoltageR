#ifndef CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#define CHOPPING_CONTROLLED_VOLTAGE_REGULATOR_H
#include "LiquidCrystal.h"
#include "Arduino.h"

/*
Set up your pins here
*/

const int pinFlag = 10;
const int pinCurrentV = A5;
const int pinSwitch1 = 8;
const int pinSwitch2 = 9;
const int pinLCDVCC = 1;
const int pinLCDGND = 1;
const int pinLCDE = 11;
const int pinLCDRS = 12;
const int pinLCDRW = 1;
const int pinLCDD7 = 2;
const int pinLCDD6 = 3;
const int pinLCDD5 = 4;
const int pinLCDD4 = 5;
const int btnNone = 5;
const int btnSelect = 4;
const int btnLeft = 3;
const int btnDown = 2;
const int btnUp = 1;
const int btnRight = 0;


class Voltage {
public:

	bool flag = false;
	int flagValue;
	int openTime = 1000;//time for method delay() or delayMicroseconds()
	float voltage_set;
	float voltage_current;
	int button;
	int lcd_key;
	LiquidCrystal *lcd = new LiquidCrystal(pinLCDRS, pinLCDE, pinLCDD4, pinLCDD5, pinLCDD6, pinLCDD7);

	Voltage() {
		voltage_set = 4.5;
		voltage_current = remap(analogRead(pinCurrentV), 1023, 5);
	}

	/*
	Check if voltage_current equals to voltage_set
	*/
	int checkVoltage() {
		if (this->voltage_current > this->voltage_set) {
			this->openTime--;
			return this->openTime;
		}
		else if (this->voltage_current < this->voltage_set) {
			this->openTime++;
			return this->openTime++;
		}
		else
			return this->openTime;
	}

	/*
	Switch mosfet on or off
	*/
	void switchOn(bool flag, int openTime) {
		if (flag) {
			/*
			First half wave
			*/
			digitalWrite(pinSwitch1, HIGH);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, HIGH);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, HIGH);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, HIGH);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, HIGH);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);
			/*
			Second half wave
			*/
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, HIGH);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, HIGH);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, HIGH);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, HIGH);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);

			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, HIGH);
			delayMicroseconds(openTime);
			digitalWrite(pinSwitch1, LOW);
			digitalWrite(pinSwitch2, LOW);
			delayMicroseconds(openTime);
		}
		else
			;
	}



	bool changeFlag() {
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
	To check if the buttons are pressed.
	voltage_set varies according to the status of the buttons
	*/
	int readButton() {
		button = analogRead(0);
		if (button > 1000) return btnNone;
		if (button < 50)   return btnNone;
		if (button < 250)  return btnUp;
		if (button < 350)  return btnDown;
		if (button < 650)  return btnNone;
		if (button < 850)  return btnNone;
		return btnNone;
	}
	void checkAndPrint(float voltage_set, float voltage_current) {

		
		lcd->setCursor(5, 0);
		this->lcd_key = this->readButton();

		switch (this->lcd_key) {               
		case btnUp: {
			this->voltage_set += 0.1;
			if (this->voltage_set > 220) {
				lcd->setCursor(5, 0);
				lcd->print("      ");
				lcd->setCursor(5, 0);
				lcd->print("limit");
				this->voltage_set -= 0.1;
				delay(500);
				lcd->setCursor(5, 0);
				lcd->print("     ");
				lcd->setCursor(5, 0);
				lcd->print(this->voltage_set);
			}
			else {
				lcd->print(this->voltage_set);  
			}
			break;
		}
		case btnDown: {
			this->voltage_set -= 0.1;
			if (this->voltage_set < 0) {
				lcd->print("limit");
				this->voltage_set += 0.1;
				delay(500);
				lcd->setCursor(5, 0);
				lcd->print("     ");
				lcd->setCursor(5, 0);
				lcd->print(this->voltage_set);
			}
			else {
				lcd->print(this->voltage_set);  
			}
			break;
		}
		}
		this->voltage_current = remap(analogRead(pinCurrentV), 1023, 5);
		lcd->setCursor(9, 1);
		lcd->print(this->voltage_current);

		delay(100);
	}

	float remap(float analogData, float originalMax, float afterMax) {
		float result = analogData * afterMax / originalMax;
		return result;
	}

	void startRegulating() {
		this->checkAndPrint(this->voltage_set, this->voltage_current);//Check the status of the buttons and return current voltage_set
		this->switchOn(this->changeFlag(), this->checkVoltage());//Switch the mosfet on according to the return value of method checkVoltage()
	}

	void initiateLCD() {
		this->lcd->begin(16, 2);
		this->lcd->setCursor(0, 0);
		this->lcd->print("Set: ");
		this->lcd->print(this->voltage_set);
		this->lcd->setCursor(0, 1);
		this->lcd->print("Current: ");
		this->lcd->print(this->voltage_current);
	}

};
#endif