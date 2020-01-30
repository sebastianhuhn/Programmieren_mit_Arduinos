#ifndef TEMPERATURSENSOR_H
#define TEMPERATURSENSOR_H

/**
 * @brief Diese Klasse ermöglicht die Verwendung des Temperatursensors.
 * Wichtig hierbei ist, dass Pin-1 mit Masse (GND), Pin-2 mit Analogeingang (A0-A5) und Pin-3 mit Versorgungsspannung (+5V) verbunden sind.
 * ( Plane Schnittfläche des  Halbkreis zeigt nach unten: Pin-1 rechts, Pin-2 mittig, Pin-3 links !) 
 */

class TemperaturSensor {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Verwendung des Temperatursensors ermöglicht.
	 * Hierbei muss der verwendete Pin angegeben werden, wobei nur die analogen Pins A0 bis A5 verwendet werden können.
	 * @param pin Verwendete Pin-Nummer
	 * Beispiel:
	 * @code y
	 * TemperaturSensor sensor( 5 );
	 * @endcode
	 */
	explicit TemperaturSensor( unsigned pin ) 
		: m_pin(pin) { 
	}

	/**
	* Ermittelt die aktuelle Temperatur in °C. Hierbei muss der Datentyp 'float' einer Nicht-Ganzzahl (!) verwendet werden.
	 * Beispiel:
	 * @code 
	 * float temperatur = sensor.missTemperatur(); 
	 * @endcode
	*/
	float missTemperatur(){
		float temp = analogRead( m_pin );
		temp /= 1024; // Auflö1sung ADC
		temp *= 5000; // Ref. Wert
		temp /= 10; // -> Celsius 
		return temp;
	}


private:
	unsigned m_pin;

};

#endif // TEMPERATURSENSOR_H
