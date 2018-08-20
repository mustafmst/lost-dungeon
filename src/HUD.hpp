#pragma once
#include <memory>
#include "GameData.h"
#include "GameObject.hpp"
#include "assetsAndDefinitions.h"

namespace ld
{

class HUD
{
	const float BarWidth = 20.f;
	GameDataRef _data;
	std::unique_ptr<sf::RectangleShape> _healtBar;
	sf::Text _coins;
public:
	HUD(GameDataRef data): _data(data) {};
	void Init();
	void Update();
	void Draw();
};

}

