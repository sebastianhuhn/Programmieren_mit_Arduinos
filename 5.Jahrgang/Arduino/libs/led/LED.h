#ifndef LED_H
#define LED_H

/**
 * @brief Diese Klasse ermöglicht die Verwendung von LEDs.
 * Wichtig hierbei ist, dass ein 220 Ohm Widerstand in Reihe zu schalten ist.
 * Außerdem ist es notwendig, dass das zweite Bein der LED mit Masse(GND) verbunden ist.
 */

class LED {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Ansteuerung einer einzelnen LED ermöglicht.
	 * Hierbei muss der verwendete Pin angegeben werden.
	 * @param pin Verwendete Pin-Nummer
	 * Beispiel:
	 * @code 
	 * LED grueneLED( 5 );
	 * @endcode
	 */
	explicit LED( unsigned pin ) 
		: m_pin(pin), 
		  m_state(false) {
		pinMode(m_pin, OUTPUT);
	//
	}

	/**
	 * Schaltet die LED ein.
	 * Beispiel:
	 * @code 
	 * grueneLED.einschalten();
	 * @endcode
	 */
	inline void einschalten(){
		m_state = true;
		digitalWrite(m_pin, m_state);
	}
	
	/**
	 * Schaltet die LED aus.
	 * Beispiel:
	 * @code 
	 * grueneLED.ausschalten();
	 * @endcode
	 */
	inline void ausschalten(){
		m_state = false;
		digitalWrite(m_pin, m_state);
	}

private:
	unsigned m_pin;
	bool m_state;

};

#endif // LED_H
