#include "Text.h"



Text::Text()
{
}

Text::Text(SDL_Renderer* renderer, char * text,char* font)
{
	_renderer = renderer;
	//init TTF lib to use TTF font support
	if (TTF_Init() == -1)
		printf("Text TTF init Failed! Error : %s\n", SDL_GetError());
	//load font
	_textFont = TTF_OpenFont(font, 20);

	SDL_Surface* textSurface = TTF_RenderText_Solid(_textFont, text, _textColor);

	_textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);

	//get Text Size and set to default size
	TTF_SizeText(_textFont, text, &_textRect.w, &_textRect.h);
	
	SDL_FreeSurface(textSurface);

}



Text::~Text()
{
	TTF_CloseFont(_textFont);
}

void Text::draw()
{
	SDL_RenderCopy(_renderer, _textTexture, NULL, &_textRect);
}