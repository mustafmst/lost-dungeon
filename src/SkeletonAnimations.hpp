#pragma once
#include <utility>
#include <memory>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

namespace ld
{

typedef std::unique_ptr<AnimatedSprite> AnimatedSpriteRef;
typedef std::shared_ptr<Animation> AnimationRef;
class SkeletonAnimations
{
	AnimationRef _walkRight, _walkLeft;
	
	sf::Vector2f _position;
	sf::Vector2f _animationShift = sf::Vector2f(0.f,0.f);
	AnimatedSpriteRef _animatedSprite;
	std::shared_ptr<sf::Texture> _texture;
	
	bool _isMovingRight = true;
	
	void ChooseAnimation();
public:
	SkeletonAnimations(sf::Texture & texture, sf::Vector2f startPos);
	void SetPos(sf::Vector2f pos);
	sf::Vector2f GetPos();
	void Update(float delta);
	void Draw(sf::RenderWindow& window);
	void SetIsMovingRight(bool isMovingRight);
};

}

