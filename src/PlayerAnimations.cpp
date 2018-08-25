#include "PlayerAnimations.hpp"
#include "knightAnimations.h"

void ld::PlayerAnimations::Draw(sf::RenderWindow& window)
{
	window.draw((AnimatedSprite) *_animatedSprite.get());
}

void ld::PlayerAnimations::SetPos(sf::Vector2f pos)
{
	_animatedSprite->setPosition(pos);
}

sf::Vector2f ld::PlayerAnimations::GetPos()
{
	return _animatedSprite->getPosition();
}

ld::PlayerAnimations::PlayerAnimations(sf::Texture& texture, sf::Vector2f startPos)
{
	_texture = std::shared_ptr<sf::Texture>(new sf::Texture(texture));
	_animatedSprite = AnimatedSpriteRef(new AnimatedSprite(sf::seconds(0.15f), false, true));
	SetPos(startPos);
	
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
	
	_animatedSprite->play(*_idleRight);
}

void ld::PlayerAnimations::Update(float delta)
{
	ChooseAnimation();
	_animatedSprite->update(sf::seconds(delta));
}

void ld::PlayerAnimations::SetDirection(AnimationDirection newDir)
{
	_direction = newDir;
}

void ld::PlayerAnimations::ChooseAnimation()
{
	if(_direction == ANIM_RIGHT)
	{
		if(_isMoving){
			_animatedSprite->play(*_walkRight);
		} else {
			_animatedSprite->play(*_idleRight);
		}
	} else
	{
		if(_isMoving){
			_animatedSprite->play(*_walkLeft);
		} else {
			_animatedSprite->play(*_idleLeft);
		}
	}
}

void ld::PlayerAnimations::SetIsMoving(bool isMoving)
{
	_isMoving = isMoving;
}
