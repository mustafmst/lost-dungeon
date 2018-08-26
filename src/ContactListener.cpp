#include "ContactListener.hpp"
#include <iostream>
#include "GoldCoin.hpp"
#include "Skeleton.hpp"


void ld::ContactListener::BeginContact(b2Contact* contact)
{
	if(contact && contact->IsTouching())
	{
		auto A = static_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
		auto B = static_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData());
		if(A == nullptr || B == nullptr) return;
		auto player = dynamic_cast<Player*>(A);
		GameObject* other = B;
		if(player == nullptr){
			player = dynamic_cast<Player*>(B);
			other = A;
			if(player == nullptr) return;
		}
		if(other->_type == COIN) if(HandleCoinCollect(player, other)) return;
		if(other->_type == ENEMY) if(HandleEnemyCollision(player, other)) return;
	}
}

void ld::ContactListener::EndContact(b2Contact* contact)
{
}

bool ld::ContactListener::HandleCoinCollect(Player* player, GameObject* other)
{
	auto coin = static_cast<GoldCoin*>(other);
	if(coin == nullptr) return false;
	player->GiveCoin();
	coin->_forDestroy = true;
	return true;
}

bool ld::ContactListener::HandleEnemyCollision(Player* player, GameObject* other)
{
	auto enemy = static_cast<Skeleton*>(other);
	if(enemy == nullptr) return false;
	player->Hurt(enemy->GetDamage());
	return true;
}
