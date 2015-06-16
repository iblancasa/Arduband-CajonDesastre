#include <SoftwareSerial.h> 
#include <XBee.h>
#include "TimerOne.h"

XBee xbee;

//SoftwareSerial BT(10,11);
 
void setup()
{
  Timer1.initialize(500); 
  Timer1.attachInterrupt(Envio);
  xbee = XBee();

  Serial.begin(9600);
  Serial1.begin(9600);
  xbee.setSerial(Serial1);
  
  while (!Serial1) {  }
  //BT.begin(9600); 
  
}

uint8_t payload[] = { 0x7F,'<',0x7F };

XBeeAddress64 primera = XBeeAddress64(0x0013A200, 0x4079E3ED);
XBeeAddress64 segunda = XBeeAddress64(0x0013A200, 0x40A09C69);
XBeeAddress64 tercera = XBeeAddress64(0x0013A200, 0x40A4D173);

uint16_t addr16=0xffff;
uint8_t broadcastradius=0;
uint8_t option=0;
uint8_t frameid=0;

ZBTxRequest primeraS=ZBTxRequest(primera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);
ZBTxRequest segundaS=ZBTxRequest(segunda,addr16,broadcastradius,option,payload,sizeof(payload),frameid);
ZBTxRequest terceraS=ZBTxRequest(tercera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);


long tiempo=0;
int i=0;
bool a = false;
char recibido;

uint8_t tempo='<';
unsigned long periodo=4000;
 
void Envio(void){
    if(millis()-tiempo>periodo){
     if(a)
       xbee.send(primeraS);
     else
         xbee.send(segundaS);
       a=!a;
       tiempo=millis();
       Serial.println("ENVIADO");
     }
}
 

void loop()
{ 
 // noInterrupts();
/*  if(BT.available()>0)
  {


 

   recibido = BT.read();
   Serial.println(recibido);
 /*  tempo = (uint8_t) recibido;
    
    
    float aux = (float)tempo/60;
    periodo=(long)1000/aux;
    payload[1] = tempo;
    
     primeraS=ZBTxRequest(primera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);
     segundaS=ZBTxRequest(segunda,addr16,broadcastradius,option,payload,sizeof(payload),frameid);
   terceraS=ZBTxRequest(tercera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);

    Serial.println(periodo);
*/
//  }
  //interrupts();
}
