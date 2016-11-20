#include "MainMenuScene.h"
#include"MainGame.h"


MainMenuScene::MainMenuScene()
{
}


MainMenuScene::~MainMenuScene()
{
	delete _btnPlay;
}

void MainMenuScene::init(SDL_Renderer* renderer)
{
	
	_renderer = renderer;
	_btnPlay = new Button("ButtonUP.png",_renderer,"PLAY");
	_btnPlay->setButtonPosition(MainGame::getScreenWidth() / 2 - _btnPlay->getButtonWidth() / 2, 
		MainGame::getScreenHeigth() / 2 - _btnPlay->getButtonWidth() / 2);
}

void MainMenuScene::update(float dt)
{
}

void MainMenuScene::draw()
{
	_btnPlay->draw();
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
