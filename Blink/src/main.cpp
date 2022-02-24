#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT); // pin 13 initialized at 1 to be used as ouput
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,HIGH); // LED on
  delay(1000); // during 1000ms
  digitalWrite(LED_BUILTIN,LOW); // LED off
  delay(1000); // during 1000ms
}