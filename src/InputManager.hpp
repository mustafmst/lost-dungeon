#pragma once
#include <SFML/Graphics.hpp>

namespace ld
{

class InputManager
{
private:
	void HandleCloseWindowEvent(sf::RenderWindow & window);
public:
	InputManager() {}
	~InputManager() {}
	void HandleBasicInputs(sf::RenderWindow & window);
};

}

