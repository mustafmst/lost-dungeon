#include "DoubleJump.hpp"
#include "assetsAndDefinitions.h"



ld::DoubleJump::DoubleJump(GameDataRef data, sf::Vector2f pos, b2World& world)
{
	_type = DOUBLE_JUMP;
	_sprite.setTexture(data->assets.GetTexture(GEMS_NAME));
	_sprite.setTextureRect(sf::IntRect(48,48,16,16));
	SetPosition(pos);
	InitPhysics(world);
}
