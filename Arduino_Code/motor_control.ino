#include <SoftwareSerial.h>

SoftwareSerial Sabertooth(11,10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Sabertooth.begin(9600);
  delay(1000);
  Sabertooth.write(64);
  Sabertooth.write(192);
}

void loop() {
  // put your main code here, to run repeatedly:
  Sabertooth.write(64+32);
  Sabertooth.write(192+32);
  Serial.println("Sent Forward");
  delay(2000);

  Sabertooth.write(64-32);
  Sabertooth.write(192-32);
  Serial.println("Sent backward");

  delay(2000);

  Sabertooth.write(64);
  Sabertooth.write(192);
  Serial.println("Sent Stop");
  delay(2000);
}
