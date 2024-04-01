typedef unsigned int midi_t;

midi_t midiStack[100];
midi_t temp;

midi_t sum(midi_t value);
midi_t avg(midi_t sumTotal, unsigned int _counter);
midi_t rnd(midi_t min , midi_t max);
midi_t rndw(midi_t* arr, size_t size);