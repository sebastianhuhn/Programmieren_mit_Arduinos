#include <LED.h>
#include <FuellstandsSensor.h>

/*
#include <Display.h>
Display display;
*/

LED gruen( 7 );
LED gelb( 6 );
LED rot( 5 );

FuellstandsSensor sensor( A2 );

int fuellstand;

void setup() {
  Serial.begin(9600);
  //display.initialisiere();
  fuellstand = 0;
  // put your setup code here, to run once:
}

void fuellstandLeer(){
    gruen.einschalten();
    gelb.ausschalten();
    rot.ausschalten();
}

void fuellstandMittel(){
    gelb.einschalten();
    gruen.ausschalten();
    rot.ausschalten();
}

void fuellstandKritisch(){
    rot.einschalten();
    gelb.ausschalten();
    gruen.ausschalten();
}
void loop() {
  fuellstand = sensor.missFuellstand();
  Serial.print("Füllstand:");
  Serial.println( fuellstand );
  
  if( fuellstand < 25 ){ // => 0% oder 1%
    fuellstandLeer();
  }
  else if( fuellstand < 75 ){ // => 25% oder 50%
    fuellstandMittel();
  }
  else{                       // => 75% oder 100%
    fuellstandKritisch();
  }
 
  // Eigentlich nicht benötigt
  /*
  display.loescheText();
  display.geheErsteZeile();
  display.schreibeText( fuellstand );
  display.schreibeText( "%" );
  display.geheZweiteZeile();
  display.schreibeText( "Roh: ");
  display.schreibeText( sensor.missFuellstandRaw() );
  */
  
  // put your main code here, to run repeatedly:
  delay(500);
}
