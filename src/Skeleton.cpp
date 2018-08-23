#include "Skeleton.hpp"
#include "assetsAndDefinitions.h"


void ld::Skeleton::Update(float delta)
{
	_skeleton.setPosition(
		_body->GetPosition().x*F_SCALE,
		(_body->GetPosition().y*F_SCALE)-11.f
	);
	Move();
}

void ld::Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(_skeleton);
}

void ld::Skeleton::InitPhysics(b2World& world)
{
	b2BodyDef skeletonBodyDefinition;
	skeletonBodyDefinition.position = b2Vec2(
		_skeleton.getPosition().x/F_SCALE,
		_skeleton.getPosition().y/F_SCALE
	);
	skeletonBodyDefinition.type = b2_dynamicBody;
	skeletonBodyDefinition.userData = this;
	_body = std::move(world.CreateBody(&skeletonBodyDefinition));
	_body->SetFixedRotation(true);
	
	b2PolygonShape boxShape;
	boxShape.SetAsBox(8.f/F_SCALE,17.f/F_SCALE);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	boxFixtureDef.friction = 0.f;
	_body->CreateFixture(&boxFixtureDef);
}

ld::Skeleton::Skeleton(GameDataRef data, sf::Vector2f startPos, float left, float right): 
	_data(data),
	_left(left),
	_right(right)
{
	_skeleton.setTexture(_data->assets.GetTexture(SKELETON_IDLE_NAME));
	_skeleton.setPosition(startPos);
	_skeleton.setTextureRect(sf::IntRect(0,0,16,32));
}

void ld::Skeleton::Move()
{
}
