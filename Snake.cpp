#include "Snake.h"
#include "Map.h"

Snake::Snake() {
	body.push_back({ Map::WINDOW_WIDTH / 2, Map::WINDOW_HEIGHT / 2 });
}

void Snake::move(char direction) {
	Segment newHead = body.front();

	switch (direction)
	{
		case 'w': newHead.y -= SEGMENT_SIZE / 10; break;
		case 's': newHead.y += SEGMENT_SIZE / 10; break;
		case 'a': newHead.x -= SEGMENT_SIZE / 10; break;
		case 'd': newHead.x += SEGMENT_SIZE / 10; break;
	}

	body.insert(body.begin(), newHead);
	body.pop_back();
}

int Snake::getHeadX() {
	return body.empty() ? 0 : body.front().x;
}

int Snake::getHeadY() {
	return body.empty() ? 0 : body.front().y;
}

void Snake::grow() {
	if (!body.empty()) {
		Segment tail = body.back();

		for (int i = 0; i < GROWTH_AMOUNT; i++) {
			Segment newSegment = tail;

			if (body.size() > 1) {
				Segment beforeTail = *(body.end() - 2);
				if (tail.x > beforeTail.x) {
					newSegment.x -= SEGMENT_SIZE;
				}
				else if (tail.x < beforeTail.x) {
					newSegment.x += SEGMENT_SIZE;
				}
				else if (tail.y > beforeTail.y) {
					newSegment.y -= SEGMENT_SIZE;
				}
				else if (tail.y < beforeTail.y) {
					newSegment.y += SEGMENT_SIZE;
				}
			}
			else {
				newSegment.x -= SEGMENT_SIZE;
			}

			body.push_back(newSegment);
		}
	}
}

bool Snake::isColliding(Apple apple) {
	int snakeX = this->getHeadX();
	int snakeY = this->getHeadY();
	int appleX = apple.getX();
	int appleY = apple.getY();
	int appleSize = Apple::APPLE_SIZE;
	return snakeX < appleX + appleSize && snakeX + SEGMENT_SIZE > appleX && snakeY < appleY + appleSize && snakeY + SEGMENT_SIZE > appleY;
}

void Snake::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	for (const auto& segment : body) {
		SDL_Rect rect = { segment.x, segment.y, SEGMENT_SIZE, SEGMENT_SIZE };
		SDL_RenderFillRect(renderer, &rect);
	}
}