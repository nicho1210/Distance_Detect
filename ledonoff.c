#include <wiringPi.h>
#include <stdio.h>

#define LED_Pin    20

void LedOnOff (int On) {
	
	pinMode (LED_Pin, OUTPUT);

	if (On) {
		digitalWrite (LED_Pin, HIGH);
	} else {
		digitalWrite (LED_Pin, LOW);
	}

}
