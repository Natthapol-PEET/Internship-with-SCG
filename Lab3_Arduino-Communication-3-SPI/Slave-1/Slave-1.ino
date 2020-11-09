#include <SPI.h>

/* Arduino Uno R3
  SCK     13
  MO-SI   11
  MI-SO   12
  SS      10
*/

void setup() {
  Serial.begin(115200);
  pinMode(MISO, OUTPUT);

  SPCR = (1<<SPE) | (1<<SPIE);
  sei();
}

char c;
bool flag = 0;

ISR (SPI_STC_vect) {
  c = SPDR;
  flag = 1;
}

void loop() {
  if(flag) {
    if(c == 'A') { SPDR = 'a'; }
    else { SPDR = c+2; }
    flag = 0;
  }
}
