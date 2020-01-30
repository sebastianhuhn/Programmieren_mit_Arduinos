#ifndef HELLIGKEITSSENSOR_H
#define HELLIGKEITSSENSOR_H

/**
 * @brief Diese Klasse ermöglicht die Verwendung des Helligkeitssensors.
 * Wichtig hierbei ist, dass ein Pin A "+" mit Versorgungsspannung (+5V) und der andere Pin B mit einem Analogeingang (A0-A5) verbunden sind.
 * Zusätzlich muss Pin B mit einem 10K Ohm Widerstand mit Masse (-) verbunden sein.
 */

class HelligkeitsSensor {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Verwendung des Helligkeitssensor ermöglicht.
	 * Hierbei muss der verwendete Pin angegeben werden, wobei nur die analogen Pins A0 bis A5 verwendet werden können.
	 * @param pin Verwendete Pin-Nummer
	 * Beispiel:
	 * @code 
	 * HelligkeitsSensor sensor( A3 );
	 * @endcode
	 */
	explicit HelligkeitsSensor( unsigned pin ) 
		: m_pin(pin) { 
	}

	/**
	* Ermittelt die aktuelle Helligkeit als analogen Wert.
	 * Hinweis: Analoge Messwerte 0 bis 1023
	 * Beispiel:
	 * @code 
	 * int helligkeit = sensor.missHelligkeitRaw(); 
	 * @endcode
	*/
	inline int missHelligkeitRaw(){
		return analogRead( m_pin );
	}

	/**
	* Ermittelt die aktuelle Helligkeit in dunkel - entspricht 0- und hell -entspricht 100- an.
	 * Beispiel:
	 * @code 
	 * int helligkeit = sensor.missHelligkeit(); 
	 * @endcode
	*/
	inline float missHelligkeit(){
		return ( missHelligkeitRaw() / 10.24 );
	}


private:
	unsigned m_pin;

};

#endif // HELLIGKEITSSENSOR_H
