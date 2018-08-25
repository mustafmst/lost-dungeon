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
	_animatedSprite = AnimatedSpriteRef(new AnimatedSprite(sf::seconds(0.2f), false, true));
	SetPos(startPos);
	
	_idleRight = AnimationRef(new Animation);
	_idleRight->setSpriteSheet(*_texture);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_1_R);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_2_R);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_3_R);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_4_R);
	
	_idleLeft = AnimationRef(new Animation());
	_idleLeft->setSpriteSheet(*_texture);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_1_L);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_2_L);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_3_L);
	_idleRight->addFrame(KNIGHT_IDLE_FRAME_4_L);
	_animatedSprite->play(*_idleRight);
}

void ld::PlayerAnimations::Update(float delta)
{
	//ChooseAnimation();
	_animatedSprite->update(sf::seconds(delta));
}

void ld::PlayerAnimations::SetDirection(AnimationDirection newDir)
{
	_direction = newDir;
}

void ld::PlayerAnimations::ChooseAnimation()
{
	if(_direction == AnimationDirection::ANIM_RIGHT)
	{
		_animatedSprite->play(*_idleRight);
	} else
	{
		_animatedSprite->play(*_idleLeft);
	}
}
