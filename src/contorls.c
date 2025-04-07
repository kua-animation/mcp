#include "include/controls.h"

int KeyPress(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		return event.key.keysym.sym;
	}

	return 0;
}
