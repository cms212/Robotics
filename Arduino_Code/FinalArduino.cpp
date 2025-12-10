#include <Sabertooth.h>

String inputString = "";      
bool stringComplete = false;
bool commandSent = false;
unsigned long ms;
Sabertooth ST(128); 
                                        
void setup()
{
  SabertoothTXPinSerial.begin(9600); 
  ST.autobaud(); 
  Serial.begin(9600);
  inputString.reserve(200);
}


void loop()
{
  if(commandSent && ((millis() - ms) >= 2000)){
    ST.stop();
    commandSent = false;
  }
  if (stringComplete) {
    if(inputString == "STOP\n"){
      commandSent = true;
      ms = millis();
      ST.stop();
    }
    else if(inputString == "FORWARD\n"){
      commandSent = true;
      ms = millis();
      driveBothMotors(40);
    }
    else if(inputString == "LEFT\n"){
      commandSent = true;
      ms = millis();
      turnLeft();
    }
    else if(inputString == "RIGHT\n"){
      commandSent = true;
      ms = millis();
      turnRight();
    }
    else if(inputString == "LEFT FAST\n"){
      commandSent = true;
      ms = millis();
      turnLeftFast();
    }
    else if(inputString == "RIGHT FAST\n"){
      commandSent = true;
      ms = millis();
      turnRightFast();
    }
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void driveBothMotors(int power){
  ST.motor(1,power);
  ST.motor(2, power);
}

void turnRight(){
  ST.motor(1, 50);
  ST.motor(2, -50);
}

void turnLeft(){
  ST.motor(1, -50);
  ST.motor(2, 50);
}

void turnRightFast(){
  ST.motor(1, 80);
  ST.motor(2, -80);
}

void turnLeftFast(){
  ST.motor(1, -80);
  ST.motor(2, 80);
}