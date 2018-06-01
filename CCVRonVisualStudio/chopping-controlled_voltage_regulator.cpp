#include "chopping-controlled_voltage_regulator.h"
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
	//pinMode(pinButton1,INPUT);//button input pin
	//pinMode(pinButton2,INPUT);//start flag input pin
	pinMode(pinLCDD4,OUTPUT);//lcd output
	pinMode(pinLCDD5, OUTPUT);//lcd output
	pinMode(pinLCDD6, OUTPUT);//lcd output
	pinMode(pinLCDD7, OUTPUT);//lcd output
	pinMode(pinSwitch1,OUTPUT);//switch1 output
	pinMode(pinSwitch2,OUTPUT);//switch2 output

	voltageNow.lcd->begin(16, 2);
	voltageNow.lcd->setCursor(0, 0);
	voltageNow.lcd->print("Set: ");
	voltageNow.lcd->print(voltageNow.voltage_set);
	//voltageNow.lcd->setCursor(0, 1);
	//voltageNow.lcd->print("Current: ");
	//voltageNow.lcd->print(voltageNow.voltage_current);
}
void loop(){
	voltageNow.startRegulating();
}
