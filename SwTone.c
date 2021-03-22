#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>

int Tone (int freq, int timer) {
	
	softToneCreate (12);
	
	softToneWrite (12, freq);
	if (timer) {
		delay (timer);
		softToneWrite (12, 0);
	}

	return 0;
}
