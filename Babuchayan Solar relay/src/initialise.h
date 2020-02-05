#include <Arduino.h>

short int sensepin=4;//check it analog
short int relaypin=8;
short int ledpin=5;
short int potpin=6;//check it analog


void pinInitialise()
{
pinMode(potpin,INPUT_PULLUP);
  pinMode(sensepin, INPUT_PULLUP);
  pinMode(relaypin, OUTPUT);
  digitalWrite(relaypin, LOW);
}
void displayinitialise()
{
//init display i2c
}
