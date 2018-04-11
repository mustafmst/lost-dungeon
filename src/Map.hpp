#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <STP/TMXLoader.hpp>
#include <string>
#include "GameObject.hpp"

namespace ld
{
	typedef std::shared_ptr<tmx::TileMap> TileMap;
	class Map : public GameObject
	{
	private:
		TileMap _map;
	public:
		Map() {}
		~Map() {}
		void Init(std::string filePath);
		void Update(float delta);
		void Draw(sf::RenderWindow & window);
		void InitPhysics(b2World & world);
	};
}

