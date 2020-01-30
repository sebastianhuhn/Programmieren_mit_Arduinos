#include <Lautsprecher.h>

Lautsprecher lautsprecher( 9 );

void setup() {
  // put your setup code here, to run once:
  }

void loop() {
  // put your main code here, to run repeatedly:
  lautsprecher.spieleTon( NOTE_A4, 1000);
  lautsprecher.spieleTon( NOTE_AS4, 1000);
  lautsprecher.spieleTon( NOTE_B4, 1000);
  lautsprecher.spieleTon( NOTE_C4, 1000);
  lautsprecher.spieleTon( NOTE_CS4, 1000);
  lautsprecher.spieleTon( NOTE_D4, 1000);
  lautsprecher.spieleTon( NOTE_DS4, 1000);
  lautsprecher.spieleTon( NOTE_E4, 1000);
  lautsprecher.spieleTon( NOTE_F4, 1000);
  lautsprecher.spieleTon( NOTE_FS4, 1000);
  lautsprecher.spieleTon( NOTE_G4, 1000);
  lautsprecher.spieleTon( NOTE_GS4, 1000);
  delay(2500);

  /*
  int toene1[] = { 1500, 2000, 2500, 3000 };
  int dauer1[] = { 500 ,  500,  500, 500 };
  lautsprecher.spieleTonleiter( toene1, dauer1 );
  delay(2500);
   
  int toene2[] = { 1500, 0, 2500 };
  int dauer2[] = { 250 ,  100,  250 };
  lautsprecher.spieleWiederholung( toene2, dauer2, 5);
  delay(2500);  
  */

}
