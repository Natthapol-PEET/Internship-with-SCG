#include <SPI.h>

/* Arduino MEGA 2560
  SCK     52
  MO-SI   51
  MI-SO   50
  SS      53
*/

#define b1  8
#define b2  9
#define b3  10

bool sb1, sb2, sb3;
bool lockb1=false, lockb2=false, lockb3=false;

void setup (void) {
    // กำหนดอัตรารับส่งข้อมูลเป็น 115200 สำหรับ usart
   Serial.begin(115200); //set baud rate to 115200 for usart
   digitalWrite(SS, HIGH); // disable Slave Select
   // ใช้งาน SPI.begin() มีผลให้ SCK, MOSI และ SS เป็นเอาต์พุต และ MISO เป็นอินพุต
   SPI.begin();
   // เลือกอัตรารับส่งข้อมูล (Max 16 MHz)
   SPI.setClockDivider(SPI_CLOCK_DIV8); // divide the clock by 8 (SCK)

   pinMode(b1, INPUT_PULLUP);
   pinMode(b2, INPUT_PULLUP);
   pinMode(b3, INPUT_PULLUP);
}
 
void loop (void) {
  sb1 = digitalRead(b1);  // Active Low
  sb2 = digitalRead(b2);
  sb3 = digitalRead(b3);

  if(!sb1 && lockb1==false) {
    send_char('A');
    lockb1 = true;
  }
  if(sb1) {
    lockb1 = false;
  }

  if(!sb2 && lockb2==false) {
    send_char('B');
    lockb2 = true;
  }
  if(sb2) {
    lockb2 = false;
  }

  if(!sb3 && lockb3==false) {
    send_char('C');
    lockb3 = true;
  }
  if(sb3) {
    lockb3 = false;
  }
}

void send_char(char *c) {
  digitalWrite(SS, LOW);
  SPI.transfer(c);
  digitalWrite(SS, HIGH);
}
