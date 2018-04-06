#include "Game.hpp"
#include "SplashState.hpp"
#include "assetsAndDefinitions.h"

namespace ld
{
	Game::Game(int width, int height, std::string title):
		_width(width),
		_height(height),
		_title(title),
		_data(new GameData)
	{
		_data->window.create(sf::VideoMode(_width, _height), _title);
		_data->window.setFramerateLimit(FRAME_RATE);
		_data->stateMachine.AddState(GameStateRef(new SplashState(_data)));
		Run();
	}
	
	void Game::Run()
	{
		float delta = _clock.restart().asSeconds();
		while(_data->window.isOpen())
		{
			_data->input.HandleBasicInputs(_data->window);
			_data->stateMachine.HandleStateChanges();
			
			_data->stateMachine.CurrentState()->Update(delta);
			_data->stateMachine.CurrentState()->Draw();
			
			delta = _clock.restart().asSeconds();
		}
	}
}

