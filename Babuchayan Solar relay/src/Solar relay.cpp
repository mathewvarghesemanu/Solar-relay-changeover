#include <Arduino.h>
#include <initialise.h>
#include <constants.h>
#include <main.cpp>
float cutoff=45;
void setup()
 {
pinInitialise();
displayinitialise();
}
void loop() {
  cutoff=(analogRead(potpin)/1025*5);//correct logic

  // print cutoff in display
digitalWrite(relaypin,1);
  float voltage=(analogRead(sensepin))*5/1024;
  if(voltage<cutoff)
  {
    digitalWrite(ledpin,1);
    digitalWrite(relaypin,1);
  }
  else
  {
  digitalWrite(relaypin, 0);
  digitalWrite(ledpin, 0);
}
}
