#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include "gen.h"

void *sequencer(void* param) {
	struct timespec sleepDur = {500 / 1000, (500 % 1000) * 1000000L}; 
	midi_t aValue, sums;
	unsigned int cntr = 0;

	while (1) {
		aValue = rnd(0, 127);
		sums = sum(aValue);
		++cntr;
		
		printf("%u\tsum:%u\tavg:%u\tcntr:%u\n", aValue, sums, avg(sums, cntr), cntr);
		fflush(stdout);
		nanosleep(&sleepDur, NULL);
	}

	return NULL;
};

int main() {
	srand((unsigned int)time(NULL));

	/*
	pthread_t th; 
 
  printf("\ngenerating random MIDI values\n");
	printf("------------------------------\n");

	pthread_create(&th, NULL, &sequencer, midiArr);
	pthread_join(th, NULL);
	pthread_exit(NULL);
  */

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

  return 0;
}