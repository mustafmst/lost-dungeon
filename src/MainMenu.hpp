#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "GameState.hpp"

namespace ld
{
	class MainMenu : public GameState
	{
	private:
		GameDataRef _data;
		sf::Text _gameTitle;
	public:
		MainMenu(GameDataRef data) : _data(data) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

