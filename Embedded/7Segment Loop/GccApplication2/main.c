#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BUTTON_PIN PD2 // Assuming the button is connected to PD2

void displaySSD(unsigned int num) {
	// Define segment values for common cathode 7-segment display
	char seg[] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
	PORTC = seg[num];
}

void init_ssd() {
	DDRC = 0xFF; // Set all PORTC pins as output
}

void init_button() {
	// Set BUTTON_PIN as input with pull-up resistor
	PORTD |= (1 << BUTTON_PIN);
}

int is_button_pressed() {
	// Check if the button is pressed (LOW)
	return bit_is_clear(PIND, BUTTON_PIN);
}

int main(void) {
	init_ssd(); // Call init_ssd function
	init_button(); // Call init_button function

	unsigned int counter = 0;

	while (1) {
		if (is_button_pressed()) {
			// Button is pressed, increment the counter
			_delay_ms(50); // Introduce a delay to handle button bouncing
			if (is_button_pressed()) {
				counter++;
				counter %= 10; // Limit the counter to a single digit
				displaySSD(counter);
				_delay_ms(1000); // Delay to prevent ghosting
			}
		}
	}

	return 0;
}
