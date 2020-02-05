#include <Arduino.h>

#include "initialise.h"


#include <main.cpp>
float cutoff = 45;
void setup()
{
  Serial.begin(9600);
  pinInitialise();
  displayinitialise();
}
void loop() {
  cutoff=readCutoff();
  showDisplay("Voltage Cutoff :" + String(cutoff), 0, 0);
  if (voltage < cutoff)
  {
    digitalWrite(ledpin, 1);
    digitalWrite(relaypin, 1);
  }
  else
  {
    digitalWrite(relaypin, 0);
    digitalWrite(ledpin, 0);
  }
