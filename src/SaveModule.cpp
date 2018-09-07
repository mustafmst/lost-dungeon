#include "SaveModule.hpp"
#include "GameObject.hpp"
#include "GameObjectsCodes.h"
#include "SaveConfig.h"
#include <fstream>
#include "GameData.h"
#include "PlayState.hpp"
#include "gameObjectTypes.h"
#include "PlayState.hpp"

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
	ofstream saveFile(SAVE_FILE_NAME);
	saveFile << _data->playerInfo.GetHealthValue() << " " << _data->playerInfo.GetCoins() << " " << _data->playerInfo.CanDoubleJump() << endl;
	auto gameobjects = dynamic_cast<PlayState*>(&*_data->stateMachine.CurrentState())->_gameObjects;
	for(auto o : gameobjects)
	{
		if(o->_type == MAP ||
			o->_type == DOUBLE_JUMP ||
			o->_type == FINISH ||
			o->ForDestroy())
			continue;
		saveFile << o->GetSaveData() << endl;
	}
	_saveExists = (bool)saveFile;
	saveFile.close();
}

bool ld::SaveModule::SaveExists()
{
	return _saveExists;
}

void ld::SaveModule::CreatePlayer(float x, float y, PlayState& playState)
{
}

void ld::SaveModule::CreateSkeleton(float x, float y, float left, float right, PlayState& playState)
{
}

void ld::SaveModule::CreateGold(float x, float y, PlayState& playState)
{
}

void ld::SaveModule::CreatePotion(float x, float y, PlayState& playState)
{
}

void ld::SaveModule::SetData(GameDataRef data)
{
	_data = data;
	_objectCreators[PLAYER_CODE] = CreatePlayer;
	_objectCreators[GOLD_COIN_CODE] = CreateGold;
	_objectCreators[POTION_CODE] = CreatePotion;
	
	ifstream saveFile(SAVE_FILE_NAME);
	_saveExists = (bool)saveFile;
	saveFile.close();
}

void ld::SaveModule::DeleteSave()
{
	_saveExists = false;
}
