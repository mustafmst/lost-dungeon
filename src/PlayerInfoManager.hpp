#pragma once

namespace ld
{

class PlayerInfoManager
{
	float _health = 100.f;
	const float HealthMax = 100.f;
	const float HealthMin = 0.f;
public:
	PlayerInfoManager(){};
	~PlayerInfoManager(){};
	void ChangeHealth(float healtDelta);
	float GetHealthValue();
};

}

