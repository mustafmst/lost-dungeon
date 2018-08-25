#include "PlayerAnimations.hpp"

void ld::PlayerAnimations::Draw(sf::RenderWindow& window)
{
	window.draw((AnimatedSprite) *_animatedSprite.get());
}

ld::PlayerAnimations::PlayerAnimations(sf::Texture& texture)
{
	_animatedSprite = AnimatedSpriteRef(new AnimatedSprite());
}
