#include "MainMenu.hpp"
#include "assetsAndDefinitions.h"
#include "PlayState.hpp"

void ld::MainMenu::Init()
{
	
	_gameTitle.setFont(_data->assets.GetFont(FONT_NAME));
	_gameTitle.setCharacterSize(70);
	_gameTitle.setString("LOST DUNGEON");
	_gameTitle.setPosition( (_data->window.getSize().x / 2) - (_gameTitle.getGlobalBounds().width / 2 ), 50 );
	
	_playButton.setFont(_data->assets.GetFont(FONT_NAME));
	_playButton.setCharacterSize(40);
	_playButton.setString("PLAY");
	_playButton.setPosition( (_data->window.getSize().x / 2) - (_playButton.getGlobalBounds().width / 2 ), 300 );
	
	_loadButton.setFont(_data->assets.GetFont(FONT_NAME));
	_loadButton.setCharacterSize(40);
	_loadButton.setString("LOAD");
	_loadButton.setPosition( (_data->window.getSize().x / 2) - (_loadButton.getGlobalBounds().width / 2 ), 400 );
	
	_exitButton.setFont(_data->assets.GetFont(FONT_NAME));
	_exitButton.setCharacterSize(40);
	_exitButton.setString("EXIT");
	_exitButton.setPosition( (_data->window.getSize().x / 2) - (_exitButton.getGlobalBounds().width / 2 ), 500 );
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
	
	
	if(!_data->save.SaveExists())
	{
		_loadButton.setColor(sf::Color(102,102,102));
	}
	else if(_data->input.CheckIfMouseIsHovering(_loadButton.getPosition(), _loadButton.getGlobalBounds(), _data->window))
	{
		_loadButton.setColor(sf::Color::Cyan);
	} else
	{
		_loadButton.setColor(sf::Color::White);
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
	if(_data->save.SaveExists() && _data->input.CheckIfWasClicked(_loadButton.getPosition(), _loadButton.getGlobalBounds(), _data->window))
	{
		_data->playerInfo.Reset();
		_data->stateMachine.AddState(GameStateRef(new PlayState(_data, MAP_FILEPATH, true)));
	}
	if(_data->input.CheckIfWasClicked(_playButton.getPosition(), _playButton.getGlobalBounds(), _data->window))
	{
		_data->playerInfo.Reset();
		_data->stateMachine.AddState(GameStateRef(new PlayState(_data, MAP_FILEPATH, false)));
	}
}

void ld::MainMenu::Draw()
{
	_data->window.clear();
	
	_data->window.draw(_gameTitle);
	_data->window.draw(_playButton);
	_data->window.draw(_loadButton);
	_data->window.draw(_exitButton);
	
	_data->window.display();
}

