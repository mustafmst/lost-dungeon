#include "Collectible.hpp"
#include "assetsAndDefinitions.h"



ld::Collectible::~Collectible()
{
	if(_body != nullptr)
	{
		_body->GetWorld()->DestroyBody(_body);
	}
}

void ld::Collectible::SetPosition(sf::Vector2f pos)
{
	_sprite.setPosition(pos);
}

void ld::Collectible::Update(float delta)
{
}

void ld::Collectible::Draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

void ld::Collectible::InitPhysics(b2World& world)
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

sf::Vector2f ld::Collectible::GetPosition()
{
	return _sprite.getPosition();
}

ld::Collectible::Collectible()
{
}
