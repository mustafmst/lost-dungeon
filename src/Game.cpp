#include "Game.hpp"
#include "SplashState.hpp"
#include "PlayState.hpp"
#include "assetsAndDefinitions.h"

namespace ld
{
	Game::Game(int width, int height, std::string title):
		_width(width),
		_height(height),
		_title(title),
		_data(new GameData),
		_clock()
	{
		_data->window.create(sf::VideoMode(_width, _height), _title);
		_data->window.setFramerateLimit(FRAME_RATE);
		_data->save.SetData(_data);
#if DEBUG
			_data->stateMachine.AddState(GameStateRef(new PlayState(_data, MAP_FILEPATH)));
#else
			_data->stateMachine.AddState(GameStateRef(new SplashState(_data)));
#endif
	}
	
	void Game::Run()
	{
		LoadAssets();
		float delta = 0.f;
		while(_data->window.isOpen())
		{
			delta = _clock.restart().asSeconds();
			_data->input.HandleBasicInputs(_data->window);
			_data->stateMachine.HandleStateChanges();
			
			_data->stateMachine.CurrentState()->Update(delta);
			_data->window.clear();
			_data->stateMachine.CurrentState()->Draw();
		}
	}
}

void ld::Game::LoadAssets()
{
	_data->assets.LoatFont(FONT_NAME, FONT_FILEPATH);
	_data->assets.LoatFont(FONT_SECONDARY_NAME, FONT_SECONDARY_FILEPATH);
	_data->assets.LoadTexture(SKELETON_IDLE_NAME, SKELETON_IDLE_FILEPATH);
}
