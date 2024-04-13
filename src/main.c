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
	/* pthread_t th; 
 
  printf("\ngenerating random MIDI values out of a gaussian func\n");
	printf("-------------------------------------------------\n");

	pthread_create(&th, NULL, &sequencer, NULL);
	pthread_join(th, NULL);
	pthread_exit(NULL);
	*/
	
	midi_t** genArr2d = populateMidiMatrix(24,84,8);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("[%i][%i]= %d ", i, j, genArr2d[i][j]);

		printf("\n");
	}

	printf("\n");

	float** probabilities = populateMatrix(3,4);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			printf("[%i][%i]= %f ", i, j, probabilities[i][j]);

		printf("\n");
	}

	for (int i = 0; i < 4; i++)
		free(probabilities[i]);
	
	free(probabilities);

	for (int i = 0; i < 8; i++)
		free(genArr2d[i]);
	
	free(genArr2d);

	// float** genArrFloat = populateMatrix(3,3);
	// for (int i = 0; i < 3; ++i)
	// 	for (int j = 0; j < 3; ++j)
			// printf("[%i][%i]=%f ", 0, 0, genArrFloat[0][0]);
	// genArr = markov(genArr);
	

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