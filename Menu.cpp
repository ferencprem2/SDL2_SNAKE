#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "Menu.h"
#include "Map.h"

Menu::Menu(){
	//FIXME: only use this path while starting the game from VS, when running exe -> "main.tt"
	const char fontFile[] =	"./x64/Debug/main.ttf";

	if (TTF_Init() != 0) {
		std::cerr << "Failed to init TTF! Error: " << TTF_GetError() << std::endl;
	}

	font = TTF_OpenFont(fontFile, 24);
	
	if (!font) {
		std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
	}
}

Menu::~Menu() {
	TTF_CloseFont(font);
}

const int WINDOW_HEIGHT = Map::WINDOW_HEIGHT;
const int WINDOW_WIDTH = Map::WINDOW_WIDTH;

void Menu::renderMainMenu(SDL_Renderer* renderer, TTF_Font* font) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_Rect startButton = { 200, 150, 240, 50 };
	SDL_Rect exitButton = { 200, 250, 240, 50 };
	SDL_RenderFillRect(renderer, &startButton);
	SDL_RenderFillRect(renderer, &exitButton);
}

void Menu::renderGameOverScreen(SDL_Renderer* renderer, TTF_Font* font, bool gameOver) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect retryButton = { 200, 150, 240, 50 };
	SDL_Rect quitButton = { 200, 250, 240, 50 };
	SDL_RenderFillRect(renderer, &retryButton);
	SDL_RenderFillRect(renderer, &quitButton);
}

void Menu::renderPauseMenu(SDL_Renderer* renderer, TTF_Font* fonts) {
	const int BTN_X_POS = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
	SDL_SetRenderDrawColor(renderer, 102, 255, 178, 255);
	SDL_Rect resumeButton = { BTN_X_POS, WINDOW_HEIGHT / 2 + BUTTON_HEIGHT, BUTTON_WIDTH, BUTTON_HEIGHT};
	SDL_Rect quitButton = { BTN_X_POS, WINDOW_HEIGHT / 2 - BUTTON_HEIGHT, BUTTON_WIDTH, BUTTON_HEIGHT};
	SDL_RenderFillRect(renderer, &resumeButton);
	SDL_RenderFillRect(renderer, &quitButton);

	SDL_Color color = { 0, 0, 0, 255 };
	renderText(renderer, font, "Resume", BTN_X_POS, WINDOW_HEIGHT / 2 + BUTTON_HEIGHT, color);
	renderText(renderer, font, "Quit", BTN_X_POS, WINDOW_HEIGHT / 2 - BUTTON_HEIGHT, color);

	SDL_RenderPresent(renderer);
}

void Menu::renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y, SDL_Color color) {
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	if (!textSurface) {
		std::cerr << "Failed to create text surface! Error: " << SDL_GetError() << "||" << TTF_GetError() << std::endl;
	}

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (!textTexture) {
		std::cerr << "Failed to create text texture! Error: " << SDL_GetError() << "||" << TTF_GetError() << std::endl;
		SDL_FreeSurface(textSurface);
		return;
	}

	SDL_Rect destRect = { x, y, textSurface->w, textSurface->h };

	SDL_RenderCopy(renderer, textTexture, nullptr ,&destRect);

	SDL_DestroyTexture(textTexture);
	SDL_FreeSurface(textSurface);

}

void Menu::handleMenuClickEvent(SDL_Event event, SDL_Window* window) {
	int mousePosX = event.button.x;
	int mousePosY = event.button.y;

	if (mousePosX < Map::WINDOW_WIDTH && mousePosX > 0 && mousePosY < Map::WINDOW_HEIGHT && mousePosY > 0) {
		std::string message = "Pos X: " + std::to_string(mousePosX) + "\nPos Y: " + std::to_string(mousePosY);
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mouse Event", message.c_str(), window);
	}
}