#include "SplashState.hpp"
#include <iostream>
#include "assetsAndDefinitions.h"
#include "MainMenu.hpp"

void ld::SplashState::Init()
{
	_data->assets.LoadTexture(SPLASH_BACKGROUND_NAME, SPLASH_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.GetTexture(SPLASH_BACKGROUND_NAME));
	_elapsedTime = 0.f;
}

void ld::SplashState::Update(float delta)
{
	_elapsedTime += delta;
	if(_elapsedTime > SPLASH_TIME)
	{
		auto color = _background.getColor();
		color.a -= 0.5*delta;
		_background.setColor(color);
		if(_background.getColor().a <= 0)
		{
			_data->stateMachine.AddState(GameStateRef(new MainMenu(_data)));
		}
	}
}

void ld::SplashState::Draw()
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}

