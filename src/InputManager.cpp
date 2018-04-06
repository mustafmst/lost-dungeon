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

