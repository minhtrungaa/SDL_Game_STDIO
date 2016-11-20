#pragma once
#include<stdio.h>
#include<SDL.h>
class Scene
{
public:
	Scene();
	~Scene();
	virtual void init(SDL_Renderer* renderer);
	virtual void update(float dt);
	virtual void draw();
	virtual void inputHandler();
protected:
	SDL_Renderer* _renderer;
};

