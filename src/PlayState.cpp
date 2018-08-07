#include "PlayState.hpp"
#include <utility>
#include <STP/TMXLoader.hpp>
#include "Map.hpp"
#include "assetsAndDefinitions.h"

void ld::PlayState::Init()
{
	// Remember to init map first
	InitMap(_mapName);
	InitPlayer();
}

void ld::PlayState::Update(float delta)
{
	_world.Step(delta, 8, 3);
	HandleInputs();
	for(auto o : _gameObjects)
		o->Update(delta);
}

void ld::PlayState::Draw()
{
	_data->window.clear();
	for(auto o : _gameObjects)
		o->Draw(_data->window);
	if(DEBUG)
	{
		//map debug
		sf::RectangleShape rec;
		rec.setFillColor(sf::Color(0,0,0,0));
		rec.setOutlineThickness(1);
		rec.setOutlineColor(sf::Color::Cyan);
		for(b2Body* b = _world.GetBodyList(); b; b = b->GetNext())
		{
			if(b->GetType()==b2_staticBody)
			{
				rec.setSize(sf::Vector2f(16.f, 16.f));
				rec.setPosition(b->GetPosition().x*F_SCALE, b->GetPosition().y*F_SCALE);
			}
			else if(b->GetType()==b2_dynamicBody)
			{
				rec.setSize(sf::Vector2f(16.f, 34.f));
				rec.setPosition(b->GetPosition().x*F_SCALE, (b->GetPosition().y*F_SCALE)-11.f);
			}
			
			_data->window.draw(rec);
		}
	}
	_data->window.display();  
}

void ld::PlayState::HandleInputs()
{
	if(_data->input.CheckIfKeyIsPressed(sf::Keyboard::Escape))
	{
		_data->stateMachine.RemoveState();
	}
}

void ld::PlayState::InitPlayer()
{
	_data->assets.LoadTexture(PLAYER_NAME, PLAYER_FILEPATH);
	Player player(_data->input);
	player.Init(_data->assets.GetTexture(PLAYER_NAME));
	player.InitPhysics(_world);
	_gameObjects.push_back(GameObjectRef(new Player(player)));
}

void ld::PlayState::InitMap(std::string mapFilePath)
{
	_map.Init(mapFilePath);
	_map.InitPhysics(_world);
	_gameObjects.push_back(GameObjectRef(new Map(_map)));
}
