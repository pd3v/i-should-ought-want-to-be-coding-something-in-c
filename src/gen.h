#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int midi_t;

struct MidiPair {
	midi_t value; 
	unsigned int other;
};

midi_t midiStack[100];
struct MidiPair midiPairStack[100];
midi_t temp;

midi_t sum(midi_t value);
midi_t avg(midi_t sumTotal, unsigned int counter);
midi_t rnd(midi_t min, midi_t max);
struct MidiPair* rndW(midi_t* arr, size_t size);
midi_t* sort(midi_t* arr, size_t size, bool orderBy);
struct MidiPair* sortW(struct MidiPair* arr, size_t size, bool orderBy);
midi_t* populateMidiStack(midi_t min, midi_t max, size_t size);