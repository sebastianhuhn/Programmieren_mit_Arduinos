#include <Display.h>
#include <Taster.h>

Display display;
Taster knopf1( 2 );
Taster knopf2( 3 ); 

int zaehler = 0;

void setup() {
    // put your setup code here, to run once:
    display.initialisiere();
    display.schreibeText(Zaehler );
    display.geheZweiteZeile();
    display.schreibeText( "---------" );
}

void loop() {
  // put your main code here, to run repeatedly:

  if( knopf1.wurdeGedrueckt() ){        // Wurde Knopf 1 gedrückt?
    display.geheZweiteZeile();          // Gehe an den Anfang der 2. Zeile
    zaehler = zaehler + 1;              // Erhöhe Zähler: zaehler += 1; zaehler++; ++zaehler;                       
    display.schreibeText( zaehler );
    knopf1.loescheMarkierung();         // Lösche Markierung

  }
  else if( knopf2.wurdeGedrueckt() ){    // ODER wurde Knopf 2 gedrückt?
    display.geheZweiteZeile();           // Gehe an den Anfang der 2. Zeile
    zaehler = 0;                         // Setze den Zähler auf Null 
    display.schreibeText( "---------" );
    knopf2.loescheMarkierung();          // Lösche Markierung
  }
}
