#include <Arduino.h>
int LED_Pin = 12;

void setup(){
  pinMode(LED_Pin, OUTPUT);
}
void loop(){
for(int i=0;i<256;i++){
  analogWrite(LED_Pin, i);
  delay(10);
}
for(int i=255;i>=0;i--){
  analogWrite(LED_Pin, i);
  delay(10);
  }
}