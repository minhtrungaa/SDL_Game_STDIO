#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"Scene.h"
#include"Button.h"
#include"Text.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	~MainMenuScene();
	void init(SDL_Renderer* _renderer) override;
	void update(float dt) override;
	void draw() override;
	void inputHandler() override;

private:
	Button* _btnPlay;
};

