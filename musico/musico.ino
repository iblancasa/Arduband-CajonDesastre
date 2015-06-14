#include <XBee.h>
#include <TimerOne.h>


XBee xbee;
Rx64Response rx64 = Rx64Response();
const int motor = 13; 

void setup() {
  xbee = XBee();
  Serial.begin(9600);
  xbee.setSerial(Serial);
  
  pinMode(motor, OUTPUT);
  Timer1.initialize(100);
  
  Timer1.attachInterrupt(vibrar);
  
}
bool entrar = false;

unsigned long frecuencia = 500;
int recibido;
unsigned long antes=millis();

void vibrar(void){
  
  if(millis() - antes > frecuencia ){
      digitalWrite(motor, HIGH);
      antes = millis();
  }
  
  else if(millis() - antes > 50){
    digitalWrite(motor, LOW);
  }
 
}



void loop() {
  
   if(Serial.available()>0){
    recibido = Serial.read();
    

    if(recibido == 0x0){
      entrar=false;
    }
    
    else if(entrar){
        float au1= (float)recibido/(float)60;
        float au2 = (float)1000 / (float)au1;
        frecuencia = (unsigned long) au2; 
        entrar = false;
        Serial.read();
    }
   
    else if(recibido == 0x7E ){
      entrar=true;
    }
  }
  
  Serial.println(millis() - antes);    
}
