#include "Map.h"
#include <iostream>

Map::Map() : window(nullptr), renderer(nullptr) {}

Map::~Map() {
	cleanup();
}

bool Map::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Failed to create window! Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    return true;
}

SDL_Window* Map::getWindow() {
    return window;
}

SDL_Renderer* Map::getRenderer() {
    return renderer;
}

void Map::cleanup() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}