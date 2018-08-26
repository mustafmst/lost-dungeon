#pragma once
#include "InputManager.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "GameData.h"
#include "PlayerAnimations.hpp"

namespace ld
{
	class Player : public GameObject
	{
	private:
		const float JumpCooldownSecMax = 0.6f;
		float _damage = 60.f;
		bool _jumpUnlocked = false;
	
		std::shared_ptr<PlayerAnimations> _player;
		b2Body* _playerBody;
		GameDataRef _data;
		bool _isFacigRight = true;
		bool _secondJump = false;
		b2Vec2 _lastVelocity;
		float _jumpCooldown = 0.f;
		
		bool CanJump();
		void SetSpriteDirection();
		void Attack();
	public:
		Player(GameDataRef data): _data(data) 
		{
			_type = PLAYER;
		}
		~Player();
		
		void Init(sf::Texture & texture, sf::Vector2f startPos);
		void Update(float delta);
		void Draw(sf::RenderWindow & window);
		void InitPhysics(b2World & world);
		
		sf::Vector2f GetPosition();
		void HandleMovement();
		void GiveCoin();
		void Hurt(float points);
		void Heal(float points);
		void FinishGame();
		void UnlockDoubleJump();
		void ResetJump();
		b2Vec2 GetDirection();
	};
}

