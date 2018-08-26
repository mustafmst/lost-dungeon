#pragma once
#include "SFML/Graphics.hpp"
#include "GameData.h"
#include "Collectible.hpp"

namespace ld
{

class HealthPotion: public Collectible
{
public:
	HealthPotion(GameDataRef data, sf::Vector2f pos, b2World & world);
};


}

