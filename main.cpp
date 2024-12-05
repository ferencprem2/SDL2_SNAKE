#include <SDL.h>
#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include "Game.h"
#include "Menu.h"


int main(int argc, char* argv[]) {
	Map map;

	if (!map.init()) {
		return 1;
	}

	SDL_Renderer* renderer = map.getRenderer();

	Snake snake;
	Apple apple;
	Game game;
	Menu menu;
	//SDL_Window* window = map.getWindow();

	SDL_Event event;

	bool quit = false;
	bool paused = false;
	char prevDirection = NULL;
	char direction = NULL;
	while (!quit) {
		int startLoop = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym)
				{
				case SDLK_w: direction = 'w'; break;
				case SDLK_s: direction = 's'; break;
				case SDLK_a: direction = 'a'; break;
				case SDLK_d: direction = 'd'; break;
				case SDLK_ESCAPE: paused = !paused; menu.renderPauseMenu(renderer); break;
				}
			}

			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.clicks == SDL_BUTTON_LEFT) {
				menu.handleMenuClickEvent(event, map.getWindow());
			}
		}
	
		if (snake.isColliding(apple)) {
			snake.grow();
			apple.resetPosition();
		}

		// TODO: Make a game over function
		if (snake.isWallHit()) quit = true;

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		if (!paused) {
			if (snake.isValidDirection(direction, prevDirection)) {
				snake.move(direction);
				prevDirection = direction;
			}
			else {
				snake.move(prevDirection);
			}		
			snake.render(renderer);
			apple.render(renderer);

			SDL_RenderPresent(renderer);
		}

		int delta = SDL_GetTicks() - startLoop;
		if (delta < game.DESIRED_DELTA) {
			SDL_Delay(game.DESIRED_DELTA - delta);
		}
	}

	map.cleanup();
	return 0;
}

