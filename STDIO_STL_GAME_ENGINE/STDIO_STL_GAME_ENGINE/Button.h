#pragma once
#include<stdio.h>
#include<SDL.h>
#include<SDL_image.h>

class Button
{
public:
	Button();
	Button(const char* sourcePath, int x, int y, int w, int h, SDL_Renderer* renderer);//init with W and H
	Button(const char* sourcePath, int x, int y, SDL_Renderer* renderer);//init with Default texture W and H
	Button(const char* sourcePath, SDL_Renderer* renderer);//init with no x y but have W and H have to manually set pos
	~Button();
	void init();
	void update(float dt);
	void draw();
	void setButtonPosition(int x, int y) { _x = x; _y = y; };
	int getButtonHeight() const { return _h; }
	int getButtonWidth() const { return _w; }

private:
	char* _TXT;
	int _x, _y, _w = 190, _h=49;
	SDL_Texture* _texture;
	SDL_Renderer* _renderer;
};

