#pragma once
#include "SFML/Graphics.hpp"
#include "GameData.h"
#include "Collectible.hpp"

namespace ld
{

class Finish: public Collectible
{
public:
	Finish(GameDataRef data, sf::Vector2f pos, b2World & world);
};

}

