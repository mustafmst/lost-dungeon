#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameState.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "PlayerInfoManager.hpp"

namespace ld
{
	struct GameData
	{
		sf::RenderWindow window;
		InputManager input;
		StateMachine stateMachine;
		AssetManager assets;
		PlayerInfoManager playerInfo;
	};
	
	typedef std::shared_ptr<GameData> GameDataRef;
}