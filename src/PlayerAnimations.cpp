#include "PlayerAnimations.hpp"

ld::PlayerAnimations::PlayerAnimations()
{
	_animatedSprite = AnimatedSpriteRef(new AnimatedSprite());
}

sf::Drawable& ld::PlayerAnimations::GetDrawable()
{
	return _animatedSprite;
}
