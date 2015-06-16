#include <XBee.h>
#include <TimerOne.h>


XBee xbee;
Rx64Response rx64 = Rx64Response();
const int motor = 2; 

void setup() {
  xbee = XBee();
  Serial.begin(9600);
  xbee.setSerial(Serial);
  
  pinMode(motor, OUTPUT);
  Timer1.initialize(500);
  
  Timer1.attachInterrupt(vibrar);
  
}


bool entrar = false;

 long frecuencia = 1000;
int recibido;
 long antes=millis();

void vibrar(void){
  
  if(millis() - antes > frecuencia ){
      digitalWrite(motor, HIGH);
      antes = millis();
  }
  
  else if(millis() - antes > 300){
    digitalWrite(motor, LOW);
  } 
}



void loop() {
  
   if(Serial.available()>=21){
     while(Serial.available()>0){
        recibido = Serial.read();
        
      //  Serial.println(recibido,HEX);
        
         if(entrar){
              float au1= (float)recibido/(float)60;
              float au2 = (float)1000 / (float)au1;
              frecuencia = (long) au2; 
             Serial.println(recibido,HEX);
          
         /*      Serial.println(au1);
                Serial.println(au2);
              Serial.println(frecuencia);
              Serial.println("======================================================");
           */  
           Serial.read();
           entrar = false;
           digitalWrite(motor, HIGH);
           antes = millis();
          }
         
          else if(recibido == 0x7F ){
            entrar=true;
          }
     }
    //  noInterrupts();
   


   //interrupts();
  }


/**
 
   if(Serial.available()>0){
 
    //  noInterrupts();
    recibido = Serial.read();
    Serial.println(recibido);

    if(entrar){
        float au1= (float)recibido/(float)60;
        float au2 = (float)1000 / (float)au1;
        frecuencia = (long) au2; 
      // Serial.println(recibido,HEX);
    
   /*      Serial.println(au1);
          Serial.println(au2);
        Serial.println(frecuencia);
        Serial.println("======================================================");
       /* entrar = false;
        digitalWrite(motor, HIGH);
         antes = millis();
    }
   
    else if(recibido == 0x7F ){
      entrar=true;
    }
   //interrupts();
  }
*/

}
