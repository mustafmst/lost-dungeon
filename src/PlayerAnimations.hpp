#pragma once
#include <utility>
#include <memory>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

namespace ld
{

typedef std::unique_ptr<AnimatedSprite> AnimatedSpriteRef;
class PlayerAnimations
{
	AnimatedSpriteRef _animatedSprite;
public:
	PlayerAnimations();
	sf::Drawable& GetDrawable();
};

}

