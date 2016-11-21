#include "MainMenuScene.h"
#include"MainGame.h"


MainMenuScene::MainMenuScene()
{
}


MainMenuScene::~MainMenuScene()
{
	delete _btnPlay;
	delete _btnExit;
}

void MainMenuScene::init(SDL_Renderer* renderer)
{
	//init new button
	_btnPlay = new Button("ButtonUp.png", renderer, "PLAY");
	_btnPlay->setButtonPosition(MainGame::getScreenWidth() / 2 - _btnPlay->getButtonWidth() / 2, MainGame::getScreenHeigth() / 2 - _btnPlay->getButtonHeight() / 2);
	_btnPlay->setClickedTexture("ButtonDown.png");
	// btn Exit
	_btnExit = new Button("ButtonUp.png", renderer, "EXIT");
	_btnExit->setButtonPosition(MainGame::getScreenWidth() / 2 - _btnExit->getButtonWidth() / 2,
								MainGame::getScreenHeigth() / 2 + _btnExit->getButtonHeight());
	_btnExit->setClickedTexture("ButtonDown.png");
	_renderer = renderer;
}

void MainMenuScene::update(float dt)
{
	if (_btnPlay->isClicked())
		printf("BUTTON PLAY CLICKED!\n");
	if (_btnExit->isClicked())
		printf("BUTTON EXIT CLICKED!\n");
}

void MainMenuScene::draw()
{
	_btnPlay->draw();
	_btnExit->draw();
	
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
			//Mouse Event
		case SDL_MOUSEMOTION:
			//printf("%d-%d\n", Event.motion.x, Event.motion.y);
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
