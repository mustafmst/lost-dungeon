#include "Game.hpp"

namespace ld
{
	Game::Game(int width, int height, std::string title):
		_width(width),
		_height(height),
		_title(title),
		_data(new GameData)
	{
		_data->window.create(sf::VideoMode(_width, _height), _title);
		Run();
	}
	
	void Game::Run()
	{
		float delta = _clock.restart().asSeconds();
		while(_data->window.isOpen())
		{
			sf::Event event;
			while(_data->window.pollEvent(event))
			{
				if(event.type == sf::Event::Closed) _data->window.close();
			}
			
			
			delta = _clock.restart().asSeconds();
		}
	}
}

