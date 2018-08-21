#include "ContactListener.hpp"
#include <iostream>
#include "GoldCoin.hpp"


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
		HandleCoinCollect(player, other);
	}
}

void ld::ContactListener::EndContact(b2Contact* contact)
{
}

void ld::ContactListener::HandleCoinCollect(Player* player, GameObject* other)
{
	auto coin = dynamic_cast<GoldCoin*>(other);
	if(coin == nullptr) return;
	player->GiveCoin();
	coin->_forDestroy = true;
}
