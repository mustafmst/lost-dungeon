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

void createFloor(b2World& world) {
	b2BodyDef def;
	def.position = b2Vec2(400/F_SCALE, 600/F_SCALE);
	def.type = b2_staticBody; //b2_kinematicBody;
	b2Body* body = std::move(world.CreateBody(&def));
	
	b2PolygonShape box1;
	box1.SetAsBox(400,10);
	b2FixtureDef box1Fix;
	box1Fix.shape = &box1;
	box1Fix.density = 1;
	body->CreateFixture(&box1Fix);
}

void ld::Player::InitPhysics(b2World& world)
{
	b2BodyDef def;
	def.position = b2Vec2(_player.getPosition().x/F_SCALE, _player.getPosition().y/F_SCALE);
	def.type = b2_dynamicBody;//b2_kinematicBody;
	_playerBody = std::move(world.CreateBody(&def));
	
	b2PolygonShape box1;
	box1.SetAsBox(8.f/F_SCALE,17.f/F_SCALE);
	b2FixtureDef box1Fix;
	box1Fix.shape = &box1;
	box1Fix.density = 1;
	_playerBody->CreateFixture(&box1Fix);
	_playerBody->SetLinearVelocity(b2Vec2(50,0));
	
	//Floor for test purposes
	/*
	b2BodyDef def2;
	def2.position = b2Vec2(400.f/F_SCALE, (32.f*16.f+8.f)/F_SCALE);
	def2.type = b2_staticBody; //b2_kinematicBody;
	b2Body* body = std::move(world.CreateBody(&def2));
	
	b2PolygonShape box2;
	box2.SetAsBox(400/F_SCALE,8.f/F_SCALE);
	b2FixtureDef box2Fix;
	box2Fix.shape = &box2;
	box2Fix.density = 1;
	body->CreateFixture(&box2Fix);
	*/
}
void ld::Player::Init(sf::Texture& texture)
{
	_player.setTexture(texture);
	_player.setPosition( (SCREEN_WIDTH/2) - (_player.getGlobalBounds().width/2), 200 );
}
