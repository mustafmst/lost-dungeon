#include "PlayState.hpp"
#include <utility>
#include <STP/TMXLoader.hpp>
#include "Map.hpp"
#include "assetsAndDefinitions.h"

void ld::PlayState::Init()
{
	// Remember to init map first
	_hud = std::unique_ptr<HUD>(new HUD(_data));
	_hud->Init();
	InitMap(_mapName);
	InitPlayer();
	InitCamera();
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
	UpdateCamera();
	for(auto o : _gameObjects)
		o->Draw(_data->window);
#if DEBUG
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
#endif
	_hud->Draw();
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
	Player player(_data);
	player.Init(_data->assets.GetTexture(PLAYER_NAME));
	player.InitPhysics(_world);
	_player = std::make_shared<Player>(player);
	_gameObjects.push_back(_player);
}

void ld::PlayState::InitMap(std::string mapFilePath)
{
	_map.Init(mapFilePath);
	_map.InitPhysics(_world);
	_gameObjects.push_back(GameObjectRef(new Map(_map)));
}
void ld::PlayState::UpdateCamera()
{
	auto r = _player->GetPosition()-_camera->getCenter();
	_camera->move(r.x/CAMERA_DELAY, r.y/CAMERA_DELAY);
	_data->window.setView(*_camera);
}
void ld::PlayState::InitCamera()
{
	
	_camera = std::unique_ptr<sf::View>(new sf::View);
	_camera->setCenter(_player->GetPosition());
	_camera->setSize(SCREEN_WIDTH/CAMERA_SCALE,SCREEN_HEIGTH/CAMERA_SCALE);
	_data->window.setView(*_camera.get());
}
