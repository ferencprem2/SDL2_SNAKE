#include <SDL.h>
#include "Apple.h"
#include "Map.h"
#include <cstdlib>
#include <ctime>

Apple::Apple() {
	static bool seeded = false;

	if (!seeded) {
		std::srand(std::time(nullptr));
		seeded = true;
	}

	resetPosition();
}

void Apple::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_Rect apple = { x, y, APPLE_SIZE, APPLE_SIZE };
	SDL_RenderFillRect(renderer, &apple);
}

void Apple::resetPosition() {
	x = (std::rand() % (Map::WINDOW_WIDTH / APPLE_SIZE)) * APPLE_SIZE;
	y = (std::rand() % (Map::WINDOW_HEIGHT / APPLE_SIZE)) * APPLE_SIZE;
}

int Apple::getX() const {
	return x;
}

int Apple::getY() const {
	return y;
}


