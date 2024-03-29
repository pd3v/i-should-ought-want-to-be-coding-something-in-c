#include <stdlib.h>
#include "gen.h"

midi_t gen_rnd(midi_t min , midi_t max) {
	return min + rand() % (max - min);
}