#include <SDL.h>
#include "Map.h"
#include "Snake.h"
#include "Apple.h"

int main(int argc, char* argv[]) {
	Map map;

	if (!map.init()) {
		return 1;
	}

	SDL_Renderer* renderer = map.getRenderer();

	Snake snake;
	Apple apple;

	bool quit = false;
	char prevDirection = NULL;
	SDL_Event e;
	const int fps = 100;
	int desiredDelta = 1000 / fps;

	while (!quit) {
		int startLoop = SDL_GetTicks();
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}

			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym)
				{
				case SDLK_w: snake.move('w'); prevDirection = 'w'; break;
				case SDLK_s: snake.move('s'); prevDirection = 's'; break;
				case SDLK_a: snake.move('a'); prevDirection = 'a'; break;
				case SDLK_d: snake.move('d'); prevDirection = 'd'; break;
				}
			}
		}
	
		if (prevDirection != NULL) {
			snake.move(prevDirection);
		}

		if (snake.isColliding(apple)) {
			snake.grow();
			apple.resetPosition();
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		snake.render(renderer);
		apple.render(renderer);

		SDL_RenderPresent(renderer);

		int delta = SDL_GetTicks() - startLoop;
		if (delta < desiredDelta) {
			SDL_Delay(desiredDelta - delta);
		}
	}

	map.cleanup();
	return 0;
}

