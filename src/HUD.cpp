#include "HUD.hpp"
#include <string>


void ld::HUD::Update()
{
	auto size = _healtBar->getSize();
		size.x = _data->playerInfo.GetHealthValue();
		_healtBar->setSize(size);
	auto coinsNum = std::to_string(_data->playerInfo.GetCoins());
	_coins.setString(coinsNum);
}

void ld::HUD::Draw()
{
	Update();
	_data->window.setView(_data->window.getDefaultView());
	_data->window.draw(*_healtBar);
	_coins.setPosition(0,0);
	_data->window.draw(_coins);
}

void ld::HUD::Init()
{
	_healtBar = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(sf::Vector2f(_data->playerInfo.GetHealthValue(), BarWidth)));
	_healtBar->setFillColor(sf::Color::Red);
	_healtBar->setPosition(10.f, 10.f);
	_coins.setFont(_data->assets.GetFont(FONT_NAME));
	_coins.setCharacterSize(70);
	
	
}
