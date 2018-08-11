#include "PlayerAnimations.hpp"

ld::PlayerAnimations::PlayerAnimations()
{
	_animatedSprite = AnimatedSpriteRef(new AnimatedSprite());
}
void ld::PlayerAnimations::Draw(sf::RenderWindow& window)
{
	window.draw((AnimatedSprite) *_animatedSprite.get());
}
