#include "PlayerAnimations.hpp"
#include "knightAnimations.h"

void ld::PlayerAnimations::Draw(sf::RenderWindow& window)
{
	window.draw((AnimatedSprite) *_animatedSprite.get());
}

void ld::PlayerAnimations::SetPos(sf::Vector2f pos)
{
	_position = pos;
	_animatedSprite->setPosition(pos + _animationShift);
}

sf::Vector2f ld::PlayerAnimations::GetPos()
{
	return _position;
}

ld::PlayerAnimations::PlayerAnimations(sf::Texture& texture, sf::Vector2f startPos)
{
	_texture = std::shared_ptr<sf::Texture>(new sf::Texture(texture));
	_animatedSprite = AnimatedSpriteRef(new AnimatedSprite(sf::seconds(0.15f), false, true));
	SetPos(startPos);
	
	// idle
	_idleRight = AnimationRef(new Animation);
	_idleRight->setSpriteSheet(*_texture);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_1_R);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_2_R);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_3_R);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_4_R);
	
	_idleLeft = AnimationRef(new Animation());
	_idleLeft->setSpriteSheet(*_texture);
	_idleLeft->addFrame(KNIGHT_IDLE_FRAME_1_L);
	_idleLeft->addFrame(KNIGHT_IDLE_FRAME_2_L);
	_idleLeft->addFrame(KNIGHT_IDLE_FRAME_3_L);
	_idleLeft->addFrame(KNIGHT_IDLE_FRAME_4_L);
	
	// walk
	_walkRight = AnimationRef(new Animation());
	_walkRight->setSpriteSheet(*_texture);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_1_R);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_2_R);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_3_R);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_4_R);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_5_R);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_6_R);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_7_R);
	_walkRight->addFrame(KNIGHT_WALK_FRAME_8_R);
	
	_walkLeft = AnimationRef(new Animation());
	_walkLeft->setSpriteSheet(*_texture);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_1_L);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_2_L);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_3_L);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_4_L);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_5_L);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_6_L);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_7_L);
	_walkLeft->addFrame(KNIGHT_WALK_FRAME_8_L);
	
	// hit
	_hitLeft = AnimationRef(new Animation());
	_hitLeft->setSpriteSheet(*_texture);
	_hitLeft->addFrame(KNIGHT_HIT_FRAME_1_L);
	_hitLeft->addFrame(KNIGHT_HIT_FRAME_2_L);
	
	_hitRight = AnimationRef(new Animation());
	_hitRight->setSpriteSheet(*_texture);
	_hitRight->addFrame(KNIGHT_HIT_FRAME_1_R);
	_hitRight->addFrame(KNIGHT_HIT_FRAME_2_R);
	
	// attack
	_attackRight = AnimationRef(new Animation());
	_attackRight->setSpriteSheet(*_texture);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_1_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_2_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_3_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_4_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_5_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_6_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_7_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_8_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_9_R);
	_attackRight->addFrame(KNIGHT_ATTACK_FRAME_10_R);
	
	_attackLeft = AnimationRef(new Animation());
	_attackLeft->setSpriteSheet(*_texture);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_1_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_2_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_3_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_4_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_5_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_6_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_7_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_8_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_9_L);
	_attackLeft->addFrame(KNIGHT_ATTACK_FRAME_10_L);
	
	// end of animations setup
	_animatedSprite->play(*_idleRight);
}

void ld::PlayerAnimations::Update(float delta)
{
	ChooseAnimation();
	_animatedSprite->update(sf::seconds(delta));
	HandleCooldowns(delta);
}

void ld::PlayerAnimations::SetDirection(AnimationDirection newDir)
{
	_direction = newDir;
}

void ld::PlayerAnimations::ChooseAnimation()
{
	if(_direction == ANIM_RIGHT)
	{
		if(_isHit){
			_animatedSprite->play(*_hitRight);
			_animationShift = sf::Vector2f(0.f,0.f);
		}else if(_isAttacking){
			_animatedSprite->play(*_attackRight);
			_animationShift = sf::Vector2f(-13.f,-4.f);
		}else if(_isMoving){
			_animatedSprite->play(*_walkRight);
			_animationShift = sf::Vector2f(0.f,0.f);
		} else {
			_animatedSprite->play(*_idleRight);
			_animationShift = sf::Vector2f(0.f,0.f);
		}
	} else
	{
		if(_isHit){
			_animatedSprite->play(*_hitLeft);
			_animationShift = sf::Vector2f(0.f,0.f);
		}else if(_isAttacking){
			_animatedSprite->play(*_attackLeft);
			_animationShift = sf::Vector2f(-13.f,-4.f);
		}else if(_isMoving){
			_animatedSprite->play(*_walkLeft);
			_animationShift = sf::Vector2f(0.f,0.f);
		} else {
			_animatedSprite->play(*_idleLeft);
			_animationShift = sf::Vector2f(0.f,0.f);
		}
	}
}

void ld::PlayerAnimations::SetIsMoving(bool isMoving)
{
	_isMoving = isMoving;
}

void ld::PlayerAnimations::SetIsHit()
{
	_isHit = true;
	_hitCooldown = _hitPlayTime;
}

void ld::PlayerAnimations::HandleCooldowns(float delta)
{
	if(_isHit)
	{
		_hitCooldown -= delta;
		if(_hitCooldown < 0)
		{
			_isHit = false;
		}
	}
	if(_isAttacking)
	{
		_attackCooldown -= delta;
		if(_attackCooldown < 0)
		{
			_isAttacking = false;
		}
	}
}

void ld::PlayerAnimations::SetAttack()
{
	_isAttacking = true;
	_attackCooldown = _attackPlayTime;
}

bool ld::PlayerAnimations::IsAttacking()
{
	return _isAttacking;
}
