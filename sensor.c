#include <stdio.h>
#include <wiringPi.h>

#define sonar_amount 1
#define sonar_trig_time 100
#define sonar_echo_time 2000
//#define sonar_trig_io 5
//#define sonar_echo_io 6

#define max_dist 900       //450cm * 2 = 900
#define max_dist_us 26470  // microseconds
#define min_dist 4         //2cm * 2 = 4
#define min_dist_us 117  // microseconds
// 900cm / (340m/s) = 26470 microseconds
// 2cm / (340m/s) = 117 microseconds

#define sonar_exchange_rate 40

int sonar_trig_io[3] = {5, 19, 20};
int sonar_echo_io[3] = {6, 26, 21};
int sonar_low_single[3] = {0};
unsigned int sonar_time_start[3] = {0};
unsigned int sonar_time_stop[3] = {0};

int sonar_counter = sonar_echo_time;

void
sonear_trigger_all ()
{
    int amount = 0;

    for (amount = 0; amount < sonar_amount; amount++) {
        digitalWrite(sonar_trig_io[amount], HIGH);
    }
    delayMicroseconds(10);  //pryd test

    for (amount = 0; amount < sonar_amount; amount++) {
        digitalWrite(sonar_trig_io[amount], LOW);
    }

}

int SensorDetect (void)
{
    int j = 0;

    for (j = 0; j < sonar_amount; j++) {
        pinMode(sonar_trig_io[j], OUTPUT);
        digitalWrite(sonar_trig_io[j], LOW);
        pinMode(sonar_echo_io[j], INPUT);
    }

    sonear_trigger_all();

    sonar_time_start[0] = micros();
    
    printf ("sonar_time_start %dus\n", sonar_time_start[0]);
    for (;;) {
        while (!digitalRead(sonar_echo_io[0]))
        sonar_time_start[0] = micros();
        while (digitalRead(sonar_echo_io[0]));
        sonar_time_stop[0] = micros();
        printf ("sonar_time_stop %dus\n", sonar_time_stop[0]);

        break;

    }

    printf("%d cm\n", (((sonar_time_stop[0] - sonar_time_start[0]) * 34) / 1000) / 2);

    return (((sonar_time_stop[0] - sonar_time_start[0]) * 34) / 1000) / 2;
}
