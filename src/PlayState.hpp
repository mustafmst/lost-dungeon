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
#include "ContactListener.hpp"

namespace ld
{
	class PlayState : public GameState
	{
	private:
		bool _isLoaded;
		GameDataRef _data;
		b2World _world;
		std::shared_ptr<Player> _player;
		Map _map;
		std::string _mapName;
		std::unique_ptr<sf::View> _camera;
		std::unique_ptr<HUD> _hud;
		std::unique_ptr<ContactListener> _eventHandler;
		void HandleInputs();
		void InitPlayer();
		void InitMap(std::string mapFilePath);
		void InitCoins();
		void InitHP();
		void InitFinish();
		void InitEnemies();
		void InitCamera();
		void UpdateCamera();
		void AddCoin(int x, int y);
		void AddHP(int x, int y);
		void AddFinish();
		void AddEnemy(int x, int y, int left, int right);
	public:
		PlayState(GameDataRef data, std::string mapFilePath, bool isLoaded): _data(data), _mapName(mapFilePath), _world(b2Vec2(0.f,9.8f)), _isLoaded(isLoaded) {}
		std::vector<GameObjectRef> _gameObjects;
		void Init();
		void Update(float delta);
		void Draw();
		void LoadPlayer(float x, float y);
		void LoadSkeleton(float x, float y, float left, float right);
		void LoadGold(float x, float y);
		void LoadHP(float x, float y);
		void InitDoubleJump();
	};
}

