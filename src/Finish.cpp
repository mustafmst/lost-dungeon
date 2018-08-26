#include "Finish.hpp"
#include "assetsAndDefinitions.h"



ld::Finish::Finish(GameDataRef data, sf::Vector2f pos, b2World& world)
{
	_type = FINISH;
	_sprite.setTexture(data->assets.GetTexture(GEMS_NAME));
	_sprite.setTextureRect(sf::IntRect(32,80,16,16));
	SetPosition(pos);
	InitPhysics(world);
}
