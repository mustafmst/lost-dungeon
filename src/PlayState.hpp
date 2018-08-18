#pragma once
#include <vector>
#include <memory>
#include "GameData.h"
#include "GameState.hpp"
#include <Box2D/Box2D.h>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "HUD.hpp"

namespace ld
{
	class PlayState : public GameState
	{
	private:
		GameDataRef _data;
		b2World _world;
		std::shared_ptr<Player> _player;
		std::vector<GameObjectRef> _gameObjects;
		Map _map;
		std::string _mapName;
		std::unique_ptr<sf::View> _camera;
		std::unique_ptr<HUD> _hud;
		void HandleInputs();
		void InitPlayer();
		void InitMap(std::string mapFilePath);
		void InitCamera();
		void UpdateCamera();
	public:
		PlayState(GameDataRef data, std::string mapFilePath): _data(data), _mapName(mapFilePath), _world(b2Vec2(0.f,9.8f)) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

