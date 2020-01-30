#ifndef FUELLSTANDSSENSOR_H
#define FUELLSTANDSSENSOR_H

/**
 * @brief Diese Klasse ermöglicht die Verwendung des Füllstandssensors.
 * Wichtig hierbei ist, dass Pin "-" mit Masse (GND), Pin "+" mit Versorgungsspannung (+5V) und Pin "S" mit Analogeingang (A0-A5) verbunden sind.
 */

class FuellstandsSensor {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Verwendung des Füllstandssensors ermöglicht..
	 * Hierbei muss der verwendete Pin angegeben werden, wobei nur die analogen Pins A0 bis A5 verwendet werden können.
	 * @param pin Verwendete Pin-Nummer
	 * Beispiel:
	 * @code 
	 * FuellstandsSensor sensor( 5 );
	 * @endcode
	 */
	explicit FuellstandsSensor( unsigned pin ) 
		: m_pin(pin) { 
	}

	/**
	* Ermittelt den aktuellen Füllstand als analogen Wert.
	 * Hinweis: Analoge Messwerte
	 *	1   160
	 *	25  250
	 *	50  260
	 *	75  270
	 *	100 300
	 * Beispiel:
	 * @code 
	 * int temperatur = sensor.missFuellstandRaw(); 
	 * @endcode
	*/
	inline int missFuellstandRaw(){
		return analogRead( m_pin );
	}

	/**
	* Ermittelt den aktuellen Füllstand in Prozent.
	 * Beispiel:
	 * @code 
	 * int temperatur = sensor.missFuellstand(); 
	 * @endcode
	*/
	inline float missFuellstand(){
		int raw = missFuellstandRaw();
		if( raw < 160 ) {
			return 0;
		}
		else if( raw >= 160 && raw < 250 ) {
			return 1;
		}
		else if( raw >= 250 && raw < 270 ) {
			return 25;
		}
		else if( raw >= 270 && raw < 282 ){
			return 50;
		}
		else if( raw >= 282 && raw < 290 ){
			return 75;
		}
		else{
			return 100;
		}		

	}


private:
	unsigned m_pin;

};

#endif // FUELLSTANDSSENSOR_H
