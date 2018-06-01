#include "chopping-controlled_voltage_regulator.h"
Voltage voltageNow;

void setup(){
  pinMode(pinCurrentV,INPUT);//voltage input pin
  Serial.begin(9600);
  pinMode(pinLCDD4,OUTPUT);//lcd output
  pinMode(pinLCDD5, OUTPUT);//lcd output
  pinMode(pinLCDD6, OUTPUT);//lcd output
  pinMode(pinLCDD7, OUTPUT);//lcd output
  pinMode(pinSwitch1,OUTPUT);//switch1 output
  pinMode(pinSwitch2,OUTPUT);//switch2 output

  voltageNow.initiateLCD();
  
}
void loop(){
  voltageNow.startRegulating();
  Serial.println(voltageNow.openTime);
}
