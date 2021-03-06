#include "PlayerInfoManager.hpp"



void ld::PlayerInfoManager::ChangeHealth(float healthDelta)
{
	_health += healthDelta;
	if(_health > HealthMax) _health = HealthMax;
	if(_health < HealthMin) _health = HealthMin;
}

float ld::PlayerInfoManager::GetHealthValue()
{
	return _health;
}

bool ld::PlayerInfoManager::GameIsOver()
{
	return _health <= HealthMin;
}

void ld::PlayerInfoManager::Reset()
{
	_health = HealthMax;
	_coins = 0;
}

void ld::PlayerInfoManager::GiveCoin()
{
	_coins++;
}

int ld::PlayerInfoManager::GetCoins()
{
	return _coins;
}

void ld::PlayerInfoManager::UnlockDoubleJump()
{
	_doubleJumpUnlocked = true;
}

bool ld::PlayerInfoManager::CanDoubleJump()
{
	return _doubleJumpUnlocked;
}

void ld::PlayerInfoManager::GiveCoins(int count)
{
	_coins += count;
}
