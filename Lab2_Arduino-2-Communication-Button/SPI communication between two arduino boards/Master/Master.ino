#include <SPI.h>

/* Arduino Uno R3
  SCK     13
  MO-SI   11
  MI-SO   12
  SS      10
*/

const int slaveSelectPin=10;

void setup() {
  SPI.begin();
  pinMode(slaveSelectPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(slaveSelectPin, LOW);
  delay(1000);

  char test = SPI.transfer('A');
  SPI.transfer('A');

  digitalWrite(slaveSelectPin, HIGH);
  Serial.println( test );
}
