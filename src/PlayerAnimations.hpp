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
	const float _attackPlayTime = 1.2f;
	
	sf::Vector2f _position;
	sf::Vector2f _animationShift = sf::Vector2f(0.f,0.f);
	AnimationRef _idleRight, _idleLeft;
	AnimationRef _walkRight, _walkLeft;
	AnimationRef _hitRight, _hitLeft;
	AnimationRef _attackRight, _attackLeft;
	AnimatedSpriteRef _animatedSprite;
	std::shared_ptr<sf::Texture> _texture;
	
	AnimationDirection _direction = ANIM_RIGHT;
	bool _isMoving = false;
	bool _isHit = false;
	bool _isAttacking = false;
	
	float _hitCooldown = 0.f;
	float _attackCooldown = 0.f;
	
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
	void SetAttack();
	bool IsAttacking();
};

}

