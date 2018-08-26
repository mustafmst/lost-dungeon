#pragma once
#include "GameObject.hpp"
#include "SFML/Graphics.hpp"

namespace ld
{
class GoldCoin: public GameObject
{
	sf::Sprite _sprite;
	b2Body* _body;
public:
	GoldCoin(){};
	~GoldCoin();
	void SetPosition(float x, float y);
	void Init(sf::Texture & texture);
	void Update(float delta);
	void Draw(sf::RenderWindow & window);
	void InitPhysics(b2World & world);
	sf::Vector2f GetPosition();
};

}

