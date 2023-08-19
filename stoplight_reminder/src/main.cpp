#include <Arduino.h>

#define LED_BUILTIN PC13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,
               HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);        // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // wait for a second
}