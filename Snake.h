#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <vector>
#include "Apple.h"

class Snake {
public:
	Snake();

	void move(char direction);

	void render(SDL_Renderer* renderer);

	bool isColliding(Apple apple);
	bool isWallHit();

	int getHeadX();
	int getHeadY();

	bool isValidDirection(char direction, char prevDirection);

	void grow();

private:
	struct Segment {
		int x, y;
	};

	int snakeLength;

	std::vector<Segment> body;

	static const int SEGMENT_SIZE = 20;
	static const int GROWTH_AMOUNT = 10;
};

#endif // SNAKE_H
