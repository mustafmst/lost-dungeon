#include "Player.hpp"
#include "assetsAndDefinitions.h"
#include <iostream>

void ld::Player::HandleInputs()
{
	if(_input.CheckIfKeyIsPressed(sf::Keyboard::Space))
	{
		std::cout << "SPACE!!!" << std::endl;
	}
}

void ld::Player::Update(float delta)
{
	_player.setPosition(_playerBody->GetPosition().x*F_SCALE, (_playerBody->GetPosition().y*F_SCALE)-11.f);
	HandleInputs();
}

void ld::Player::Draw(sf::RenderWindow& window)
{
	window.draw(_player);
}

void ld::Player::InitPhysics(b2World& world)
{
	b2BodyDef def;
	def.position = b2Vec2(_player.getPosition().x/F_SCALE, _player.getPosition().y/F_SCALE);
	def.type = b2_dynamicBody;
	_playerBody = std::move(world.CreateBody(&def));
	
	b2PolygonShape box1;
	box1.SetAsBox(8.f/F_SCALE,17.f/F_SCALE);
	b2FixtureDef box1Fix;
	box1Fix.shape = &box1;
	box1Fix.density = 1;
	_playerBody->CreateFixture(&box1Fix);
}
void ld::Player::Init(sf::Texture& texture)
{
	_player.setTexture(texture);
	_player.setPosition( (SCREEN_WIDTH/2) - (_player.getGlobalBounds().width/2)- 10, 200 );
}
