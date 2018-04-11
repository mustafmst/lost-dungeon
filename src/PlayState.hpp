#pragma once
#include <vector>
#include <memory>
#include "GameData.h"
#include "GameState.hpp"
#include <Box2D/Box2D.h>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Map.hpp"

namespace ld
{
	class PlayState : public GameState
	{
	private:
		GameDataRef _data;
		b2World _world;
		std::vector<GameObjectRef> _gameObjects;
		Map _map;
		std::string _mapName;
		void HandleInputs();
		void InitPlayer();
		void InitMap(std::string mapFilePath);
	public:
		PlayState(GameDataRef data, std::string mapFilePath): _data(data), _mapName(mapFilePath), _world(b2Vec2(0.f,9.8f)) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

