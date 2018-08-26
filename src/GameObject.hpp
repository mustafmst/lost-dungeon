#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <string>
#include "gameObjectTypes.h"

namespace ld
{
	class GameObject
	{
	public:
		GameObject() {}
		~GameObject() {}
		std::string _type = GAME_OBJECT;
		bool _forDestroy = false;
		bool ForDestroy(){return _forDestroy;};
		virtual void Update(float delta) = 0;
		virtual void Draw(sf::RenderWindow & window) = 0;
		virtual void InitPhysics(b2World & world) = 0;
	};
	typedef std::shared_ptr<GameObject> GameObjectRef;
}

