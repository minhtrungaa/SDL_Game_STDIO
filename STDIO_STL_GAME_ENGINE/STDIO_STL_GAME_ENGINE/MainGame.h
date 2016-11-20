#pragma once
#include<SDL.h>
#include<stdio.h>
#include"Scene.h"
#include"MainMenuScene.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

enum GameState
{
	MainMenu,
	GamePlay,
	Exit,
};

class MainGame
{
public:
	//functions and constructor
	MainGame();
	~MainGame();
	void run(Uint32 FPS);

	//variables
	static GameState _gameState;

private:
	//functions
	void init();
	void update();
	void draw();

	//variables
	int _screenWidth;
	int _screenHeight;	
	SDL_Window* _window;
	SDL_Surface* _screenSurface;
	Scene* _currentScene;
	Scene* _nextScene;
	Uint32 _fps;
	Uint32 _delayTime;
	SDL_Renderer* _renderer;
};

