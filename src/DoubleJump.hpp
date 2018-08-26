#pragma once
#include "SFML/Graphics.hpp"
#include "GameData.h"
#include "Collectible.hpp"

namespace ld
{

class DoubleJump: public  Collectible
{
public:
	DoubleJump(GameDataRef data, sf::Vector2f pos, b2World& world);
};

}

