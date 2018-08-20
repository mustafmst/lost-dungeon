#pragma once
#include "InputManager.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "GameData.h"

namespace ld
{
	class Player : public GameObject
	{
	private:
		sf::Sprite _player;
		b2Body* _playerBody;
		GameDataRef _data;
		bool _isFacigRight = true;
		b2Vec2 _lastVelocity;
		
		bool IsOnGround();
		void SetSpriteDirection();
	public:
		Player(GameDataRef data): _data(data) {}
		~Player();
		
		void Init(sf::Texture & texture);
		void Update(float delta);
		void Draw(sf::RenderWindow & window);
		void InitPhysics(b2World & world);
		
		sf::Vector2f GetPosition();
		void HandleMovement();
		void GiveCoin();
	};
}

