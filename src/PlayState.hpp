#pragma once
#include <vector>
#include <memory>
#include "GameData.h"
#include "GameState.hpp"

namespace ld
{
	
	class PlayState : public GameState
	{
	private:
		GameDataRef _data;
		std::vector<sf::CircleShape*> _objects;
		
		void HandleInputs();
	public:
		PlayState(GameDataRef data): _data(data) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

