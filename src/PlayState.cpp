#include "PlayState.hpp"
#include <utility>

void ld::PlayState::Init()
{
	
}

void ld::PlayState::Update(float delta)
{
	HandleInputs();
}

void ld::PlayState::Draw()
{
	_data->window.clear();
	for(auto & obj : _objects)
	{
		_data->window.draw(*obj);
	}
	_data->window.display();
}

void ld::PlayState::HandleInputs()
{
	if(_data->input.CheckIfKeyIsPressed(sf::Keyboard::Escape))
	{
		_data->stateMachine.RemoveState();
	}
}
