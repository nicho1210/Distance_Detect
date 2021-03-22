CC = gcc

INC = -I ./include
LIB = -l wiringPi
OBJ = sensor.OBJ ledonoff.OBJ buzzer_sw.OBJ SwTone.OBJ

# define any compile-time flags
CFLAGS = -Wall $(OBJ) -g -O

.PHONY: clean

all: DistanceDetect $(OBJ)

DistanceDetect : main.c $(OBJ)
	$(CC) -Wall $(OBJ) -o $@ $< $(LIB)

sensor.OBJ: sensor.c
	$(CC) -Wall -c -o $@ $< $(LIB)

ledonoff.OBJ: ledonoff.c
	$(CC) -Wall -c -o $@ $< $(LIB)

buzzer_sw.OBJ: buzzer_sw.c
	$(CC) -Wall -c -o $@ $< $(LIB)

SwTone.OBJ: SwTone.c
	$(CC) -Wall -c -o $@ $< $(LIB)

clean:
	rm -f DistanceDetect $(OBJ)
