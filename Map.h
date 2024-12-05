#ifndef MAP_H
#define MAP_H

#include <SDL.h>

class Map {
public: 
	// Window dimensions
	static const int WINDOW_WIDTH = 640;
	static const int WINDOW_HEIGHT = 480;

	Map();
	~Map();

	bool init();

	SDL_Renderer* getRenderer();

	void cleanup();

private: 
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif // MAP_H