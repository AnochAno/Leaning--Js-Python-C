#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void displaySSD(unsigned int num) {
	// Define segment values for common cathode 7-segment display
	char seg[] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
	PORTC = seg[num];
}

void init_ssd() {
	DDRC = 0xFF; // Set all PORTC pins as output
}

int main(void) {
	init_ssd(); // Call init_ssd function

	unsigned int counter = 0;

	while (1) {
		displaySSD(counter % 20); // Display the least significant digit of the counter
		_delay_ms(4000); // Delay to prevent ghosting
		counter++;

		if (counter == 10) {
			counter = 0; // Reset counter when it reaches 10
		}
	}

	return 0;
}
