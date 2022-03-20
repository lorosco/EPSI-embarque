#include <Arduino.h>
#define LED_MASK (1<<5)

void led_setup(){
  DDRB |= LED_MASK; //setting bit 5 at 1 in DDRB register (port B)
}

void led_on(){
  PORTB |= LED_MASK; //setting bit 5 at 1 in PORTB register (port B)
}

void led_off(){
  PORTB &=~LED_MASK; //setting bit 5 at 0
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led_setup();//pinMode(LED_BUILTIN,OUTPUT); // pin 13 initialized at 1 to be used as ouput
}

void loop() {
  // put your main code here, to run repeatedly:
  led_on();//digitalWrite(LED_BUILTIN,HIGH); // LED on
  delay(1000); // during 1000ms
  led_off();//digitalWrite(LED_BUILTIN,LOW); // LED off
  delay(1000); // during 1000ms
}