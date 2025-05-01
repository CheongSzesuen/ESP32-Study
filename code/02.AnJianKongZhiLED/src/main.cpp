#include <Arduino.h>

int ledPin = 15;
int buttonPin = 35;
int ledLogic=0;
bool status=false;
void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLDOWN);
}
void loop(){
  if(digitalRead(buttonPin)){
    delay(5);
    if (digitalRead(buttonPin)==0 && status==false){
      ledLogic=!ledLogic;
    digitalWrite(ledPin,ledLogic);
    status= !status;
    }else if(digitalRead(buttonPin)==0){
      status=!status;
    }
    
  }
}