#include <Kabel.h>
#include <Lautsprecher.h>
#include <LED.h>

Lautsprecher lautsprecher( 9 );
Kabel bruecke( 7 );
LED lampe( 8 );
void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  if( bruecke.schaltkreisGeoeffnet() ){
      lampe.ausschalten();
      lautsprecher.spieleWiederholung( NOTE_F4, 500, 2 );
  }
  else{
     lampe.einschalten();
  }
  // put your main code here, to run repeatedly:

}
