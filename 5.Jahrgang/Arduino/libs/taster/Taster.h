#ifndef TASTER_H
#define TASTER_H

// Helper variable
volatile bool state = false;
volatile bool state2 = false;

/**
 * @brief Diese Klasse ermöglicht die Verwendung von Tastern.
 * Wichtig hierbei ist, dass das Schalten gegen Masse (GND) erfolgt.
 */
class Taster {
public:
	/**
	 * Konstruktor
	 * 
	 * Erstellt ein Objekt, welches die Verwendung eines Tasters ermöglicht.
	 * Hierbei muss der verwendete Pin angegeben werden.
	 * @param pin Verwendete Pin-Nummer
	 * Beispiel:
	 * @code 
	 * Taster meinTaster( 5 );
	 * @endcode
	 */
	explicit Taster( unsigned pin ) 
		: m_pin(pin)
		, m_state(nullptr) {
		pinMode(m_pin, INPUT_PULLUP);
		if( pin == 2){
			attachInterrupt( digitalPinToInterrupt( pin ) , standardAktion, FALLING );
			m_state = &state;
		}
		else if( pin == 3 ){
			attachInterrupt( digitalPinToInterrupt( pin ) , standardAktion2, FALLING );
			m_state = &state2;
		}
	}

	/**
	 * Überprüft, ob der Taster gedrückt wurde.
	 * @return wahr falls gedrückt, sonst falsch
	 * @code 
	 * if( meinTaster.wurdeGedrueckt() ){
	 * // Mache irgendwas
	 * }
	 * @endcode
	 */
	
	inline bool wurdeGedrueckt(){
		return *m_state;
	}
	
	/** Entfernt die Markierung, dass der Taster gedrückt wurde.
	*
	* @code 
	* meinTaster.loescheMarkierung()
	* @endcode
	*/
	inline void loescheMarkierung(){
		delay(100);
		noInterrupts();
		*m_state = false;
		interrupts();
	}
	 
	/**
	 * Setz eine Funktion, die bei Druck des Tasters ausgeführt wird.
	 * Beispiel:
	 * @code 
	 * void meineAktion(){
	 *	// Mache irgendwas 
	 * }
	 * meinTaster.setzeAktion( meineAktion );
	 * @endcode
	 */
	inline void setzeAktion( void (*funktion )(void) ){
		attachInterrupt( digitalPinToInterrupt(m_pin), funktion, FALLING );
	}
	
	static void standardAktion(  ){
	   noInterrupts();
	   state = true;
	   interrupts();
	}

	static void standardAktion2(  ){
	   noInterrupts();
	   state2 = true;
	   interrupts();
	}
	
private:
	unsigned m_pin;
	volatile bool * m_state;
};

#endif // TASTER_H
