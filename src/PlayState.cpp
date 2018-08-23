#include "PlayState.hpp"
#include <utility>
#include <STP/TMXLoader.hpp>
#include "Map.hpp"
#include "assetsAndDefinitions.h"
#include "GoldCoin.hpp"
#include "Skeleton.hpp"

void ld::PlayState::Init()
{
	// Remember to init map first
	_data->assets.LoadTexture(GEMS_NAME, GEMS_FILEPATH);
	_eventHandler = std::unique_ptr<ContactListener>(new ContactListener());
	_world.SetContactListener(&*_eventHandler);
	_hud = std::unique_ptr<HUD>(new HUD(_data));
	_hud->Init();
	InitMap(_mapName);
	InitPlayer();
	InitCamera();
	InitCoins();
	InitEnemies();
}

void ld::PlayState::Update(float delta)
{
	_world.Step(delta, 8, 3);
	HandleInputs();
	int index = 0;
	std::vector<GameObjectRef> gameObjects = _gameObjects;
	for(auto o : _gameObjects)
	{
		if(!o->ForDestroy())
		{
			o->Update(delta);
		}
		else
		{
			gameObjects.erase(gameObjects.begin()+index);
			index--;
		}
		index++;
	}
	_gameObjects = gameObjects;
}

void ld::PlayState::Draw()
{
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
	_player = std::shared_ptr<Player>(new Player(_data));
	_player->Init(_data->assets.GetTexture(PLAYER_NAME));
	_player->InitPhysics(_world);
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
	auto forwardDirection = _player->GetDirection();
	forwardDirection.x = forwardDirection.x*CAMERA_FORWARD;
	forwardDirection.y = forwardDirection.y*CAMERA_FORWARD;
	auto r = (_player->GetPosition()+sf::Vector2f(forwardDirection.x, forwardDirection.y))-_camera->getCenter();
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

void ld::PlayState::AddCoin(float x, float y)
{
	auto coin = std::shared_ptr<GoldCoin>(new GoldCoin());
	coin->Init(_data->assets.GetTexture(GEMS_NAME));
	coin->SetPosition(x*16,y*16);
	coin->InitPhysics(_world);
	_gameObjects.push_back(coin);
}

void ld::PlayState::InitCoins()
{
	AddCoin(17,14);
	AddCoin(18,14);
	AddCoin(19,14);
}

void ld::PlayState::InitEnemies()
{
	auto skel = new Skeleton(_data, sf::Vector2f(150.f,300.f),10.f, 500.f);
	skel->InitPhysics(_world);
	_gameObjects.push_back(GameObjectRef(skel));
}
