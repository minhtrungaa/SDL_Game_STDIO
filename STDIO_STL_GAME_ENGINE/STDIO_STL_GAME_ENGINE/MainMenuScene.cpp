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
	if (_btnPlay->_buttonState == ButtonState::CLICKED)
	{
		printf("Mouse Clicked with Button Play Rect\n");
		_btnPlay->_buttonState = ButtonState::NORMAL;
	}
	if (_btnExit->_buttonState == ButtonState::CLICKED)

	{
		MainGame::_gameState = GameState::Exit;
		_btnExit->_buttonState == ButtonState::NORMAL;
	}
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
			//Mouse Event Motion
		case SDL_MOUSEMOTION:
			_btnPlay->addButtonHoverListener(Event.motion.x, Event.motion.y);
			_btnExit->addButtonHoverListener(Event.motion.x, Event.motion.y);
			break;
			//Mouse Button DOWN
		case SDL_MOUSEBUTTONUP:
			if (Event.button.button == SDL_BUTTON_LEFT)
			{
				_btnPlay->addButtonClickListener(Event.motion.x, Event.motion.y);
				_btnExit->addButtonClickListener(Event.motion.x, Event.motion.y);
			}
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
