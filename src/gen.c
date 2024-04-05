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

midi_t* swap(midi_t* arr, midi_t i, midi_t j) {
	midi_t temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	return arr;
}

struct MidiPair* swapMidiPair(struct MidiPair* arr, midi_t i, midi_t j) {
	struct MidiPair temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	return arr;
}

midi_t* sort(midi_t* arr, size_t size, bool orderBy) {
	int i, j, temp;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (orderBy == 0) {
				if (arr[j] > arr[j + 1])
					swap(arr, j, j+1);
			} else {
					if (arr[j] < arr[j + 1])
						swap(arr, j, j+1);
			}
	return arr;
}

struct MidiPair* sortW(struct MidiPair* arr, size_t size, bool orderBy) {
	struct MidiPair temp;
	int i, j;
	
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
				if (orderBy == 0) {
					if (arr[j].other > arr[j + 1].other)
						swapMidiPair(arr, j, j+1);
				} else {
					if (arr[j].other < arr[j + 1].other)
						swapMidiPair(arr, j, j+1);
				}
				
	return arr;
}

midi_t* populateMidiStack(midi_t min, midi_t max, size_t size) {
	midi_t* _midiStack = (midi_t*) malloc(sizeof (midi_t) * size);

	for (int i = 0; i < size; i++)
		_midiStack[i] = rnd(min, max);

	return _midiStack;
}