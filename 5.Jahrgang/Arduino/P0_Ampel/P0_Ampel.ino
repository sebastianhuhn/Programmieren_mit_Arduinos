#include <LED.h>
#include <Taster.h>

LED auto_gruen( 8 );
LED auto_gelb( 12 );
LED auto_rot( 11 );
LED personen_gruen( 10 ) ; 
LED personen_rot( 9 );
Taster knopf( 3 );

// Autoamplel von rot auf grün schalten mit Gelb-Phase
void autoGruenSchalten(){
  auto_gelb.einschalten();
  delay(1000);
  auto_rot.ausschalten();
  auto_gelb.ausschalten();
  auto_gruen.einschalten();
}

// Autoampel von grün auf rot schalten mit Gelb-Rot-Phase
void autoRotSchalten(){
  auto_gruen.ausschalten();
  auto_gelb.einschalten();
  delay(1000);
  auto_gelb.ausschalten();
  auto_rot.einschalten();
}

// Fußgängerampel von rot auf grün schalten
void personenGruenSchalten(){
   personen_rot.ausschalten();
   personen_gruen.einschalten();
}

// Fußgängerampel von grün auf rot schalten
void personenRotSchalten(){
   personen_gruen.ausschalten();
   personen_rot.einschalten();
}

// Wird einmalig am Programmstart ausgeführt
void setup() {
  auto_gruen.einschalten();
  personen_rot.einschalten();

}

// Wird immer wiederholt ausgeführtgit pgit pus
void loop() {
    if( knopf.wurdeGedrueckt() )
    { 
      // Wurde der Knopf gedrückt?
      autoRotSchalten();

      delay(1000);
      
      personenGruenSchalten();

      delay(5000);
      
      personenRotSchalten();
 
      delay(1000);
      autoGruenSchalten();

      knopf.loescheMarkierung();
      delay(10000);
      
    }
}
