#pragma once
#include<SDL.h>
#include<stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

enum class GameState
{
	PLAY,
	EXIT
};

class MainGame
{
public:
	MainGame();
	~MainGame();
	void run();

private:
	//functions
	void init();
	void update();
	void draw();
	void processInput();

	//variables
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;
	SDL_Window* _window;
};

