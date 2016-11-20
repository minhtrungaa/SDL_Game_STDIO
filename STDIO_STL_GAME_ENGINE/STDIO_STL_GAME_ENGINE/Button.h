#pragma once
#include<stdio.h>
#include<SDL.h>
#include<SDL_image.h>
#include"Text.h"

class Button
{
public:
	Button();
	Button(const char* sourcePath, SDL_Renderer* renderer, char* Title);//init with no x y but have W and H Default size have to manually set pos
	~Button();
	void update(float dt);
	void draw();
	void setButtonPosition(int x, int y);
	int getButtonHeight() const { return _buttonRect.h; }
	int getButtonWidth() const { return _buttonRect.w; }
	void setHoverTexture(const char* sourcePath);
	void setClickedTexture(const char* sourcePath);
	bool isClicked();

private:
	SDL_Texture* _renderTexture;
	SDL_Texture* _normaltexture;
	SDL_Texture* _hoverTexture;
	SDL_Texture* _clickedTexture;
	SDL_Renderer* _renderer;
	SDL_Rect _buttonRect;
	Text* _title;
};

