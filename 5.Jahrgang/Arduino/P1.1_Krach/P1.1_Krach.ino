#include <AudioSensor.h>
#include <Lautsprecher.h>
#include <Display.h>

Lautsprecher lautsprecher( 6 );
AudioSensor sensor( 5 );
Display anzeige;
  
  int meine_tonleiter[] = { 100, 200, NOTE_A7};
  int meine_tondauer[] = { 250, 500, 750 };
  
void setup() {
  anzeige.initialisiere();

  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if( sensor.laut() ){
    sensor.ausschalten();               // Sensor deaktivieren, damit er nicht auf den Warnton reagiert
    lautsprecher.spieleTonleiter( meine_tonleiter, meine_tondauer ); // Spielt den Warnton 1s lang ab
    delay(2000);                        // Wartet bis der Warnton abgespielt wurde (+ "Puffer")
    sensor.einschalten();               // ... wieder einschalten
   }
}
