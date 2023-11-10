#include <SPI.h>
#include <RK_ASK.h>

#define LED 4 
#define PORT_RECEIVER 12

RH_ASK driver; //~500 bytes por segundo

String infoTransmitter = "";
int statusLED = false;

void setup() {
  driver.init();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, statusLED);
}

void loop() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN]; 
  uint8_t buflen = sizeof(buf);     

  if (driver.recv(buf, &buflen)) {  
    infoTransmitter = "";                                                

    for (int index = 0; index < buflen; index++) { 
      infoTransmitter += (char)buf[index];              
    }
    
    verifyString();
  }
}

void verifyString () {
  if ((infoTransmitter.equals("led-ON")) && !statusLED) {  
      statusLED = !statusLED;                                 
      digitalWrite(pinoLed, statusLED);
    }                                        
    if ((infoTransmitter.equals("led-ON")) && statusLED) { 
        statusLED = false;                                
        digitalWrite(pinoLed, statusLED);                   
    }
    else return;
}
