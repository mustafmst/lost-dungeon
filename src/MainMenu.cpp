#include "MainMenu.hpp"
#include "assetsAndDefinitions.h"
#include <iostream>
#include "PlayState.hpp"

void ld::MainMenu::Init()
{
	_data->assets.LoatFont(FONT_NAME, FONT_FILEPATH);
	
	_gameTitle.setFont(_data->assets.GetFont(FONT_NAME));
	_gameTitle.setCharacterSize(70);
	_gameTitle.setString("LOST DUNGEON");
	_gameTitle.setPosition( (_data->window.getSize().x / 2) - (_gameTitle.getGlobalBounds().width / 2 ), 50 );
	
	_playButton.setFont(_data->assets.GetFont(FONT_NAME));
	_playButton.setCharacterSize(40);
	_playButton.setString("PLAY");
	_playButton.setPosition( (_data->window.getSize().x / 2) - (_playButton.getGlobalBounds().width / 2 ), 300 );
	
	_exitButton.setFont(_data->assets.GetFont(FONT_NAME));
	_exitButton.setCharacterSize(40);
	_exitButton.setString("EXIT");
	_exitButton.setPosition( (_data->window.getSize().x / 2) - (_exitButton.getGlobalBounds().width / 2 ), 400 );
}

void ld::MainMenu::Update(float delta)
{
	if(_data->input.CheckIfMouseIsHovering(_playButton.getPosition(), _playButton.getGlobalBounds(), _data->window))
	{
		_playButton.setColor(sf::Color::Cyan);
	} else
	{
		_playButton.setColor(sf::Color::White);
	}
	
	if(_data->input.CheckIfMouseIsHovering(_exitButton.getPosition(), _exitButton.getGlobalBounds(), _data->window))
	{
		_exitButton.setColor(sf::Color::Cyan);
	} else
	{
		_exitButton.setColor(sf::Color::White);
	}
	
	if(_data->input.CheckIfWasClicked(_exitButton.getPosition(), _exitButton.getGlobalBounds(), _data->window))
	{
		_data->window.close();
	}
	if(_data->input.CheckIfWasClicked(_playButton.getPosition(), _playButton.getGlobalBounds(), _data->window))
	{
		_data->stateMachine.AddState(GameStateRef(new PlayState(_data)));
	}
}

void ld::MainMenu::Draw()
{
	_data->window.clear();
	
	_data->window.draw(_gameTitle);
	_data->window.draw(_playButton);
	_data->window.draw(_exitButton);
	
	_data->window.display();
}

