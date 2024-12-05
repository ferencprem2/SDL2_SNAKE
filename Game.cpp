#include <SDL.h>
#include "Game.h"

Game::Game() {};

bool Game::gameOver() {
	return false;
}

bool Game::startGame() {
	return true;
}

Game::GameTypes Game::selectGameType() {
	return Game::Advanced;
}