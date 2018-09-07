#include "PlayState.hpp"
#include <utility>
#include <STP/TMXLoader.hpp>
#include "Map.hpp"
#include "assetsAndDefinitions.h"
#include "GoldCoin.hpp"
#include "Skeleton.hpp"
#include "HealthPotion.hpp"
#include "Finish.hpp"
#include "DoubleJump.hpp"

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
	InitHP();
	InitCoins();
	InitDoubleJump();
	InitEnemies();
	InitFinish();
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
#if GRID
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
		_data->save.SaveGame();
		_data->stateMachine.RemoveState();
	}
}

void ld::PlayState::InitPlayer()
{
	_data->assets.LoadTexture(PLAYER_NAME, PLAYER_FILEPATH);
	_player = std::shared_ptr<Player>(new Player(_data));
	_player->Init(_data->assets.GetTexture(PLAYER_NAME), sf::Vector2f(2*TILE_SIZE, 3*TILE_SIZE));
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

void ld::PlayState::InitCoins()
{
	AddCoin(9,4);
	AddCoin(7,4);
	AddCoin(5,4);
	AddCoin(30,35);
	AddCoin(32,35);
	AddCoin(34,35);
	AddCoin(36,35);
	AddCoin(38,35);
	AddCoin(54,31);
	AddCoin(49,31);
	AddCoin(45,29);
	AddCoin(42,29);
	AddCoin(56,26);
	AddCoin(46,22);
	AddCoin(41,22);
	AddCoin(32,19);
	AddCoin(21,27);
	AddCoin(23,27);
	AddCoin(25,27);
	AddCoin(34,7);
	AddCoin(36,7);
	AddCoin(38,7);
	AddCoin(40,7);
	AddCoin(42,7);
	AddCoin(62,12);
	AddCoin(64,12);
	AddCoin(74,9);
	AddCoin(78,6);
	AddCoin(109,8);
	AddCoin(141,16);
	AddCoin(142,16);
	AddCoin(143,16);
	AddCoin(144,16);
	AddCoin(145,16);
	AddCoin(146,16);
	AddCoin(147,16);
}

void ld::PlayState::InitEnemies()
{
	AddEnemy(30,2,25,48);
	AddEnemy(49,17,0,100);
	AddEnemy(82,3,80,101);
	AddEnemy(82,3,80,101);
	AddEnemy(126,47,80,130);
}

void ld::PlayState::InitHP()
{
	AddHP(19,36);
	AddHP(48,18);
	AddHP(128,48);
}

void ld::PlayState::InitFinish()
{
	AddFinish();
}

void ld::PlayState::AddCoin(int x, int y)
{
	auto coin = std::shared_ptr<GoldCoin>(new GoldCoin(_data, sf::Vector2f(x*16.f,y*16.f), _world));
	_gameObjects.push_back(coin);
}

void ld::PlayState::AddHP(int x, int y)
{
	auto hp = std::shared_ptr<HealthPotion>(new HealthPotion(_data, sf::Vector2f(x*16.f,y*16.f),_world));
	_gameObjects.push_back(hp);
}

void ld::PlayState::AddFinish()
{
	auto finish = std::shared_ptr<Finish>(new Finish(_data, sf::Vector2f(98*16,30*16), _world));
	_gameObjects.push_back(finish);
};

void ld::PlayState::AddEnemy(int x, int y, int left, int right)
{
	auto skel = new Skeleton(_data, sf::Vector2f(x*TILE_SIZE,y*TILE_SIZE),left*TILE_SIZE, right*TILE_SIZE);
	skel->InitPhysics(_world);
	_gameObjects.push_back(GameObjectRef(skel));
}

void ld::PlayState::InitDoubleJump()
{
	auto dj = new DoubleJump(_data, sf::Vector2f(104*16,47*16), _world);
	_gameObjects.push_back(GameObjectRef(dj));
}
