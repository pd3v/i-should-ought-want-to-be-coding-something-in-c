#include <stdlib.h>
#include "rnd.h"

midi_t rnd_rnd(midi_t min , midi_t max) {
	return min + rand() % (max - min);
}

void fillStack(midi_t* arr, int size, midi_t min, midi_t max) {
	for (int i = 0; i < size; i++)
		arr[i] = rnd_rnd(min, max);
}