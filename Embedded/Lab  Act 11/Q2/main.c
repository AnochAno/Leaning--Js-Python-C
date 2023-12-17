#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BUTTON_PIN PD2 // Assume the push button is connected to PD2

void displaySSD(unsigned int num) {
	// Define segment values for common cathode 7-segment display
	char seg[] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
	PORTC = seg[num];
}

void init_ssd() {
	DDRC = 0xFF; // Set all PORTC pins as output
}

void init_button() {
	// Set the BUTTON_PIN as input and enable internal pull-up resistor
	DDRD &= ~(1 << BUTTON_PIN);
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
	int button_state = 0; // 0: button not pressed, 1: button pressed

	while (1) {
		if (is_button_pressed() && !button_state) {
			// Button is pressed and it was not pressed in the previous loop
			_delay_ms(20); // Introduce a delay to handle button bouncing
			if (is_button_pressed()) {
				// Increment counter only if the button is still pressed after the delay
				counter++;
				if (counter == 10) {
					counter = 0; // Reset counter when it reaches 10
				}
			}
			button_state = 1; // Update button state to indicate it's pressed
			} else if (!is_button_pressed()) {
			button_state = 0; // Update button state to indicate it's not pressed
		}

		displaySSD(counter); // Display the counter value on the SSD
	}

	return 0;
}
