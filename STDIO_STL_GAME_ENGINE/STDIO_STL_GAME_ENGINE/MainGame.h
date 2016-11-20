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
	static int getScreenWidth() { return _screenWidth; }
	static int getScreenHeigth() {
		return _screenHeight;
	}

	//variables
	static GameState _gameState;
	static Scene* _nextScene;

private:
	//functions
	void init();
	void update();
	void draw();

	//variables
	static int _screenWidth;
	static int _screenHeight;
	SDL_Window* _window;
	SDL_Surface* _screenSurface;
	Scene* _currentScene;
	Uint32 _fps;
	Uint32 _delayTime;
	SDL_Renderer* _renderer;
};

