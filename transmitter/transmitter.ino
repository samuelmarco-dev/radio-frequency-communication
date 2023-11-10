#include <SPI.h>
#include <RK_ASK.h>

#define PUSH_BUTTON 2
#define PORT_TRANSMITTER 12

RH_ASK driver; //~500 bytes por segundo

void setup() {
  driver.init();
  pinMode(PUSH_BUTTON, OUTPUT);
}

void loop() {
  const char *msg = "led-ON";
  const logicalLevelButton = digitalRead(PUSH_BUTTON);

  if(!logicalLevelButton) {
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(100);
  }
}
