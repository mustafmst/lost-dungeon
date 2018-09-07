#pragma once

namespace ld
{

class PlayerInfoManager
{
	int _coins = 0;
	float _health = 100.f;
	const float HealthMax = 100.f;
	const float HealthMin = 0.f;
	bool _doubleJumpUnlocked = false;
public:
	PlayerInfoManager(){};
	~PlayerInfoManager(){};
	void ChangeHealth(float healtDelta);
	float GetHealthValue();
	void GiveCoin();
	int GetCoins();
	bool GameIsOver();
	void Reset();
	void UnlockDoubleJump();
	bool CanDoubleJump();
};

}

