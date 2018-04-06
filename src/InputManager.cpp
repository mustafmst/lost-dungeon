#include "InputManager.hpp"

void ld::InputManager::HandleBasicInputs(sf::RenderWindow & window)
{
	HandleCloseWindowEvent(window);
}

void ld::InputManager::HandleCloseWindowEvent(sf::RenderWindow & window)
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed) window.close();
	}
}


bool ld::InputManager::CheckIfMouseIsHovering(const sf::Vector2f  pos, sf::FloatRect bounds, sf::RenderWindow & window)
{
	sf::IntRect rect(pos.x, pos.y, bounds.width, bounds.height);
	return rect.contains(sf::Mouse::getPosition(window));
}


bool ld::InputManager::CheckIfWasClicked(const sf::Vector2f pos, sf::FloatRect bounds, sf::RenderWindow & window)
{
	sf::IntRect rect(pos.x, pos.y, bounds.width, bounds.height);
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return rect.contains(sf::Mouse::getPosition(window));
	}
	return false;
}