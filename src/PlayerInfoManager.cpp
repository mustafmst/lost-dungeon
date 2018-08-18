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
