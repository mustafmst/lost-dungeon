#pragma once
#include "GameData.h"
#include "GameObject.hpp"
#include "SkeletonAnimations.hpp"

namespace ld
{

class Skeleton: public GameObject 
{
	float _damage = 30.f;
	float _life = 80.f;
	GameDataRef _data;
	std::shared_ptr<SkeletonAnimations> _skeleton;
	b2Body* _body;
	float _left, _right;
	bool _goRight = true;
	
	void Move();
public:
	Skeleton(GameDataRef data, sf::Vector2f startPos, float left, float right);
	~Skeleton();
	
	void Update(float delta);
	void Draw(sf::RenderWindow & window);
	void InitPhysics(b2World & world);
	sf::Vector2f GetPosition();
	float GetDamage();
	void Hurt(float points);
};

}

