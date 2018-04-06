#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameState.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"

namespace ld
{
	struct GameData
	{
		sf::RenderWindow window;
		InputManager input;
		StateMachine stateMachine;
	};
	
	typedef std::shared_ptr<GameData> GameDataRef;
}