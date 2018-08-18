#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "GameState.hpp"

namespace ld
{
	class GameOver : public GameState
	{
	private:
		GameDataRef _data;
		sf::Text _gameTitle;
		sf::Text _playButton;
		sf::Text _exitButton;
	public:
		GameOver(GameDataRef data) : _data(data) {}
		void Init();
		void Update(float delta);
		void Draw();
	};
}

