#include <Display.h>
#include <HelligkeitsSensor.h>
#include <LED.h>

LED lampe(8);
//Display anzeige;
HelligkeitsSensor sensor( A3 );
void setup() {
  // put your setup code here, to run once:
  //anzeige.initialisiere();
}

void loop() {
  int helligkeit = sensor.missHelligkeit();
  //anzeige.schreibeText( helligkeit );
  if( helligkeit < 50 ){
    lampe.einschalten();
  }
  else{
    lampe.ausschalten();
  }
  delay(1000);
  //anzeige.loescheText();
  // put your main code here, to run repeatedly:
  
}
