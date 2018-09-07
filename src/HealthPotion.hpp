#pragma once
#include "SFML/Graphics.hpp"
#include "GameData.h"
#include "Collectible.hpp"
#include <sstream>
#include "GameObjectsCodes.h"

namespace ld
{

class HealthPotion: public Collectible
{
public:
	HealthPotion(GameDataRef data, sf::Vector2f pos, b2World & world);
	std::string GetSaveData();
};


}

