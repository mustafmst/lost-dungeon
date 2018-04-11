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
	Player player;
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
