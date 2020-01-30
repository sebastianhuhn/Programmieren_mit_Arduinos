#include <Matrix.h>

Matrix anzeige;


void setup() {
  int zeilen[] = { 4, A2, 5, 0, 12, 6, 11, 8}; // R1...R8
  int spalten[] = { A3, 10, 9, 3, 7, 1, A1, A0}; // C1...C8
  anzeige.initialisiere(zeilen, spalten);
  // put your setup code here, to run once:

}

void loop() {
  bool ibuchstabe[8][8] = { 
    {0, 0, 1, 1, 1, 1, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }
   ,{0, 0, 1, 1, 1, 1, 0, 0 }  
  };
  
  bool ubuchstabe[8][8] = { 
    {0, 1, 1, 0, 0, 1, 1, 0 }
   ,{0, 1, 1, 0, 0, 1, 1, 0 }
   ,{0, 1, 1, 0, 0, 1, 1, 0 }
   ,{0, 1, 1, 0, 0, 1, 1, 0 }
   ,{0, 1, 1, 0, 0, 1, 1, 0 }
   ,{0, 1, 1, 0, 0, 1, 1, 0 }
   ,{0, 0, 1, 1, 1, 1, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }  
  };
  
  bool herz[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0 }
   ,{0, 0, 1, 0, 0, 1, 0, 0 }
   ,{0, 1, 0, 1, 1, 0, 1, 0 }
   ,{1, 0, 0, 0, 0, 0, 0, 1 }
   ,{1, 0, 0, 0, 0, 0, 0, 1 }
   ,{0, 1, 0, 0, 0, 0, 1, 0 }
   ,{0, 0, 1, 0, 0, 1, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }  
  };

   bool herz2[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0 }
   ,{0, 0, 0, 0, 0, 0, 0, 0 }
   ,{0, 1, 1, 0, 0, 1, 1, 0 }
   ,{1, 1, 1, 1, 1, 1, 1, 1 }
   ,{1, 1, 1, 1, 1, 1, 1, 1 }
   ,{0, 1, 1, 1, 1, 1, 1, 0 }
   ,{0, 0, 1, 1, 1, 1, 0, 0 }
   ,{0, 0, 0, 1, 1, 0, 0, 0 }  
  };
 

  anzeige.setzeZustand( ibuchstabe );
  anzeige.anzeigen( 40 );
  anzeige.setzeZustand( herz2 );
  anzeige.anzeigen( 40 );
  anzeige.setzeZustand( ubuchstabe );
  anzeige.anzeigen( 40 );

  anzeige.loescheAlles();
  anzeige.einschalten( 1, 1 );
  anzeige.einschalten( 2, 2 );
  anzeige.einschalten( 3, 3 );
  anzeige.einschalten( 4, 4 );
  anzeige.einschalten( 5, 5 );
  anzeige.einschalten( 6, 6 );
  anzeige.einschalten( 7, 7 );
  anzeige.einschalten( 8, 8 );
  anzeige.anzeigen( 400 );
  // put your main code here, to run repeatedly:

}
