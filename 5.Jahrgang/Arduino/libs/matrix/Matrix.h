#ifndef MATRIX_H
#define MATRIX_H

#include <assert.h>

/**
 * @brief Diese Klasse ermöglicht die Verwendung der 8x8 LED-Matrix.
 * Diese Matrix besteht auch 8 Zeilen (rows R1...R8) und 8 Spalten (columns C1...C8).
 * Hierbei agieren die Zeilen als Anode (inaktiv bei LOW), die Spalten als Kathode (inaktiv bei HIGH).
 * Wichtig hierbei ist, dass ein 1K Ohm Widerstand in Reihe bei JEDER Kathode (C1...C8) zu schalten ist.
 */

class Matrix {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Ansteuerung der Matrix ermöglicht.
	 * Beispiel:
	 * @code 
	 * Matrix matrix(  );
	 * @endcode
	 */
	explicit Matrix() {
	}

	/**
	 * Initialisiert die LED-Matrix.
	 * @param zeilen[] Array der Pins für die Zeilen (R1, R2, R3, R4, R5, R6, R7, R8)
	 * @param spalten[] Array der Pins für die Spalten (R1, R2, R3, R4, R5, R6, R7, R8)	 
	 * Beispiel:
	 * @code 
	 * int zeilen[] = {9, A1, 8, 12, 1, 7, 2, 5 }; 		// R1...R8
	 * int spalten[] = {A0, 3, 4, 10, 6, 11, A2, A3}; 	// C1...C8
	 * matrix.initialisiere(zeilen, spalten);
	 * @endcode
	 */
	inline void initialisiere(int zeilen[], int spalten[]){
		for( unsigned i = 0; i < 8; ++i ){
				m_pins_row[i] = zeilen[i];
				m_pins_col[i] = spalten[i];
				pinMode( m_pins_row[i], OUTPUT);	
				pinMode( m_pins_col[i], OUTPUT);	
				
		}
		loescheAlles();
	}
	/**
	 * Schaltet die jeweilige LED der Matrix ein.
	 * @param zeile Einzuschaltende Zeilennummer (1...8)
	 * @param spalte Einzuschaltende Spaltennummer (1...8)	 
	 * Beispiel:
	 * @code 
	 * matrix.einschalten( 5, 6);
	 * @endcode
	 */
	inline void einschalten( unsigned zeile, unsigned spalte ){
		assert( zeile > 0 );
		assert( spalte > 0 );
		if( zeile > 8 || spalte > 8 ){
			return; 
		}
		m_state[zeile-1][spalte-1] = true;
	}
		
	/**
	 * Schaltet die jeweilige LED der Matrix aus.
	 * @param zeile Auszuschaltende Zeilennummer (1...8)
	 * @param spalte Auszuschaltende Spaltennummer (1...8)	 
	 * Beispiel:
	 * @code 
	 * matrix.ausschalten( 5, 6 );
	 * @endcode
	 */
	inline void ausschalten( unsigned zeile, unsigned spalte ){
		assert( zeile > 0 );
		assert( spalte > 0 );
		if( zeile > 8 || spalte > 8 ){
			return; 
		}
		m_state[zeile-1][spalte-1] = false;
	}


	/**
	 * Schaltet alle LEDs auf der Matrix ein.
	 * Beispiel:
	 * @code 
	 * matrix.test();
	 * @endcode
	 */
	inline void test(){
		for( unsigned i = 0; i < 8; ++i){
			for( unsigned j = 0; j < 8; ++j){
				m_state[i][j] = true;
			}
		}
	}


	/**
	 * Setzt den Zustand aller LEDs der Matrix.
	 * @param zustand[][] 2D Array mit 0/1 Werten der jeweiligen LED
	 * Beispiel:
	 * @code 
	 * bool zustand[8][8] = { 
	 * {0, 0, 1, 1, 1, 1, 0, 0 }
     * ,{0, 0, 0, 1, 1, 0, 0, 0 }
     * ,{0, 0, 0, 1, 1, 0, 0, 0 }
     * ,{0, 0, 0, 1, 1, 0, 0, 0 }
     * ,{0, 0, 0, 1, 1, 0, 0, 0 }
	 * ,{0, 0, 0, 1, 1, 0, 0, 0 }
     * ,{0, 0, 0, 1, 1, 0, 0, 0 }
     * ,{0, 0, 1, 1, 1, 1, 0, 0 }  
     * };
	 * matrix.setzeZustand( zustand );
	 * @endcode
	 */
	inline void setzeZustand( bool zustand[][8] ){
		for( unsigned i = 0; i < 8; ++i){
			for( unsigned j = 0; j < 8; ++j){
				m_state[i][j] = zustand[i][j];
			}
		}
	}

	/**
	 * Setzt den aktuell gespeicherten Zustand aller LEDs.
	 * @param dauer Anzeigedauer (in cs)
	 * Beispiel:
	 * @code 
	 * matrix.anzeigen( 500 );
	 * @endcode
	 */
	void anzeigen( unsigned dauer = 500 ){
		for( unsigned t = 0; t < dauer; ++t) {
			for( unsigned i = 0; i < 8; ++i ){	 		// Zeilen
					for( unsigned j = 0; j < 8; ++j){	// Spalten
						digitalWrite( m_pins_col[j], !m_state[i][j] );
					}
					digitalWrite( m_pins_row[i], HIGH);	// Zeile aktivieren	
					delay(1);
					digitalWrite( m_pins_row[i], LOW);
			}	
		}
	}

	/**
	 * Schaltet alle LEDs auf der Matrix aus.
	 * Beispiel:
	 * @code 
	 * matrix.loescheAlles();
	 * @endcode
	 */
	void loescheAlles(){
		for( unsigned i = 0; i < 8; ++i ){
			digitalWrite( m_pins_row[i], LOW );	
			digitalWrite( m_pins_col[i], HIGH );		
			for( unsigned j = 0; j < 8; ++j ){
				m_state[i][j] = false;
			}
		}
	}

private:
	int m_pins_row[8];
	int m_pins_col[8];
	bool m_state[8][8];
};

#endif // MATRIX_H
