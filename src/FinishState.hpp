#pragma once
#include "SplashState.hpp"

namespace ld
{

class FinishState : public SplashState
{
public:
	FinishState(GameDataRef data): SplashState(data){}
	void Init();
};

}

