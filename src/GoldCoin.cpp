#include "GoldCoin.hpp"
#include "assetsAndDefinitions.h"
#include <sstream>
#include "GameObjectsCodes.h"


ld::GoldCoin::GoldCoin(GameDataRef data, sf::Vector2f pos, b2World& world)
{
	_type = COIN;
	_sprite.setTexture(data->assets.GetTexture(GEMS_NAME));
	_sprite.setTextureRect(sf::IntRect(64,16,16,16));
	SetPosition(pos);
	InitPhysics(world);
}

std::string ld::GoldCoin::GetSaveData()
{
	std::stringstream stream;
	stream << GOLD_COIN_CODE << " " << GetPosition().x << " "<< GetPosition().y;
	return stream.str();
}
