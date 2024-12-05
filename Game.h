#ifndef GAME_H
#define GAME_H


class Game
{
public:
	int DESIRED_DELTA = 1000 / FPS;

	static enum GameTypes
	{
		Regular,
		Advanced
	};

	static enum GameStates {
		MainMenu,
		Playing,
		Paused, 
		GameOver
	};

	Game();



	bool gameOver();
	bool startGame();

	GameTypes selectGameType();

private:
	static const int FPS = 100;


};

#endif // !GAME_H
