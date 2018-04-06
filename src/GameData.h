#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "InputManager.hpp"

namespace ld
{
	struct GameData
	{
		sf::RenderWindow window;
		InputManager input;
	};
	
	typedef std::shared_ptr<GameData> GameDataRef;
}