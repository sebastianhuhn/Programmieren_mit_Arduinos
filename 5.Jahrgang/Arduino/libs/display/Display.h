#ifndef DISPLAY_H
#define DISPLAY_H

#include "LiquidCrystal_I2C.h"
#include "Wire.h"

#define LCD_COLS 16
#define LCD_ROWS 2
/**
 * @brief Diese Klasse ermöglicht die Verwendung und gezielte Ansteuerung der Anzeige.
 */

class Display : protected LiquidCrystal_I2C{
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Ansteuerung der Anzeige ermöglicht.
	 * Beispiel:
	 * @code 
	 * Display anzeige;
	 * @endcode
	 */
	explicit Display() : LiquidCrystal_I2C(0x3F, LCD_COLS, LCD_ROWS) {

	}

	/**
	 * Initialisiert die Anzeige.
	 * Beispiel:
	 * @code 
	 * anzeige.initialisiere();
	 * @endcode
	 */
	inline void initialisiere(){
		Serial.begin(9600);
		begin();
		home();
		clear();
		cursor();
	}
	/**
	 * Setzt den Cursor der Anzeige auf den Beginn der ersten Zeile.
	 * Beispiel:
	 * @code 
	 * anzeige.geheErsteZeile();
	 * @endcode
	 */
	inline void geheErsteZeile(){
		setCursor(0,0);
	}

	/**
	 * Setzt den Cursor der Anzeige auf den Beginn der zweiten Zeile.
	 * Beispiel:
	 * @code 
	 * anzeige.geheZweiteZeile();
	 * @endcode
	 */
	inline void geheZweiteZeile(){
		setCursor(0,1);
	}

	/**
	 * Setzt den Cursor der Anzeige an die jeweilige Position.
	 * @param zeile Zeilennummer ( 0 oder 1 )
	 * @param position Positionsnummer ( 0 ... 15 )
	 *
	 * Beispiel:
	 * @code 
	 * anzeige.gehePosition(1, 10);
	 * @endcode
	 */
	inline void gehePosition(unsigned zeile, unsigned position){
		setCursor( position, zeile );
	}
	/**
	 * Löscht den gesamten Anzeigetext.
	 * 
	 * Beispiel:
	 * @code 
	 * anzeige.loescheText();
	 * @endcode
	 */
	inline void loescheText(){
		clear();
	}

	/**
	 * Gibt den jeweiligen Text auf dem Display von der aktuellen Position aus beginned aus.
	 * @param text Ausgabetext
	 * 
	 * Beispiel:
	 * @code 
	 * anzeige.schreibeText("Testtext");
	 * @endcode
	 */
	inline void schreibeText(const char text[] ){
		print(text);
	}
	
	
	/**
	 * Gibt die jeweilige Zahl auf dem Display von der aktuellen Position aus beginned aus.
	 * @param num Auszugebende Ganzzahl
	 * 
	 * Beispiel:
	 * 
	@code 
	 * anzeige.schreibeText(1500);
	 * @endcode
	 */
	inline void schreibeText( int num ){
		print( String(num) );
	}
	 
	 /**
	 * Gibt die jeweilige Zahl auf dem Display von der aktuellen Position aus beginned aus.
	 * @param num Auszugebende Kommazahl
	 * @param dec Anzahl der Dezimalnachkommastellen
	 * Beispiel:
	 * @code 
	 * anzeige.schreibeText(15.5);
	 * @endcode
	 */
	inline void schreibeText( float num, int dec = 1 ){
		print( String(num, dec) );
	}
	 
private:

};

#endif // DISPLAY_H
