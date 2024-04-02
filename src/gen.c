#include "gen.h"

struct midiPair;

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

void rndW(midi_t* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		midiPairStack[i].value = arr[i];
		midiPairStack[i].weight = rnd(1, 10);
	}
}