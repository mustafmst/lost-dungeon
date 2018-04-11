#include "Player.hpp"
#include "assetsAndDefinitions.h"

void ld::Player::Update(float delta)
{
	_player.setPosition(_playerBody->GetPosition().x*F_SCALE, _playerBody->GetPosition().y*F_SCALE);
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
}
void ld::Player::Init(sf::Texture& texture)
{
	_player.setTexture(texture);
	_player.setPosition( (SCREEN_WIDTH/2) - (_player.getGlobalBounds().width/2), 200 );
}
