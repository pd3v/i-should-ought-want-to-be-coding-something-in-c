#include "gen.h"

struct midiPair;

midi_t sum(midi_t value) {
	temp += value;
	return temp;
}

midi_t avg(midi_t sumTotal, unsigned int counter) {
	return  sumTotal / counter;
}

midi_t rnd(midi_t min , midi_t max) {
	return min + rand() % (max - min);
}

struct MidiPair* rndW(midi_t* arr, size_t size) {
	struct MidiPair* _midiPairs = (struct MidiPair*)  malloc(sizeof (struct MidiPair) * size);
	 
	for (int i = 0; i < size; i++)
		_midiPairs[i] = (struct MidiPair){.value = arr[i], .other = rnd(1, 10)};

	return _midiPairs;
}