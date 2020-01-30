#ifndef AUDIOSENSOR_H
#define AUDIOSENSOR_H

/**
 * @brief Diese Klasse ermöglicht die Verwendung des Audiosensor.
 */

class AudioSensor {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches zur Abfrage des Audiosensor dient.
	 * Beispiel:
	 * @code 
	 * AudioSensor sensor;
	 * @endcode
	 */
	explicit AudioSensor( unsigned dig_pin, unsigned ana_pin = 0  )
		: m_dig_pin( dig_pin )
		, m_ana_pin( ana_pin )
		, m_aktiv( true ) {
		pinMode(m_dig_pin, INPUT_PULLUP);
	}

	/**
	 * Prüft, ob die aktuelle Lautstärke den Grenzwert überschritten wurde.
	 * Der Grenzwert wurde mit der "Einstellschraube" justiert.
	 * Beispiel:
	 * @code 
	 * if( sensor.laut() ){
	 *	// mach irgendwas
	 * }
	 * @endcode
	 */
	inline bool laut(){
		return ( m_aktiv && digitalRead( m_dig_pin ) == HIGH );
	}

	/**
	 * Schaltet den Sensor ein.
	 * Beispiel:
	 * @code 
	 * sensor.einschalten();
	 * @endcode
	 */
	inline void einschalten(){
		m_aktiv = true;
	}

	/**
	 * Schaltet den Sensor aus.
	 * Beispiel:
	 * @code 
	 * sensor.ausschalten();
	 * @endcode
	 */
	inline void ausschalten(){
		m_aktiv = false;
	}
	/**
	 * Der Grenzwert wurde mit der "Einstellschraube" justiert.
	 * Beispiel:
	 * @code 
	 * int lautstaerke = sensor.missLautstaerke();
	 * @endcode
	 */
	
	inline int missLautstaerke(){
		if( m_ana_pin <= 0 ) {
			return -1;
		}
		return analogRead(m_ana_pin);
	}
		 
private:

	unsigned m_dig_pin;
	unsigned m_ana_pin;
	bool m_aktiv;
};

#endif // DISPLAY_H
