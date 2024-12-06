#ifndef MENU_H
#define MENU_H
#include <SDL_ttf.h>
#include <string>


class Menu
{
public:
	TTF_Font* font;
	
	static const int BUTTON_WIDTH = 120;
	static const int BUTTON_HEIGHT = 50;

	void renderMainMenu(SDL_Renderer* renderer, TTF_Font* font);
	void renderGameOverScreen(SDL_Renderer* renderer, TTF_Font* font, bool isGameOver);
	void renderPauseMenu(SDL_Renderer* renderer, TTF_Font* font);
	void handleMenuClickEvent(SDL_Event event, SDL_Window* window);
	void renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y, SDL_Color color);
	Menu();
	~Menu();
private: 
};
#endif // !MENU_H
