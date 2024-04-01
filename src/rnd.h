#define MIDI_STACK_SIZE 1000

typedef unsigned int midi_t;

midi_t rnd_rnd(midi_t min , midi_t max);
void fillStack(midi_t* arr, int size, midi_t min, midi_t max);