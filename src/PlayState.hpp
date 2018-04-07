#pragma once
#include <vector>
#include <memory>
#include "GameData.h"
#include "GameState.hpp"
#include <STP/TMXLoader.hpp>

namespace ld
{
	
	class PlayState : public GameState
	{
	private:
		GameDataRef _data;
		sf::Sprite _player;
		
		tmx::TileMap _map;
		void HandleInputs();
	public:
		PlayState(GameDataRef data, std::string mapFilePath): _data(data), _map(mapFilePath) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

