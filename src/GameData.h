#include <SFML/Graphics.hpp>
#include "InputManager.hpp"

namespace ld
{
	struct GameData
	{
		sf::RenderWindow window;
		InputManager input;
	};
	
	typedef std::shared_ptr<GameData> GameDataRef;
}