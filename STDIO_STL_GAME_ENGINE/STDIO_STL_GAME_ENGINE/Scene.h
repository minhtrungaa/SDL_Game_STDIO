#pragma once
#include<stdio.h>
class Scene
{
public:
	Scene();
	~Scene();
	virtual void init();
	virtual void update(float dt);
	virtual void draw();
	virtual void inputHandler();
};

