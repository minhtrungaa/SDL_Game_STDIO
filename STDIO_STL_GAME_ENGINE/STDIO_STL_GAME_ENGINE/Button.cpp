#include "Button.h"
#include"MainGame.h"

Button::Button()
{

	_normaltexture = nullptr;
}
Button::Button(const char * sourcePath, SDL_Renderer * renderer, char* title) :
	_renderer(renderer)
{
	_buttonState = ButtonState::NORMAL;
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
	if(_buttonState == ButtonState::NORMAL)
		SDL_RenderCopy(_renderer, _normaltexture, NULL, &_buttonRect);
	else if (_buttonState == ButtonState::HOVER && _hoverTexture != nullptr)
		SDL_RenderCopy(_renderer, _hoverTexture, NULL, &_buttonRect);
	else if (_buttonState == ButtonState::CLICKED && _clickedTexture != nullptr)
		SDL_RenderCopy(_renderer, _clickedTexture, NULL, &_buttonRect);

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

void Button::addButtonHoverListener(int x, int y)
{
	if (x >= _buttonRect.x && x <= _buttonRect.x + _buttonRect.w &&
		y >= _buttonRect.y && y <= _buttonRect.y + _buttonRect.h)
	{
		if (_hoverTexture == nullptr)
			printf("Hover Texture for Button is NULL! \n");
		else
		_buttonState = ButtonState::HOVER;
	}
	else
		_buttonState = ButtonState::NORMAL;
}

void Button::addButtonClickListener(int x, int y)
{
	if (x >= _buttonRect.x && x <= _buttonRect.x + _buttonRect.w &&
		y >= _buttonRect.y && y <= _buttonRect.y + _buttonRect.h)
	{
		_buttonState = ButtonState::CLICKED;
	}
	else
		_buttonState = ButtonState::NORMAL;
}
