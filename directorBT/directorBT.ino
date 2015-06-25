#include <SoftwareSerial.h>// import the serial library
#include <XBee.h>
#include "TimerOne.h"

SoftwareSerial Genotronex(10, 11); // RX, TX
int ledpin=7; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer


XBee xbee;



bool leer=true;



void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  Serial.begin(9600);
  while (!Serial) {  }
  
  xbee.setSerial(Serial);
  
  
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin, HIGH);
  
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
long periodo=1000;
 
void Envio(void){
    if(millis()-tiempo>periodo){
    // if(a)
       xbee.send(primeraS);
  //   else
         xbee.send(segundaS);
    //   a=!a;
       tiempo=millis();
     }
}



void loop() {
  
  
 
  if(leer){ // put your main code here, to run repeatedly:
   if (Genotronex.available()){
     leer=false;
     tempo = Genotronex.read(); 
     long aux = (long)tempo/(long)60;
     periodo = 1000/aux-20;
     
     
     float au1= (float)tempo/(float)60;
     float au2 = (float)1000 / (float)au1;
     periodo= (long) au2; 
     
     digitalWrite(ledpin, LOW);
       Timer1.initialize(500); 
      
  Timer1.attachInterrupt(Envio);
     Serial.println("----------------------------------------------------------------------------");
     Serial.println(tempo);
     Serial.println(au1);
     Serial.println(au2);
     Serial.println(periodo);
     
     Serial.print(au1); Serial.print(" = "); Serial.print(tempo);Serial.println(" / +60");

     Serial.println("----------------------------------------------------------------------------");
  }
  }
}
