#include <stdio.h>
#include <stdlib.h>
#include "gen.h"

midi_t sum(midi_t value) {
	temp += value;
	return temp;
}

midi_t avg(midi_t sumTotal, unsigned int _counter) {
	return  sumTotal / _counter;
}

midi_t rnd(midi_t min , midi_t max) {
	return min + rand() % (max - min);
}

midi_t rndw(midi_t* arr, size_t size) {
	return arr[0];
}