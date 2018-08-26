#include "Skeleton.hpp"
#include "assetsAndDefinitions.h"


void ld::Skeleton::Update(float delta)
{
	_skeleton.setPosition(
		_body->GetPosition().x*F_SCALE,
		(_body->GetPosition().y*F_SCALE)-11.f
	);
	Move();
	if(_goRight)
	{
		_skeleton.setTextureRect(sf::IntRect(0,0,16,32));
	} else {
		_skeleton.setTextureRect(sf::IntRect(16,0,-16,32));
	}
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
	_type = ENEMY;
	_skeleton.setTexture(_data->assets.GetTexture(SKELETON_IDLE_NAME));
	_skeleton.setPosition(startPos);
	_skeleton.setTextureRect(sf::IntRect(0,0,16,32));
}

void ld::Skeleton::Move()
{
	auto xPos = _skeleton.getPosition().x;
	if(_body->GetLinearVelocity().x == 0)
	{
		_goRight = !_goRight;
	} else if(xPos < _left){
		_goRight = true;
	} else if(xPos > _right){
		_goRight = false;
	}
	auto velocity = b2Vec2(-4.f,0.1f);
	if(_goRight)
	{
		velocity = b2Vec2(4.f,0.1f);
	}
	_body->SetLinearVelocity(velocity);
}

float ld::Skeleton::GetDamage()
{
	return _damage;
}

sf::Vector2f ld::Skeleton::GetPosition()
{
	return _skeleton.getPosition();
}

ld::Skeleton::~Skeleton()
{
	_body->GetWorld()->DestroyBody(_body);
}
