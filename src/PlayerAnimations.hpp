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
	const float _hitPlayTime = 0.4f;
	
	sf::Vector2f _animationShift = sf::Vector2f(0.f,0.f);
	AnimationRef _idleRight, _idleLeft;
	AnimationRef _walkRight, _walkLeft;
	AnimationRef _hitRight, _hitLeft;
	AnimatedSpriteRef _animatedSprite;
	std::shared_ptr<sf::Texture> _texture;
	
	AnimationDirection _direction = ANIM_RIGHT;
	bool _isMoving = false;
	bool _isHit = false;
	
	float _hitCooldown = 0.f;
	
	void ChooseAnimation();
	void HandleCooldowns(float delta);
public:
	PlayerAnimations(sf::Texture & texture, sf::Vector2f startPos);
	void SetPos(sf::Vector2f pos);
	sf::Vector2f GetPos();
	void Update(float delta);
	void Draw(sf::RenderWindow& window);
	void SetDirection(AnimationDirection newDir);
	void SetIsMoving(bool isMoving);
	void SetIsHit();
};

}

