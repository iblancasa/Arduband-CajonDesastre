#include <XBee.h>

XBee xbee;
Rx64Response rx64 = Rx64Response();
void setup() {
  // put your setup code here, to run once:
  xbee = XBee();
  Serial.begin(9600);
  xbee.setSerial(Serial);
}
uint8_t payload[] = { '~','A','~' };
XBeeAddress64 segunda = XBeeAddress64(0x13A200, 0x40A09C69);
//ZBTxRequest peti = ZBTxRequest(segunda, payload, sizeof(payload));

XBeeAddress64 primera = XBeeAddress64(0x13A200, 0x4079E3ED);

XBeeAddress64 tercera = XBeeAddress64(0x13A200, 0x40A4D173);
//XBeeAddress64 addr64 = XBeeAddress64(0x0, 0xffff);
 
/**
XBeeAddress64 &addr64 = addr64
uint16_t addr16
uint8_t broadcastRadius = 1 / 0
uint8_t option ? 0
uint8_t *payload = payload
uint8_t payloadLength = sizeof(payload) 
uint8_t frameId  = 0
*/

//XBeeAddress64 addr64=XBeeAddress64(0x00000000, 0x0000ffff);
//ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));

uint16_t addr16=0xffff;
uint8_t broadcastradius=0;
uint8_t option=0;
uint8_t frameid=0;

ZBTxRequest primeraS=ZBTxRequest(primera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);


ZBTxRequest segundaS=ZBTxRequest(segunda,addr16,broadcastradius,option,payload,sizeof(payload),frameid);


ZBTxRequest terceraS=ZBTxRequest(tercera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);
long tiempo;
int i=0;
bool a = false;

void loop() {
  // put your main code here, to run repeatedly:

if(millis()-tiempo>500){
 if(a)
   xbee.send(primeraS);
 else
   xbee.send(segundaS);
 a=!a;
 tiempo=millis();
 }
 
 
}
