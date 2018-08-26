#pragma once
#include <memory>
#include "GameObject.hpp"

namespace ld
{
	class GameState
	{
	public:
		std::vector<GameObjectRef> _gameObjects;
		virtual void Init() = 0;
		virtual void Update(float delta) = 0;
		virtual void Draw() = 0;
	};
}

