#include "HealthPotion.hpp"
#include "gameObjectTypes.h"
#include "assetsAndDefinitions.h"
#include <string>


ld::HealthPotion::HealthPotion(GameDataRef data, sf::Vector2f pos, b2World& world)
{
	_type = HP;
	_sprite.setTexture(data->assets.GetTexture(GEMS_NAME));
	_sprite.setTextureRect(sf::IntRect(16,144,16,16));
	SetPosition(pos);
	InitPhysics(world);
}

std::string ld::HealthPotion::GetSaveData()
{
	std::stringstream stream;
	stream << POTION_CODE << " " << GetPosition().x << " "<< GetPosition().y;
	return stream.str();
}
