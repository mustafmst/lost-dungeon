#include "HUD.hpp"

void ld::HUD::Update(float delta)
{
	auto size = _healtBar->getSize();
	size.x -= 1.f;
	_healtBar->setSize(size);
}

void ld::HUD::Draw(sf::RenderWindow& window)
{
	window.draw(*_healtBar);
}

void ld::HUD::Init()
{
	_healtBar = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(sf::Vector2f(MaxBarLength, BarWidth)));
	_healtBar->setFillColor(sf::Color::Red);
	_healtBar->setPosition(10.f, 10.f);
}
