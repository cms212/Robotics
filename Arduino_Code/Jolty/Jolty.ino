// Jolty Sample for Packet Serial
// Copyright (c) 2012 Dimension Engineering LLC
// See license.txt for license details.

#include <Sabertooth.h>

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;
bool commandSent = false;
unsigned long ms;
Sabertooth ST(128); // The Sabertooth is on address 128. We'll name its object ST.
                    // If you've set up your Sabertooth on a different address, of course change
                    // that here. For how to configure address, etc. see the DIP Switch Wizard for
                    //   Sabertooth - http://www.dimensionengineering.com/datasheets/SabertoothDIPWizard/start.htm
                    //   SyRen      - http://www.dimensionengineering.com/datasheets/SyrenDIPWizard/start.htm
                    // Be sure to select Packetized Serial Mode for use with this library.
                    //
                    // On that note, you can use this library for SyRen just as easily.
                    // The diff-drive commands (drive, turn) do not work on a SyRen, of course, but it will respond correctly
                    // if you command motor 1 to do something (ST.motor(1, ...)), just like a Sabertooth.
                    //
                    // In this sample, hardware serial TX connects to S1.
                    // See the SoftwareSerial example in 3.Advanced for how to use other pins.
                                        
void setup()
{
  SabertoothTXPinSerial.begin(9600); // 9600 is the default baud rate for Sabertooth packet serial.
  ST.autobaud(); // Send the autobaud command to the Sabertooth controller(s).
                 // NOTE: *Not all* Sabertooth controllers need this command.
                 //       It doesn't hurt anything, but V2 controllers use an
                 //       EEPROM setting (changeable with the function setBaudRate) to set
                 //       the baud rate instead of detecting with autobaud.
                 //
                 //       If you have a 2x12, 2x25 V2, 2x60 or SyRen 50, you can remove
                 //       the autobaud line and save yourself two seconds of startup delay.
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
    // clear the string:
    if(inputString == "STOP\n"){
      Serial.println("IN STOP\n");
      commandSent = true;
      ms = millis();
      ST.stop();
    }
    else if(inputString == "FORWARD\n"){
      Serial.println("IN FORWARD\n");
      commandSent = true;
      ms = millis();
      driveBothMotors(80);
    }
    else if(inputString == "LEFT\n"){
      Serial.println("IN LEFT\n");
      commandSent = true;
      ms = millis();
      turnLeft();
    }
    else if(inputString == "RIGHT\n"){
      Serial.println("IN RIGHT\n");
      commandSent = true;
      ms = millis();
      turnRight();
    }
    else if(inputString == "1f\n"){
      //ST.motor(1,80);
    }
    else if(inputString == "1b\n"){
      //ST.motor(1,-80);
    }
    else if(inputString == "1s\n"){
      //ST.motor(1,0);
    }
    else if(inputString == "2f\n"){
      //ST.motor(2,80);
    }
    else if(inputString == "2b\n"){
      //ST.motor(2,-80);
    }
    else if(inputString == "2s\n"){
      //ST.motor(2,0);
    }

    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
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
  ST.motor(1, 80);
  ST.motor(2, -80);
}

void turnLeft(){
  ST.motor(1, -80);
  ST.motor(2, 80);
}
