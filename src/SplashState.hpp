#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "GameData.h"

namespace ld
{
	class SplashState : public GameState
	{
	private:
		GameDataRef _data;
		float _elapsedTime;
		sf::Sprite _background;
	public:
		SplashState(GameDataRef data): _data(data) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

