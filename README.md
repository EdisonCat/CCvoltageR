# Chopping-controlled Voltage Regulator
## Description
An Arduino-based Chopping-controlled Voltage Regulator can be used to regulate voltage with the control signal produced by Arduino.
And this is a C++ library for Arduino-based Chopping-controlled Voltage Regulator.
## Usage
### On Arduino IDE
Download or clone the library and copy folder CCVRonArduinoIDE/chopping-controlled_voltage_regulator to Arduino/Libraries, and include the header file in your .ino source code.
Then create a new object of class voltage, and use the methods in the class.
### On Visual Studio
Download or clone the library and copy folder CCVRonVisualStudio to your Visual Studio project.
Then start your development.
### Connection of voltage regulator
Find the information of the pins of LCD Keypad Shield in header file. TX and RX pins of two Arduinos will be connected with each other. For example, Arduino 1 generates control signal and Arduino 2 displays the information. The output of the regulator will be sent to both Arduinos, and the TX pin of Arduino 2 should be connected with the RX pin of Arduino 1 to tell the targeting voltage of the output, GNDs of both Arduinos should be connected with each other.