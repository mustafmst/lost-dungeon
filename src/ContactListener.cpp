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
		if(other->_type == COIN) HandleCoinCollect(player, other);
		if(other->_type == HP) HandlePotionCollect(player, other);
		if(other->_type == FINISH) HandleFinish(player, other);
		if(other->_type == DOUBLE_JUMP) HandleDoubleJumpAddition(player, other);
		if(other->_type == ENEMY) HandleEnemyCollision(player, other);
		if(other->_type == MAP) HandleMapCollision(player);
	}
}

void ld::ContactListener::EndContact(b2Contact* contact)
{
}

void ld::ContactListener::HandleCoinCollect(Player* player, GameObject* other)
{
	player->GiveCoin();
	other->_forDestroy = true;
}

void ld::ContactListener::HandleEnemyCollision(Player* player, GameObject* other)
{
	auto enemy = static_cast<Skeleton*>(other);
	if(enemy == nullptr) return;
	player->Hurt(enemy->GetDamage());
}

void ld::ContactListener::HandlePotionCollect(Player* player, GameObject* other)
{
	player->Heal(100.f);
	other->_forDestroy = true;
}

void ld::ContactListener::HandleFinish(Player* player, GameObject* other)
{
	player->FinishGame();
	other->_forDestroy = true;
}

void ld::ContactListener::HandleDoubleJumpAddition(Player* player, GameObject* other)
{
	player->UnlockDoubleJump();
	other->_forDestroy = true;
}

void ld::ContactListener::HandleMapCollision(Player* player)
{
	player->ResetJump();
}
