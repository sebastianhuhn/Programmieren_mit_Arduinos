#include <Lautsprecher.h>

Lautsprecher lautsprecher( 9 );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
  lautsprecher.spieleAbwechselnd(NOTE_A4, NOTE_D6, 10 );
  delay( 2500 );
}
