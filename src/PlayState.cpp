#include "PlayState.hpp"
#include <utility>
#include "assetsAndDefinitions.h"

void ld::PlayState::Init()
{
	_data->assets.LoadTexture(PLAYER_NAME, PLAYER_FILEPATH);
	_player.setTexture(_data->assets.GetTexture(PLAYER_NAME));
	_player.setPosition( (_data->window.getSize().x/2) - (_player.getGlobalBounds().width/2), 480 );
}

void ld::PlayState::Update(float delta)
{
	HandleInputs();
}

void ld::PlayState::Draw()
{
	_data->window.clear();
	_data->window.draw(_map);
	_data->window.draw(_player);
	_data->window.display();
}

void ld::PlayState::HandleInputs()
{
	if(_data->input.CheckIfKeyIsPressed(sf::Keyboard::Escape))
	{
		_data->stateMachine.RemoveState();
	}
}
