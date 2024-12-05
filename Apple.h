#ifndef APPLE_H
#define APPLE_H

#include <SDL.h>

class Apple
{
public:
	static const int APPLE_SIZE = 15;
	SDL_Rect apple;

	Apple();

	void render(SDL_Renderer* renderer);

	void resetPosition();

	int getX() const;
	int getY() const;

private:
	int x, y;
	int widowWidth, windowHeight;
};


#endif // APPLE_H