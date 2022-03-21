#include <Arduino.h>
#define LED_MASK (1<<5)
#define CS_PRESCALER_1024 ( (1 << CS10) | (1 << CS12) )
#define TICKS_IN_S 15625

void led_setup(){
  DDRB |= LED_MASK; //setting bit 5 at 1 in DDRB register (port B)
}

void led_on(){
  PORTB |= LED_MASK; //setting bit 5 at 1 in PORTB register (port B)
}

void led_off(){
  PORTB &=~LED_MASK; //setting bit 5 at 0
}

void led_toggle(){
  PINB = LED_MASK; // change la valeur du PORTB à la position de LED_MASK
}

void timer_setup(){
  TCCR1A = 0;
  TCCR1B = CS_PRESCALER_1024 | (1 << WGM12);
  OCR1A = TICKS_IN_S;
  //OCR1AL = (uint8_t) (15625 & 0xFF);
  //OCR1AH = (uint8_t) (15625 & (0xFF << 8)) >> 8;
  TIMSK1 = (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect){
  led_toggle();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led_setup();//pinMode(LED_BUILTIN,OUTPUT); // pin 13 initialized at 1 to be used as ouput
  timer_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  led_toggle();//led_on();//digitalWrite(LED_BUILTIN,HIGH); // LED on
  delay(1000); // during 1000ms
  //led_off();//digitalWrite(LED_BUILTIN,LOW); // LED off
  //delay(1000); // during 1000ms
}