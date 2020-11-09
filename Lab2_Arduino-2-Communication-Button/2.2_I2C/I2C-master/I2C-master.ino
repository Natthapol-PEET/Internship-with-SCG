#include <Wire.h>

#define b1	10
#define b2	9
#define b3	8

bool lockb1 = false;
bool lockb2 = false;
bool lockb3 = false;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
}

void SendvalueToSlave(char c) {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(c);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}

void loop() {
  bool sb1 = digitalRead(b1);
  bool sb2 = digitalRead(b2);
  bool sb3 = digitalRead(b3);

  if(!sb1 && lockb1==false) {
    SendvalueToSlave('A');
    lockb1 = true;
  }
  if(sb1) {
  	lockb1 = false;
  }
  
  if(!sb2 && lockb2==false) {
    SendvalueToSlave('B');
    lockb2 = true;
  }
  if(sb2) {
  	lockb2 = false;
  }
  
  Serial.println(lockb2);
  
  if(!sb3 && lockb3==false) {
    SendvalueToSlave('C');
    lockb3 = true;
  }
  if(sb3) {
  	lockb3 = false;
  }

}