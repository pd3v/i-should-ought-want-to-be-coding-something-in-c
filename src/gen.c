#include <math.h>
#include "gen.h"

struct midiPair;

midi_t sum(midi_t value) {
	temp += value;
	return temp;
}

midi_t avg(midi_t sumTotal, unsigned int counter) {
	return  sumTotal / counter;
}

float rnd() {
	return (rand() % 100) / 100.0f;
} 

midi_t rndMidi(midi_t min, midi_t max) {
	return min + rand() % (max + 1 - min);
} 

struct MidiPair* rndWeight(midi_t* arr, size_t size) {
	struct MidiPair* _midiPairs = (struct MidiPair*)  malloc(sizeof (struct MidiPair) * size);
	 
	for (int i = 0; i < size; i++)
		_midiPairs[i] = (struct MidiPair){.value = arr[i], .other = rndMidi(1, 10)};

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

struct MidiPair* sortByWeigth(struct MidiPair* arr, size_t size, bool orderBy) {
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
		_midiStack[i] = rndMidi(min, max);

	return _midiStack;
}

midi_t** populateMidiMatrix(midi_t min, midi_t max, size_t size) {
	midi_t** _midi2d = (midi_t**)malloc(sizeof(midi_t*) * size);
	for (int i = 0; i < size; i++) _midi2d[i] = malloc(sizeof(_midi2d[0]) * size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			_midi2d[i][j] = rndMidi(min, max);
	
	return _midi2d;
}

float** populateMatrix(size_t rows, size_t cols) {
	float** _matrix = (float**)malloc(sizeof(float*) * rows);
	for (int i = 0; i < rows; i++) _matrix[i] = malloc(sizeof(_matrix[0]) * cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			_matrix[i][j] = rnd();

	return _matrix;
}

midi_t toMidi(double value) {
	return (midi_t)round(value);
}

double gaussian(double value, double offset, double spread) {
	return (1.0f / sqrt(2 * M_PI * powf(spread, 2)) * exp(- powf(value - offset, 2) / (2 * powf(spread, 2))));
}

double gaussianInner(double value, double offset, double spread) {
	return gaussian(value, offset, spread) * (rand() % 100 / 100.0f);
}

midi_t* markov(midi_t* arr) {
	return arr;	
}
