#include "Button.h"



Button::Button()
{
	_texture = nullptr;
}

Button::Button(const char * sourcePath, int x, int y, int w, int h,SDL_Renderer* renderer):
	_x(x),_y(y),_h(h),_w(w),_renderer(renderer)
{
	SDL_Surface* surface = IMG_Load(sourcePath);
	if (surface == nullptr)
	{
		printf("Button Failed to init Surface! error : %s\n",SDL_GetError());
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_FreeSurface(surface);
}

Button::Button(const char * sourcePath, int x, int y, SDL_Renderer * renderer):
_x(x), _y(y), _renderer(renderer)
{
	SDL_Surface* surface = IMG_Load(sourcePath);
	if (surface == nullptr)
	{
		printf("Button Failed to init Surface! error : %s\n", SDL_GetError());
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	//get Texture size and set _w _h
	SDL_QueryTexture(_texture, NULL, NULL, &_w, &_h);

	SDL_FreeSurface(surface);
}

Button::Button(const char * sourcePath, SDL_Renderer * renderer) :
_renderer(renderer)
{
	SDL_Surface* surface = IMG_Load(sourcePath);
	if (surface == nullptr)
	{
		printf("Button Failed to init Surface! error : %s\n", SDL_GetError());
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	//get Texture size and set _w _h
	SDL_QueryTexture(_texture, NULL, NULL, &_w, &_h);

	SDL_FreeSurface(surface);
}


Button::~Button()
{
	SDL_DestroyTexture(_texture);

}

void Button::init()
{
}

void Button::update(float dt)
{
}

void Button::draw()
{
	SDL_Rect rect;
	rect.x = _x;
	rect.y = _y;
	rect.h = _h;
	rect.w = _w;

	//draw Button
	SDL_RenderCopy(_renderer, _texture, NULL, &rect);
	//draw Button Text
	//arial.ttf
}
