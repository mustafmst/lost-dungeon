#include "SplashState.hpp"
#include "assetsAndDefinitions.h"

void ld::SplashState::Init()
{
	_data->assets.LoadTexture(SPLASH_BACKGROUND_NAME, SPLASH_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.GetTexture(SPLASH_BACKGROUND_NAME));
}

void ld::SplashState::Update(float delta)
{
	
}

void ld::SplashState::Draw()
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}

