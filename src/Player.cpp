#include "Player.hpp"
#include "MoveState.h"
#include "assetsAndDefinitions.h"

void ld::Player::Update(float delta)
{
	HandleMovement();
	_player.setPosition(_playerBody->GetPosition().x*F_SCALE, (_playerBody->GetPosition().y*F_SCALE)-11.f);
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
	_playerBody->SetFixedRotation(true);
}
void ld::Player::Init(sf::Texture& texture)
{
	_player.setTexture(texture);
	_player.setPosition( (SCREEN_WIDTH/2) - (_player.getGlobalBounds().width/2)- 10, 200 );
}
void ld::Player::HandleMovement()
{
	MoveState moveState = STOP;
	int moveDirection = 0;
	b2Vec2 vel = _playerBody->GetLinearVelocity();
	if(_input.CheckIfKeyIsPressed(sf::Keyboard::Right))
		moveDirection += 1;
	if(_input.CheckIfKeyIsPressed(sf::Keyboard::Left))
		moveDirection-=1;
	if(_input.CheckIfKeyIsPressed(sf::Keyboard::Space))
	{
		vel.y = -10;
	}
	switch(moveDirection)
	{
		case 1:
			moveState = RIGHT;
			//_player.setScale()
			break;
		case -1:
			moveState = LEFT;
			break;
		default: break;
	}
	switch ( moveState )
	{
		case LEFT:  vel.x = -5; break;
		case STOP:  vel.x =  0; break;
		case RIGHT: vel.x =  5; break;
	}
	_playerBody->SetLinearVelocity( vel );
}
