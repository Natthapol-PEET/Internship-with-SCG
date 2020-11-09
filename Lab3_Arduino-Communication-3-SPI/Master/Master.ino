#include <SPI.h>
#include <SPIExtension.h>

const uint8_t PIN_CS = 10;
const uint8_t NUM_DEVICE = 2;
SPIExtension<PIN_CS, NUM_DEVICE> spi;

uint8_t send_data[NUM_DEVICE] = {'C', 'B'};

void setup()
{
    Serial.begin(115200);
    SPI.begin();
    spi.attatch(SPI);
}

void loop()
{
  send_data[1] = 'A';
  send_data[0] = 'B';
  
  spi.transfer(send_data);
  Serial.print("Slave-1 -> "); Serial.print(char(spi.data(1)));
  Serial.print("\tSlave-2 -> "); Serial.print(char(spi.data(0)));
  Serial.println();
}
