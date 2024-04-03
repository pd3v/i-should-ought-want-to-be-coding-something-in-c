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

	printf("\nadding random weight to every midi value in midiArr\n\n");

	size_t sz = 15;
	midi_t midiArr[15] = {10,20,30,40,60,10,20,30,40,60,10,20,30,40,60};
	struct MidiPair* midis = rndW(midiArr, sz);

	for (int i = 0; i < sz; i++)
		printf("[%i %i] ", midis[i].value, midis[i].other);

  return 0;
}