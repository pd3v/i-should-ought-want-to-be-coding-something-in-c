#include <stdio.h>
#include <time.h>
#include <pthread.h>
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
	pthread_t th; 

  printf("\ngenerating random MIDI values\n");
	printf("------------------------------\n");

	pthread_create(&th, NULL, &sequencer, NULL);
	pthread_join(th, NULL);
	pthread_exit(NULL);
	
  return 0;
}