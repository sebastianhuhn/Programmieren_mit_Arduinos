#ifndef KABEL_H
#define KABEL_H

/**
 * @brief Diese Klasse ermöglicht die Verwendung von Kabeln.
 * Außerdem ist es notwendig, dass eine Seite des Kabels mit Masse(GND) verbunden ist.
 */

class Kabel {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Ansteuerung einer einzelnen KABEL ermöglicht.
	 * Hierbei muss der verwendete Pin angegeben werden.
	 * @param pin Verwendete Pin-Nummer
	 * Beispiel:
	 * @code 
	 * Kabel bruecke( 5 );
	 * @endcode
	 */
	explicit Kabel( unsigned pin ) 
		: m_pin(pin){
		pinMode(m_pin, INPUT_PULLUP);
	//
	}
	
	/**
	 * Gibt den Zustand des Kabels zurück, ob der Schaltkreis geschlossen ist.
	 * Beispiel:
	 * @code 
	 * if( bruecke.schaltkreisGeschlossen() ){
	 * // 
	 * }
	 * @endcode
	 */
	inline bool schaltkreisGeschlossen(){
		return ( digitalRead(m_pin) == LOW );
	}

	/**
	 * Gibt den Zustand des Kabels zurück, ob Schaltkreis geöffnet ist.
	 * Beispiel:
	 * @code 
	 * if( bruecke.schaltkreisGeoeffnet() ){
	 * // 
	 * }
	 * @endcode
	 */
	inline bool schaltkreisGeoeffnet(){
		return ( digitalRead(m_pin) == HIGH );
	}

private:
	unsigned m_pin;

};

#endif // KABEL_H
