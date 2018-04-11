#include "Map.hpp"
#include <utility>

void ld::Map::Update(float delta)
{
}

void ld::Map::Draw(sf::RenderWindow& window)
{
	window.draw(*_map);
}

void ld::Map::InitPhysics(b2World& world)
{
}
void ld::Map::Init(std::string filePath)
{
	_map = std::move(TileMap(new tmx::TileMap(filePath)));
}
