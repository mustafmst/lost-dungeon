#include "HUD.hpp"


void ld::HUD::Update()
{
	auto size = _healtBar->getSize();
		size.x = _data->playerInfo.GetHealthValue();
		_healtBar->setSize(size);
}

void ld::HUD::Draw()
{
	Update();
	_data->window.setView(_data->window.getDefaultView());
	_data->window.draw(*_healtBar);
}

void ld::HUD::Init()
{
	_healtBar = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(sf::Vector2f(_data->playerInfo.GetHealthValue(), BarWidth)));
	_healtBar->setFillColor(sf::Color::Red);
	_healtBar->setPosition(10.f, 10.f);
}
