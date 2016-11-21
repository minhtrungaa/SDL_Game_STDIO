#include "Button.h"
#include"MainGame.h"

Button::Button()
{

	_normaltexture = nullptr;
}
Button::Button(const char * sourcePath, SDL_Renderer * renderer, char* title) :
	_renderer(renderer)
{
	_normaltexture = nullptr;
	SDL_Surface* surface = IMG_Load(sourcePath);
	if (surface == nullptr)
	{
		printf("Button Failed to init Surface! error : %s\n", SDL_GetError());
	}

	_normaltexture = SDL_CreateTextureFromSurface(_renderer, surface);

	//get Texture size and set _w _h
	SDL_QueryTexture(_normaltexture, NULL, NULL, &_buttonRect.w, &_buttonRect.h);

	SDL_FreeSurface(surface);

	_renderTexture = _normaltexture;
	//init text for Button
	_title = new Text(_renderer, title, "Arial.ttf");
	//set Text to the center of the butotn
	_title->setTextPosition(_buttonRect.x + (_buttonRect.w / 2 - _title->getTextRect().w / 2), _buttonRect.y + (_buttonRect.h / 2 - _title->getTextRect().h / 2));
}


Button::~Button()
{
	SDL_DestroyTexture(_normaltexture);
	delete _title;
	IMG_Quit();
}

void Button::update(float dt)
{

}

void Button::draw()
{
	//draw Button
	SDL_RenderCopy(_renderer, _renderTexture, NULL, &_buttonRect);
	_title->draw();
}

void Button::setButtonPosition(int x, int y)
{
	_buttonRect.x = x;
	_buttonRect.y = y;
	_title->setTextPosition(_buttonRect.x + (_buttonRect.w / 2 - _title->getTextRect().w / 2), _buttonRect.y + (_buttonRect.h / 2 - _title->getTextRect().h / 2));
}

void Button::setHoverTexture(const char * sourcePath)
{
	SDL_Surface* surface = IMG_Load(sourcePath);
	if (surface == nullptr)
	{
		printf("Button Hover Texture Failed to init Surface! error : %s\n", SDL_GetError());
	}

	_hoverTexture = SDL_CreateTextureFromSurface(_renderer, surface);

	SDL_FreeSurface(surface);
}

void Button::setClickedTexture(const char * sourcePath)
{
	SDL_Surface* surface = IMG_Load(sourcePath);
	if (surface == nullptr)
	{
		printf("Button Hover Texture Failed to init Surface! error : %s\n", SDL_GetError());
	}

	_clickedTexture = SDL_CreateTextureFromSurface(_renderer, surface);

	SDL_FreeSurface(surface);
}

bool Button::isClicked()
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			MainGame::_gameState = GameState::Exit;
			break;
		case SDL_MOUSEMOTION:
			if (Event.motion.x >= _buttonRect.x && Event.motion.x <= _buttonRect.x + _buttonRect.w &&
				Event.motion.y >= _buttonRect.y && Event.motion.y <= _buttonRect.y + _buttonRect.h &&
				_hoverTexture != nullptr)
			{

				_renderTexture = _hoverTexture;
			}
			else
				_renderTexture = _normaltexture;

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (Event.button.button == SDL_BUTTON_LEFT)
			{
				if (Event.motion.x >= _buttonRect.x && Event.motion.x <= _buttonRect.x + _buttonRect.w &&
					Event.motion.y >= _buttonRect.y && Event.motion.y <= _buttonRect.y + _buttonRect.h)
				{
					if (_clickedTexture != nullptr)
						_renderTexture = _clickedTexture;
					return true;
				}
				else
				{

					return false;
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (Event.button.button == SDL_BUTTON_LEFT)
			{
				if (Event.motion.x >= _buttonRect.x && Event.motion.x <= _buttonRect.x + _buttonRect.w &&
					Event.motion.y >= _buttonRect.y && Event.motion.y <= _buttonRect.y + _buttonRect.h)
					_renderTexture = _normaltexture;
			}
			break;
		default:
			break;
		}

	}
	return false;
}