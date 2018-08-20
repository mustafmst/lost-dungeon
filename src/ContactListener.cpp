#include "ContactListener.hpp"
#include <iostream>
#include "GameObject.hpp"
#include "Player.hpp"
#include "GoldCoin.hpp"


void ld::ContactListener::BeginContact(b2Contact* contact)
{
	if(contact && contact->IsTouching())
	{
		HandleCoinCollect(contact);
	}
}

void ld::ContactListener::EndContact(b2Contact* contact)
{
}

void ld::ContactListener::HandleCoinCollect(b2Contact* contact)
{
	auto A = static_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
	auto B = static_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData());
	if(A == nullptr || B == nullptr) return;
	auto player = dynamic_cast<Player*>(A);
	if(player == nullptr){
		player = dynamic_cast<Player*>(B);
		if(player == nullptr) return;
	}
	auto coin = dynamic_cast<GoldCoin*>(A);
	if(coin == nullptr){
		coin = dynamic_cast<GoldCoin*>(B);
		if(coin == nullptr) return;
	}
	player->GiveCoin();
	coin->_forDestroy = true;
}
