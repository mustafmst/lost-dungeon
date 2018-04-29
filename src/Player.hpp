#pragma once
#include "InputManager.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"

namespace ld
{
	class Player : public GameObject
	{
	private:
		sf::Sprite _player;
		b2Body* _playerBody;
		InputManager& _input;
	public:
		Player(InputManager& input): _input(input) {}
		~Player() {}
		
		void Init(sf::Texture & texture);
		void Update(float delta);
		void Draw(sf::RenderWindow & window);
		void InitPhysics(b2World & world);
		
		void HandleMovement();
	};
}

