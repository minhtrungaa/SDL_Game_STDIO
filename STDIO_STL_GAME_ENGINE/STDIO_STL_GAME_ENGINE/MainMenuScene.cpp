#include "MainMenuScene.h"
#include"MainGame.h"


MainMenuScene::MainMenuScene()
{
}


MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::init(SDL_Renderer* renderer)
{
	
	_renderer = renderer;
}

void MainMenuScene::update(float dt)
{
}

void MainMenuScene::draw()
{
	Text text(_renderer,"TEST","Arial.ttf");
	text.setTextPosition(MainGame::getScreenWidth() / 2 , MainGame::getScreenHeigth() / 2);
	text.draw();
}

void MainMenuScene::inputHandler()
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
			// if quit
		case SDL_QUIT:
			MainGame::_gameState = GameState::Exit;
			break;
			// keyboard event input
		case SDL_KEYDOWN:
			switch (Event.key.keysym.sym)
			{
			case SDLK_SPACE:
				break;
			case SDLK_RETURN:

				break;
			default:
				break;
			}
		default:
			break;
		}
	}
}
