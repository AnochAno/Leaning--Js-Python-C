#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void displaySSD(unsigned int num) {
	
	char seg[] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
	PORTC = seg[num];
}

void init_ssd() {
	DDRC = 0xFF; 
}

int main(void) {
	init_ssd(); 

	unsigned int counter = 0;

	while (1) {
		displaySSD(counter % 20); 
		_delay_ms(4000); // Delay to prevent ghosting
		counter++;

		if (counter == 10) {
			counter = 0; 
		}
	}

	return 0;
}
