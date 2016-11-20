#include "MainGame.h"
GameState MainGame::_gameState;
Scene* MainGame::_nextScene;
int MainGame::_screenHeight;
int MainGame::_screenWidth;

MainGame::MainGame()
{
	_gameState = GameState::MainMenu;
	_window = nullptr;
	_screenSurface = nullptr;
	_currentScene = nullptr;
	_nextScene = nullptr;
	_screenHeight = SCREEN_HEIGHT;
	_screenWidth = SCREEN_WIDTH;
	
}


MainGame::~MainGame()
{
	delete _currentScene;
}

void MainGame::run(Uint32 FPS)
{
	_fps = FPS;
	_delayTime = 1000 / _fps;

	//init MainGame
	init();

	//update MainGame
	update();
}


void MainGame::init()
{

	//init Image Support
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG))
	{
		printf("SDL Image Suport init failed!\n");
	}

	//SDL INIT EVERYTHING
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create Window
	_window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
	// check window error
	if (_window == nullptr)
	{
		printf("SDL window could not init! SDL error : %s\n", SDL_GetError());
	}
	else
	{
		//Get window surface
		//_screenSurface = SDL_GetWindowSurface(_window);

		//Fill the surface white
		//SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0, 0, 255));

		//Update the surface
		//SDL_UpdateWindowSurface(_window);
	}

	//init renderer to draw
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr)
	{
		printf("SDL Renderer could not init! SDL Error : %s\n",SDL_GetError());
	}

	//init Scene
	_currentScene = new MainMenuScene;
	_nextScene = _currentScene;
	_currentScene->init(_renderer);
}

void MainGame::update()
{
	//init
	//first Frame
	Uint32 FrameStart= 0;

	//how long is First Frame
	Uint32 FrameTime = _delayTime;
	//Main Game Loop
	while (_gameState != GameState::Exit)
	{
		//First Frame = Now Time in millisecon
		FrameStart = SDL_GetTicks();
		
		//update Scene
		//check to Change Scene
		if (_currentScene != _nextScene)
		{
			delete _currentScene;
			_currentScene = _nextScene;
			_nextScene = _currentScene;
			_currentScene->init(_renderer);
		}

		//Scene Game Loop
		_currentScene->update(FrameTime);
		_currentScene->inputHandler();
		draw();

		//see how long the frame take to prosess
		FrameTime = SDL_GetTicks() - FrameStart;
		if (FrameTime < _delayTime)
		{
			SDL_Delay(_delayTime - FrameTime);
			FrameTime += _delayTime - FrameTime;
		}
			
	}

	//free memory for the window and de init
	SDL_DestroyWindow(_window);
	_window = nullptr;

	//destroy renderer
	SDL_DestroyRenderer(_renderer);

	SDL_Quit();
	//De init Image Support
	IMG_Quit();
}

void MainGame::draw()
{
	//clear screen first
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);

	//draw to back buffer
	_currentScene->draw();

	//get the back buffer that draw by scene to front
	SDL_RenderPresent(_renderer);
}

