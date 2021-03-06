#include "Map.hpp"
#include <utility>
#include "assetsAndDefinitions.h"

void ld::Map::Update(float delta)
{
}

void ld::Map::Draw(sf::RenderWindow& window)
{
	window.draw(*_map);
}

void ld::Map::InitPhysics(b2World& world)
{
	InitGround(world);
}

void ld::Map::Init(std::string filePath)
{
	_map = std::move(TileMap(new tmx::TileMap(filePath)));
}

void ld::Map::InitGround(b2World & world)
{
	int xTilesNum = _map->GetWidth();
	int yTilesNum = _map->GetHeight();
	tmx::Layer mapLayer = _map->GetLayer("map");
	for(int x = 0; x < xTilesNum; x++)
	{
		for(int y = 0; y < yTilesNum; y++)
		{
			tmx::Layer::Tile* tile = &mapLayer.GetTile(x,y);
			if(!tile->empty())
			{
				b2BodyDef def2;
				def2.position = b2Vec2((x*16.f)/F_SCALE, (y*16.f)/F_SCALE);
				def2.type = b2_staticBody;
				def2.userData = this;
				b2Body* body = std::move(world.CreateBody(&def2));
				
				b2PolygonShape box2;
				box2.SetAsBox(8.f/F_SCALE,8.f/F_SCALE);
				b2FixtureDef box2Fix;
				box2Fix.shape = &box2;
				box2Fix.density = 0.50f;
				box2Fix.friction = 0.f;
				body->CreateFixture(&box2Fix);
			}
		}
	}
}

void ld::Map::InitGoldLayer(b2World& world)
{
	int xTilesNum = _map->GetWidth();
	int yTilesNum = _map->GetHeight();
	tmx::Layer mapLayer = _map->GetLayer("gold");
	for(int x = 0; x < xTilesNum; x++)
	{
		for(int y = 0; y < yTilesNum; y++)
		{
			tmx::Layer::Tile* tile = &mapLayer.GetTile(x,y);
			if(!tile->empty())
			{
				b2BodyDef def2;
				def2.position = b2Vec2((x*16.f)/F_SCALE, (y*16.f)/F_SCALE);
				def2.type = b2_staticBody;
				b2Body* body = std::move(world.CreateBody(&def2));
				
				b2PolygonShape box2;
				box2.SetAsBox(8.1f/F_SCALE,8.1f/F_SCALE);
				b2FixtureDef box2Fix;
				box2Fix.shape = &box2;
				box2Fix.density = 1;
				box2Fix.friction = 0.f;
				body->CreateFixture(&box2Fix);
			}
		}
	}
}

sf::Vector2f ld::Map::GetPosition()
{
	return sf::Vector2f();
}

ld::Map::Map()
{
	_type = MAP;
}
