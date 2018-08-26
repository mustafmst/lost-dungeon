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
		void InitGround(b2World & world);
		void InitGoldLayer(b2World & world);
	public:
		Map();
		void Init(std::string filePath);
		void Update(float delta);
		void Draw(sf::RenderWindow & window);
		void InitPhysics(b2World & world);
		sf::Vector2f GetPosition();
	};
}

