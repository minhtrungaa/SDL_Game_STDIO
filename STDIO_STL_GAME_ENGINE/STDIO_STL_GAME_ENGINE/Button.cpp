#include "Button.h"

Button::Button()
{

	_texture = nullptr;
}
Button::Button(const char * sourcePath, SDL_Renderer * renderer, char* title) :
_renderer(renderer)
{
	_texture = nullptr;
	SDL_Surface* surface = IMG_Load(sourcePath);
	if (surface == nullptr)
	{
		printf("Button Failed to init Surface! error : %s\n", SDL_GetError());
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	//get Texture size and set _w _h
	SDL_QueryTexture(_texture, NULL, NULL, &_buttonRect.w, &_buttonRect.h);


	SDL_FreeSurface(surface);
	//init text for Button
	_title = new Text(_renderer, title, "Arial.ttf");
	//set Text to the center of the butotn
	_title->setTextPosition(_buttonRect.x +(_buttonRect.w/2 - _title->getTextRect().w/2), _buttonRect.y + (_buttonRect.h/2-_title->getTextRect().h/2));
}


Button::~Button()
{
	SDL_DestroyTexture(_texture);
	delete _title;
	IMG_Quit();
}

void Button::update(float dt)
{
}

void Button::draw()
{
	//draw Button
	SDL_RenderCopy(_renderer, _texture, NULL, &_buttonRect);
	_title->draw();
}

void Button::setButtonPosition(int x, int y)
{
	_buttonRect.x = x;
	_buttonRect.y = y;
	_title->setTextPosition(_buttonRect.x + (_buttonRect.w / 2 - _title->getTextRect().w / 2), _buttonRect.y + (_buttonRect.h / 2 - _title->getTextRect().h / 2));
}
