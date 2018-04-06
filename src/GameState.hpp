#pragma once
#include "GameData.h"
#include <memory>

namespace ld
{
	class GameState
	{
	private:
		GameDataRef _data;
	public:
		GameState(GameDataRef data);
		~GameState() {}
		virtual void Update(float delta) = 0;
		virtual void Draw() = 0;
	};
	
	typedef std::unique_ptr<GameState> GameStateRef;
}

