#include "MainGame.h"



MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	_window = nullptr;
	_screenHeight = SCREEN_HEIGHT;
	_screenWidth = SCREEN_WIDTH;
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	//init MainGame
	init();

	//update MainGame
	update();
}

void MainGame::init()
{
	//SDL INIT EVERYTHING
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create Window
	_window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
	// check window error
	if (_window == nullptr)
	{
		printf("SDL window could not init! SDL error : %s\n", SDL_GetError());
	}
}

void MainGame::update()
{
	while (_gameState != GameState::EXIT)
	{

	}
}

void MainGame::draw()
{

}

void MainGame::processInput()
{

}
