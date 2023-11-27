#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL  // Set the clock frequency to 16 MHz

int main(void) {
	// Configure Pin 3 (connected to LED) as an output
	DDRD |= (1 << DDD3);

	// Configure Pin 2 (connected to push button) as an input
	DDRD &= ~(1 << DDD2);

	while (1) {
		// Check if the push button is pressed (LOW)
		if (!(PIND & (1 << PIND2))) {
			// If pressed, turn ON the LED
			PORTD |= (1 << PORTD3);
			} else {
			// If not pressed, turn OFF the LED
			PORTD &= ~(1 << PORTD3);
		}

		_delay_ms(100);  // Add a small delay to avoid button debounce
	}

	return 0;
}
