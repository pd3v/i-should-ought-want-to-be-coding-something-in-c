#include "stdio.h"
#include "rnd.h"

int main() {
  printf("It's a start! :) \n");

	midi_t midiStack[MIDI_STACK_SIZE];

	fillStack(midiStack, MIDI_STACK_SIZE, 0, 127);
	int length = sizeof(midiStack) / sizeof(*midiStack);

	for (int i = 0; i < length; i++)
		printf("midiStack[%i]= %i\n", i, midiStack[i]);
	
  return 0;
}