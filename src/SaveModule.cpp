#include "SaveModule.hpp"
#include "GameObject.hpp"
#include "GameObjectsCodes.h"

using namespace std;
using namespace ld;

ld::SaveModule::SaveModule(): _objectCreators()
{
}

ld::SaveModule::~SaveModule()
{
}

void ld::SaveModule::LoadSave()
{
}

void ld::SaveModule::SaveGame()
{
	_saveExists = true;
}

bool ld::SaveModule::SaveExists()
{
	return _saveExists;
}

shared_ptr<GameObject> ld::SaveModule::CreatePlayer(float x, float y)
{
}

shared_ptr<GameObject> ld::SaveModule::CreateSkeleton(float x, float y)
{
}

shared_ptr<GameObject> ld::SaveModule::CreateGold(float x, float y)
{
}

shared_ptr<GameObject> ld::SaveModule::CreatePotion(float x, float y)
{
}

void ld::SaveModule::SetData(GameDataRef data)
{
	_data = data;
	_objectCreators[PLAYER_CODE] = CreatePlayer;
	_objectCreators[SKELETON_CODE] = CreateSkeleton;
	_objectCreators[GOLD_COIN_CODE] = CreateGold;
	_objectCreators[POTION_CODE] = CreatePotion;
}

void ld::SaveModule::DeleteSave()
{
	_saveExists = false;
}
