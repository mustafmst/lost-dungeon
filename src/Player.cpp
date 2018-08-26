#include "Player.hpp"
#include "MoveState.h"
#include "assetsAndDefinitions.h"
#include <iostream>
#include "GameOver.hpp"
#include "knightAnimations.h"
#include "PlayState.hpp"
#include "Skeleton.hpp"

void ld::Player::Update(float delta)
{
	_player->Update(delta);
	if(_jumpCooldown > 0) _jumpCooldown-=delta;
	HandleMovement();
	if(CanJump() && _lastVelocity.y > 15.f) Hurt(50.f);
	_player->SetPos(sf::Vector2f(
		_playerBody->GetPosition().x*F_SCALE,
		(_playerBody->GetPosition().y*F_SCALE)-11.f)
	);
	_lastVelocity = _playerBody->GetLinearVelocity();
	if(_player->IsAttacking()) Attack();
	if(_data->playerInfo.GameIsOver())
	{
		_data->stateMachine.AddState(GameStateRef(new GameOver(_data)), true);
	}
}

void ld::Player::Draw(sf::RenderWindow& window)
{
	_player->Draw(window);
}

void ld::Player::InitPhysics(b2World& world)
{
	b2BodyDef playerBodyDefinition;
	playerBodyDefinition.position = b2Vec2(
		_player->GetPos().x/F_SCALE,
		_player->GetPos().y/F_SCALE
	);
	playerBodyDefinition.type = b2_dynamicBody;
	playerBodyDefinition.userData = this;
	_playerBody = std::move(world.CreateBody(&playerBodyDefinition));
	_playerBody->SetFixedRotation(true);
	
	b2PolygonShape boxShape;
	boxShape.SetAsBox(6.f/F_SCALE,17.f/F_SCALE);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	boxFixtureDef.friction = 0.f;
	_playerBody->CreateFixture(&boxFixtureDef);
	_lastVelocity = _playerBody->GetLinearVelocity();
}
void ld::Player::Init(sf::Texture& texture, sf::Vector2f startPos)
{
	_player = std::shared_ptr<PlayerAnimations>(new PlayerAnimations(texture, startPos));
}

bool ld::Player::CanJump()
{
	const float velocityBorders = 0.001f;
	const float current = _playerBody->GetLinearVelocity().y;
	return  current > -velocityBorders && current < velocityBorders && _jumpCooldown <= 0;
}

void ld::Player::HandleMovement()
{
	MoveState moveState = STOP;
	int moveDirection = 0;
	b2Vec2 vel = _playerBody->GetLinearVelocity();
	if(_data->input.CheckIfKeyIsPressed(sf::Keyboard::Right))
		moveDirection += 1;
	if(_data->input.CheckIfKeyIsPressed(sf::Keyboard::Left))
		moveDirection-=1;
	if(_data->input.CheckIfKeyIsPressed(sf::Keyboard::Up) && CanJump())
	{
		_jumpCooldown = JumpCooldownSecMax;
		vel.y = -8;
	}
	if(_data->input.CheckIfKeyIsPressed(sf::Keyboard::Space)){
		_player->SetAttack();
	}
	switch(moveDirection)
	{
		case 1:
			moveState = RIGHT;
			break;
		case -1:
			moveState = LEFT;
			break;
		default: break;
	}
	switch ( moveState )
	{
		case LEFT:  vel.x = -5; 
			_player->SetIsMoving(true);
		break;
		case RIGHT: vel.x =  5; 
			_player->SetIsMoving(true);
		break;
		case STOP:  
			vel.x =  0;
			_player->SetIsMoving(false);
			break;
	}
	if(vel.y == 0 && moveState != STOP) vel.y = -0.2f;
	_playerBody->SetLinearVelocity( vel );
	SetSpriteDirection();
}

void ld::Player::SetSpriteDirection()
{
	const float xMovingSpeed = _playerBody->GetLinearVelocity().x;
	if(xMovingSpeed == 0) return;
	const bool currentFacing = xMovingSpeed >= 0;
	if(currentFacing != _isFacigRight)
	{
		_isFacigRight = currentFacing;
		if(!_isFacigRight)
		{
			_player->SetDirection(ANIM_LEFT);
		} else 
		{
			_player->SetDirection(ANIM_RIGHT);
		}
	}
}

sf::Vector2f ld::Player::GetPosition()
{
	return _player->GetPos();
}

ld::Player::~Player()
{
	_playerBody->GetWorld()->DestroyBody(_playerBody);
}

void ld::Player::GiveCoin()
{
	_data->playerInfo.GiveCoin();
}

b2Vec2 ld::Player::GetDirection()
{
	auto vel = _playerBody->GetLinearVelocity();
	vel.Normalize();
	return vel;
}

void ld::Player::Hurt(float points)
{
	_data->playerInfo.ChangeHealth(-points);
	_player->SetIsHit();
}

void ld::Player::Attack()
{
	auto state = dynamic_cast<PlayState*>(_data->stateMachine.CurrentState().get());
	if(state == nullptr) return;
	for(auto o: state->_gameObjects)
	{
		if(o->_type == ENEMY && (b2Vec2(o->GetPosition().x, o->GetPosition().y) - b2Vec2(GetPosition().x,GetPosition().y)).Length() < 20.f)
		{
			auto enemy = dynamic_cast<Skeleton*>(o.get());
			enemy->Hurt(_damage);
		}
	}
}

void ld::Player::Heal(float points)
{
	_data->playerInfo.ChangeHealth(points);
}
