#include"chopping-controlled_voltage_regulator.h"
Voltage voltageNow;

/*
method main() is used to successfully debug on Visual Studio
*/
void main() {
	setup();
	loop();
	cout << "Compiled successfully." << endl;
	system("pause");

}
void setup(){
	pinMode(pinCurrentV,INPUT);//voltage input pin
	pinMode(pinButton1,INPUT);//button input pin
	pinMode(pinButton2,INPUT);//start flag input pin
	pinMode(pinLCDD4,OUTPUT);//lcd output
	pinMode(pinLCDD5, OUTPUT);//lcd output
	pinMode(pinLCDD6, OUTPUT);//lcd output
	pinMode(pinLCDD7, OUTPUT);//lcd output
	pinMode(pinSwitch1,OUTPUT);//switch1 output
	pinMode(pinSwitch2,OUTPUT);//switch2 output
}
void loop(){
	voltageNow.checkStatus(voltageNow.voltage_set);//Check the status of the buttons and return current voltage_set
	voltageNow.switchOn(voltageNow.changeFlag(),voltageNow.checkVoltage());//Switch the mosfet on according to the return value of method checkVoltage()
	//Screen cleaner maybe in need here
	voltageNow.printVoltage(voltageNow.voltage_current,voltageNow.voltage_set);//Print the message here
}