#pragma once
#include "Box2D/Box2D.h"
#include "GameObject.hpp"
#include "Player.hpp"

namespace ld
{

class ContactListener: public b2ContactListener
{
public:
	ContactListener(){};
	~ContactListener(){};
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void HandleCoinCollect(Player* player, GameObject* other);
	void HandlePotionCollect(Player* player, GameObject* other);
	void HandleEnemyCollision(Player* player, GameObject* other);
};

}

