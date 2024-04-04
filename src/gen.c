#include "gen.h"

struct midiPair;

midi_t sum(midi_t value) {
	temp += value;
	return temp;
}

midi_t avg(midi_t sumTotal, unsigned int counter) {
	return  sumTotal / counter;
}

midi_t rnd(midi_t min, midi_t max) {
	return min + rand() % (max + 1 - min);
} 

struct MidiPair* rndW(midi_t* arr, size_t size) {
	struct MidiPair* _midiPairs = (struct MidiPair*)  malloc(sizeof (struct MidiPair) * size);
	 
	for (int i = 0; i < size; i++)
		_midiPairs[i] = (struct MidiPair){.value = arr[i], .other = rnd(1, 10)};

	return _midiPairs;
}

midi_t* sort(midi_t* arr, size_t size) {
	int i, j, temp;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
				if (arr[j] > arr[j + 1]) {
	 				temp = arr[j];
    			arr[j] = arr[j+1];
    			arr[j+1] = temp;
				}

	return arr;
}

struct MidiPair* sortW(struct MidiPair* arr, size_t size) {
	struct MidiPair temp;
	int i, j;
	
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
				if (arr[j].other > arr[j + 1].other) {
	 				temp = arr[j];
    			arr[j] = arr[j+1];
    			arr[j+1] = temp;
				}

	return arr;
}

midi_t* populateMidiStack(midi_t min, midi_t max, size_t size) {
	midi_t* _midiStack = (midi_t*) malloc(sizeof (midi_t) * size);

	for (int i = 0; i < size; i++)
		_midiStack[i] = rnd(min, max);

	return _midiStack;
}