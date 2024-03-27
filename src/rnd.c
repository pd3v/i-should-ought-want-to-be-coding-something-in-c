#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "rnd.h"

#define MIDI_STACK_SIZE 1000

midi_t rnd(midi_t min , midi_t max) {
	return min + rand() % (max - min);
}

void fillStack(midi_t* arr, int size, midi_t min, midi_t max) {
	for (int i = 0; i < size; i++)
		arr[i] = rnd(min, max);
}

int main () {
	srand((unsigned int)time(NULL));

	midi_t midiStack[MIDI_STACK_SIZE];

	fillStack(midiStack, MIDI_STACK_SIZE, 0, 127);
	int length = sizeof(midiStack) / sizeof(*midiStack);

	for (int i = 0; i < length; i++)
		printf("midiStack[%i]= %i\n", i, midiStack[i]);
	
	return 0;
}
