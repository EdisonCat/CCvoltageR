#include"chopping-controlled_voltage_regulator.h"
voltage voltageNow;

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
	pinMode(pin,INPUT);//voltage input pin
	pinMode(pin,INPUT);//button input pin
	pinMode(pin,INPUT);//start flag input pin
	pinMode(pin,OUTPUT);//lcd output
	pinMode(pin,OUTPUT);//switch1 output
	pinMode(pin,OUTPUT);//switch2 output
}
void loop(){
	voltageNow.checkStatus(voltageNow.voltage_set);//Check the status of the buttons and return current voltage_set
	voltageNow.switchOn(voltageNow.checkVoltage());//Switch the mosfet on according to the return value of method checkVoltage()
	//Screen cleaner maybe in need here
	voltageNow.printVoltage();//Print the message here
}