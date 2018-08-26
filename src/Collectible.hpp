#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

namespace ld
{

class Collectible: public GameObject
{
public:
	sf::Sprite _sprite;
	b2Body* _body;
	
	Collectible();
	~Collectible();
	void SetPosition(sf::Vector2f pos);
	void Update(float delta);
	void Draw(sf::RenderWindow & window);
	void InitPhysics(b2World & world);
	sf::Vector2f GetPosition();
};

}

