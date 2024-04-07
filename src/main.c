#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include "gen.h"

void *sequencer(void* param) {
	struct timespec sleepDur = {125 / 1000, (125 % 1000) * 1000000L}; 
	unsigned int cntr = 0;
	float spread = 0.1;

	while (1) {
		if ((cntr++ % 8) == 0) {
			spread = (rand() % 1000) / 1000.0f * 2.0f;
			printf("\n\nspread (σ):%f\n", spread);
		}

		midi_t gaussainedMidi = MIDI_MAX * gaussianInner(rnd(MIDI_MIN, MIDI_MAX) / MIDI_MAX, 1, spread);
		printf("%d ", gaussainedMidi < 127 ? gaussainedMidi : 127); 
		fflush(stdout);

		nanosleep(&sleepDur, NULL);
	}

	return NULL;
};

int main() {
	srand((unsigned int)time(NULL));
	pthread_t th; 
 
  printf("\ngenerating random MIDI values out a gaussian func\n");
	printf("-------------------------------------------------\n");

	pthread_create(&th, NULL, &sequencer, NULL);
	pthread_join(th, NULL);
	pthread_exit(NULL);


	/*
	// Adding random weight to every midi value in a midi array and asc sorting

	printf("\nadding random weight to every midi value in a midi array and asc sorting\n");
	
	midi_t midiArr[] = {10,20,30,40,60,9,21,32,43,64,14,25,36,47,68};
	size_t size = sizeof(midiArr) / sizeof(midiArr[0]);

	struct MidiPair* midiArrW = rndW(midiArr, size);

	printf("\nunsorted midi values with added weights\n");
	for (int i = 0; i < size; i++)
		printf("[%i %i] ", midiArrW[i].value, midiArrW[i].other);
	
	midiArrW = sortW(midiArrW, size, 1);

	printf("\nmidi values asc sorted by added weights\n");
	for (int i = 0; i < size; i++)
			printf("[%i %i] ", midiArrW[i].value, midiArrW[i].other);

	printf("\n");

	free(midiArrW);
 	*/  

 	return 0;
}