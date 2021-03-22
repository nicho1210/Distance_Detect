#include <wiringPi.h>
#include <stdio.h>

extern int SensorDetect (void);
extern void LedOnOff (int On);
extern int Tone (int freq, int timer);

int main () {
		
	int dis = 0;
	printf ("Distance Detect\n");

	if (wiringPiSetupGpio() == -1) {
		printf ("Failed\n");
		return 1;
	}
	while(1) {

		dis = SensorDetect();

		if (dis <= 100 && dis > 50) {
			LedOnOff (1);
			Tone (261, 1000);
		} else if (dis <= 50 && dis > 25) {
			LedOnOff (1);
			Tone (261, 500);
			LedOnOff (0);
		} else if (dis <= 25 && dis > 10) {
			LedOnOff (1);
			Tone (261, 100);
			LedOnOff (0);
		} else if (dis <= 10) {
			LedOnOff (1);
			Tone (261, 0);
			LedOnOff (0);
		}
		delay (100);
	}
	return 0;
}
