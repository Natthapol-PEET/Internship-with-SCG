#include <SPI.h>

/* Arduino Uno R3
  SCK     13
  MO-SI   11
  MI-SO   12
  SS      10
*/

bool flag = 0;
byte s_recv;

void setup() {
  Serial.begin(115200);
  pinMode(MISO, OUTPUT);

  // SPI Slave mode
  // SPI Control Register (SPCR):
  // Bit 6: SPE - SPI Enable
  // Bit 7: SPIE - SPI Interrupt Enable
  SPCR = (1<<SPE) | (1<<SPIE);   // Enable spi module and interrupt
  sei();
}

// การลงทะเบียนสถานะ SPI (SPSR)
// Bit 7: SPIF - SPI Interrupt Flag
// SPI Data Register (SPDR) 
// SPDR - การลงทะเบียนข้อมูล SPI - การลงทะเบียนข้อมูล SPI 
// คือการอ่าน / เขียนลงทะเบียนที่การถ่ายโอนข้อมูลที่เกิดขึ้นจริง
ISR (SPI_STC_vect) {
  s_recv = SPDR;    // data received from master is stored in SPDR
  flag = 1;
}

void loop() {
  if(flag) {
    SPDR = 'C';   // send data to master
    flag = 0;
    Serial.println(s_recv);
  }
}
