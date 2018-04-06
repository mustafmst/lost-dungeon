#include "MainMenu.hpp"
#include "assetsAndDefinitions.h"

void ld::MainMenu::Init()
{
	_data->assets.LoatFont(FONT_NAME, FONT_FILEPATH);
	_gameTitle.setFont(_data->assets.GetFont(FONT_NAME));
	_gameTitle.setCharacterSize(70);
	_gameTitle.setString("LOST DUNGEON");
	_gameTitle.setPosition( (_data->window.getSize().x / 2) - (_gameTitle.getGlobalBounds().width / 2 ), 50 );
}

void ld::MainMenu::Update(float delta)
{
	
}

void ld::MainMenu::Draw()
{
	_data->window.clear();
	
	_data->window.draw(_gameTitle);
	
	_data->window.display();
}

