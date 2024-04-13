#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIDI_MIN 0.0f
#define MIDI_MAX 127.0f

typedef unsigned int midi_t;
typedef float** matrixf_t;

struct MidiPair {
	midi_t value; 
	unsigned int other;
};

midi_t midiStack[12];
midi_t midi2D[12][12];
struct MidiPair midiPairStack[12];
midi_t temp;

midi_t sum(midi_t value);
midi_t avg(midi_t sumTotal, unsigned int counter);
float rnd();
midi_t rndMidi(midi_t min, midi_t max);
struct MidiPair* rndWeight(midi_t* arr, size_t size);

midi_t* sort(midi_t* arr, size_t size, bool orderBy);
struct MidiPair* sortByWeigth(struct MidiPair* arr, size_t size, bool orderBy);

midi_t* populateMidiStack(midi_t min, midi_t max, size_t size);
midi_t** populateMidiMatrix(midi_t min, midi_t max, size_t size);
float** populateMatrix(size_t rows, size_t cols);
midi_t toMidi(double value);

double gaussian(double value, double offset, double spread);
double gaussianInner(double value, double offset, double spread);

midi_t* markov(midi_t* arr);