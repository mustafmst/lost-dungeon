#pragma once
#include "GameState.hpp"
#include "GameData.h"

namespace ld
{
	class SplashState : public GameState
	{
	private:
		GameDataRef _data;
	public:
		SplashState(GameDataRef data): _data(data) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

