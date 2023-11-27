#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN  PB5  // Pin 13 on Atmega 328p
#define BUTTON_PIN PD2  // Pin 2 on Atmega 328p

void setup() {
	// Set LED_PIN as output
	DDRB |= (1 << LED_PIN);
	
	// Set BUTTON_PIN as input with pull-up resistor
	PORTD |= (1 << BUTTON_PIN);
}

int main() {
	setup();

	while (1) {
		// Check if the button is pressed
		if (!(PIND & (1 << BUTTON_PIN))) {
			// If button is pressed, turn on the LED
			PORTB |= (1 << LED_PIN);
			_delay_ms(500);  // Delay for 500 milliseconds
			} else {
			// If button is not pressed, turn off the LED
			PORTB &= ~(1 << LED_PIN);
		}
	}

	return 0;
}
