#include "SkeletonAnimations.hpp"
#include "skeletonAnimation.h"



ld::SkeletonAnimations::SkeletonAnimations(sf::Texture& texture, sf::Vector2f startPos)
{
	_texture = std::shared_ptr<sf::Texture>(new sf::Texture(texture));
	_animatedSprite = AnimatedSpriteRef(new AnimatedSprite(sf::seconds(0.1f), false, true));
	SetPos(startPos);
	
	_walkRight = AnimationRef(new Animation());
	_walkRight->setSpriteSheet(*_texture);
	_walkRight->addFrame( SKELETON_WALK_1_R);
	_walkRight->addFrame( SKELETON_WALK_2_R);
	_walkRight->addFrame( SKELETON_WALK_3_R);
	_walkRight->addFrame( SKELETON_WALK_4_R);
	_walkRight->addFrame( SKELETON_WALK_5_R);
	_walkRight->addFrame( SKELETON_WALK_6_R);
	_walkRight->addFrame( SKELETON_WALK_7_R);
	_walkRight->addFrame( SKELETON_WALK_8_R);
	_walkRight->addFrame( SKELETON_WALK_9_R);
	_walkRight->addFrame(SKELETON_WALK_10_R);
	_walkRight->addFrame(SKELETON_WALK_11_R);
	_walkRight->addFrame(SKELETON_WALK_12_R);
	_walkRight->addFrame(SKELETON_WALK_13_R);
	
	_walkLeft = AnimationRef(new Animation());
	_walkLeft->setSpriteSheet(*_texture);
	_walkLeft->addFrame( SKELETON_WALK_1_L);
	_walkLeft->addFrame( SKELETON_WALK_2_L);
	_walkLeft->addFrame( SKELETON_WALK_3_L);
	_walkLeft->addFrame( SKELETON_WALK_4_L);
	_walkLeft->addFrame( SKELETON_WALK_5_L);
	_walkLeft->addFrame( SKELETON_WALK_6_L);
	_walkLeft->addFrame( SKELETON_WALK_7_L);
	_walkLeft->addFrame( SKELETON_WALK_8_L);
	_walkLeft->addFrame( SKELETON_WALK_9_L);
	_walkLeft->addFrame(SKELETON_WALK_10_L);
	_walkLeft->addFrame(SKELETON_WALK_11_L);
	_walkLeft->addFrame(SKELETON_WALK_12_L);
	_walkLeft->addFrame(SKELETON_WALK_13_L);
	
	// end of animations setup
	_animatedSprite->play(*_walkRight);
}

void ld::SkeletonAnimations::SetPos(sf::Vector2f pos)
{
	_position = pos;
	_animatedSprite->setPosition(pos + _animationShift);
}

sf::Vector2f ld::SkeletonAnimations::GetPos()
{
	return _position;
}

void ld::SkeletonAnimations::Update(float delta)
{
	ChooseAnimation();
	_animatedSprite->update(sf::seconds(delta));
}

void ld::SkeletonAnimations::Draw(sf::RenderWindow& window)
{
	window.draw((AnimatedSprite) *_animatedSprite.get());
}

void ld::SkeletonAnimations::SetIsMovingRight(bool isMovingRight)
{
	_isMovingRight = isMovingRight;
}

void ld::SkeletonAnimations::ChooseAnimation()
{
	if(_isMovingRight){
		_animatedSprite->play(*_walkRight);
		_animationShift = sf::Vector2f(0.f,0.f);
	}else {
		_animatedSprite->play(*_walkLeft);
		_animationShift = sf::Vector2f(0.f,0.f);
	}
}
