#include <stdio.h>
#include <stdlib.h>

typedef unsigned int midi_t;

struct midiPair {
	midi_t value; 
	unsigned int weight;
};

midi_t midiStack[100];
struct midiPair midiPairStack[100];
midi_t temp;

midi_t sum(midi_t value);
midi_t avg(midi_t sumTotal, unsigned int _counter);
midi_t rnd(midi_t min , midi_t max);
void rndW(midi_t* arr, size_t size);