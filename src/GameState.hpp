#pragma once
#include <memory>
#include "GameObject.hpp"

namespace ld
{
	class GameState
	{
	public:
		virtual void Init() = 0;
		virtual void Update(float delta) = 0;
		virtual void Draw() = 0;
	};
}

