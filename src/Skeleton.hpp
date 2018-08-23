#pragma once
#include "GameData.h"
#include "GameObject.hpp"

namespace ld
{

class Skeleton: public GameObject 
{
	GameDataRef _data;
	sf::Sprite _skeleton;
	b2Body* _body;
	float _left, _right;
	
	void Move();
public:
	Skeleton(GameDataRef data, sf::Vector2f startPos, float left, float right);
	~Skeleton(){};
	
	void Update(float delta);
	void Draw(sf::RenderWindow & window);
	void InitPhysics(b2World & world);
};

}

