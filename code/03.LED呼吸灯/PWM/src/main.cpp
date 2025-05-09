#include <Arduino.h>
#define FREQ 2000
#define CHANNEL   0
#define RESOLUTION 8
#define LED 12


void setup(){
  ledcSetup(CHANNEL, FREQ, RESOLUTION);
  ledcAttachPin(LED ,CHANNEL);
}
void loop(){
  for(int i=0;i<pow(2, RESOLUTION);i++){
    ledcWrite(CHANNEL, i);
    delay(10);
  }
  for(int i=pow(2, RESOLUTION)-1;i>=0;i--){
    ledcWrite(CHANNEL, i);
    delay(10);
  }
}