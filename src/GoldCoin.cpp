#include "GoldCoin.hpp"
#include "assetsAndDefinitions.h"


void ld::GoldCoin::Init(sf::Texture& texture)
{
	_sprite.setTexture(texture);
	_sprite.setTextureRect(sf::IntRect(64,16,16,16));
}

void ld::GoldCoin::Update(float delta)
{
	//_sprite.setPosition(
	//	_playerBody->GetPosition().x*F_SCALE,
	//	(_playerBody->GetPosition().y*F_SCALE)-11.f
	//);
}

void ld::GoldCoin::Draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

void ld::GoldCoin::InitPhysics(b2World& world)
{
	b2BodyDef def;
	def.position = b2Vec2(
		_sprite.getPosition().x/F_SCALE,
		_sprite.getPosition().y/F_SCALE
	);
	def.type = b2_staticBody;
	def.userData = this;
	_body = std::move(world.CreateBody(&def));
	
	b2PolygonShape box1;
	box1.SetAsBox(8.f/F_SCALE,8.f/F_SCALE);
	b2FixtureDef box1Fix;
	box1Fix.shape = &box1;
	box1Fix.density = 1;
	box1Fix.friction = 0.f;
	_body->CreateFixture(&box1Fix);
	_body->SetFixedRotation(true);
}

void ld::GoldCoin::SetPosition(float x, float y)
{
	_sprite.setPosition(x,y);
}

ld::GoldCoin::~GoldCoin()
{
	_body->GetWorld()->DestroyBody(_body);
}
