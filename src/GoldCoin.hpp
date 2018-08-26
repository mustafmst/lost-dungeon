#pragma once
#include "SFML/Graphics.hpp"
#include "GameData.h"
#include "Collectible.hpp"

namespace ld
{
class GoldCoin: public Collectible
{
public:
	GoldCoin(GameDataRef data, sf::Vector2f pos, b2World & world);
};

}

