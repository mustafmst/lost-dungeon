#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

namespace ld
{
	struct GameData
	{
		sf::RenderWindow window;
	};
	
	typedef std::shared_ptr<GameData> GameDataRef;
	
	class Game
	{
	private:
		int _width, _height;
		std::string _title;
		GameDataRef _data;
		sf::Clock _clock;
		void Run();
	public:
		Game(int width, int height, std::string title);
	};

}

