#include "MainMenuScene.h"
#include"MainGame.h"


MainMenuScene::MainMenuScene()
{
}


MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::init()
{
}

void MainMenuScene::update(float dt)
{
}

void MainMenuScene::draw()
{
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
			case SDLK_a:
				printf("you click \'A'\ \n");
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (Event.button.button)
			{
			case SDL_BUTTON_LEFT:
				printf("Left Mouse Down! \n");
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
