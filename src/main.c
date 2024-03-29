#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "gen.h"
#include "rnd.h"

void *sequencer(void *param) {
	struct timespec remaining, request = {1, 100}; 

	while (1) {
		printf(" %i", gen_rnd(0, 127));
		fflush(stdout);
		nanosleep(&request, &remaining);
	}

	return NULL;
};

int main() {
  printf("\ngenerating random MIDI values\n");
	printf("------------------------------\n");

	pthread_t ti; 
	pthread_create(&ti, NULL, &sequencer, NULL);
	pthread_join(ti, NULL);
	pthread_exit(NULL);
	
  return 0;
}