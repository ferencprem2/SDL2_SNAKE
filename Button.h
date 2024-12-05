#ifndef BUTTON_H
#define BUTTON_H
#include <SDL.h>
#include <string>

class Button
{
public:
	int x, y, width, height;
	SDL_Color color;
	std::string label;

	//Button(int x, int y, int width, int height, SDL_Color color, std::string label) : x(x), y(y), width(width), height(height), color(color), label(label) {}


};

#endif // BUTTON_H