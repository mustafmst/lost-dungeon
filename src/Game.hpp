#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameData.h"

namespace ld
{
	class Game
	{
	private:
		int _width, _height;
		std::string _title;
		GameDataRef _data;
		sf::Clock _clock;
	public:
		Game(int width, int height, std::string title);
		void Run();
	};

}

