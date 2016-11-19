#pragma once
#include<SDL.h>
#include"Scene.h"
class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	~MainMenuScene();
	void init() override;
	void update(float dt) override;
	void draw() override;
	void inputHandler() override;
};

