#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "GameData.h"
#include "assetsAndDefinitions.h"

namespace ld
{
	class SplashState : public GameState
	{
	protected:
		GameDataRef _data;
		float _elapsedTime;
		sf::Sprite _background;
		float _timeToFinish = SPLASH_TIME;
	public:
		SplashState(GameDataRef data): _data(data) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

