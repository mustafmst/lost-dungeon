#pragma once
#include <memory>
#include "GameData.h"
#include "GameObject.hpp"

namespace ld
{

class HUD
{
	const float BarWidth = 20.f;
	GameDataRef _data;
	std::unique_ptr<sf::RectangleShape> _healtBar;
public:
	HUD(GameDataRef data): _data(data) {};
	void Init();
	void Update();
	void Draw();
};

}

