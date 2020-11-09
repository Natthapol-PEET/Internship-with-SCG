#include <SPI.h>

void setup (void) {
   Serial.begin(115200);
   pinMode(MISO, OUTPUT);
   SPCR |= _BV(SPE);
   // คำสั่งกำหนด และสร้างอินเตอร์รัพท์
   SPI.attachInterrupt();
}

byte c;
volatile boolean process=false;

ISR(SPI_STC_vect) // SPI interrupt routine 
{ 
   c = SPDR; // read byte from SPI Data Register
   process = true;
}

void loop (void) {
  if(process) {
    Serial.println((char)c);
    process = false;
   }
}
