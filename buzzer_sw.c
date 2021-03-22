#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define PWM_pin    12

void Buzzer (int On, int timer) {
	
	pinMode (PWM_pin, OUTPUT);

	softPwmCreate(PWM_pin, 1, 100);
	
	if (On) {
		softPwmWrite (PWM_pin, 0);
		delay (100);
		softPwmWrite (PWM_pin, 100);
		delay (timer);
	}
	delay (10);
	softPwmWrite (PWM_pin, 0);
	delay (10);

	return;
}
