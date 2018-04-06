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
			_data->input.HandleBasicInputs(_data->window);
			
			delta = _clock.restart().asSeconds();
		}
	}
}

