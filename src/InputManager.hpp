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
		bool CheckIfMouseIsHovering(const sf::Vector2f pos, sf::FloatRect bounds, sf::RenderWindow & window);
		bool CheckIfWasClicked(const sf::Vector2f pos, sf::FloatRect bounds, sf::RenderWindow & window);
		bool CheckIfKeyIsPressed(sf::Keyboard::Key key);
	};
}

