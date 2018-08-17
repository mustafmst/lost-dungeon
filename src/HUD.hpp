#pragma once
#include <memory>
#include "GameData.h"
#include "GameObject.hpp"

namespace ld
{

class HUD : public GameObject
{
	const float BarWidth = 20.f;
	const float MaxBarLength = 100.f;
	GameDataRef _data;
	std::unique_ptr<sf::RectangleShape> _healtBar;
public:
	HUD(GameDataRef data): _data(data);
	void Init();
	void Update(float delta);
	void Draw(sf::RenderWindow & window);
};

}

