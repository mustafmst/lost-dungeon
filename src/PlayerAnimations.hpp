#pragma once
#include <utility>
#include <memory>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "AnimationDirection.h"

namespace ld
{

typedef std::unique_ptr<AnimatedSprite> AnimatedSpriteRef;
typedef std::shared_ptr<Animation> AnimationRef;
class PlayerAnimations
{
	AnimationRef _idleRight, _idleLeft;
	AnimatedSpriteRef _animatedSprite;
	std::shared_ptr<sf::Texture> _texture;
	
	AnimationDirection _direction;
	
	void ChooseAnimation();
public:
	PlayerAnimations(sf::Texture & texture, sf::Vector2f startPos);
	void SetPos(sf::Vector2f pos);
	sf::Vector2f GetPos();
	void Update(float delta);
	void Draw(sf::RenderWindow& window);
	void SetDirection(AnimationDirection newDir);
};

}

