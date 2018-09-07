#include "SaveModule.hpp"
#include "GameObject.hpp"
#include "GameObjectsCodes.h"
#include "SaveConfig.h"
#include <fstream>
#include <sstream>
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

void ld::SaveModule::LoadSave(PlayState& playState)
{
	ifstream saveFile(SAVE_FILE_NAME);
	string line;
	if(!(bool)saveFile)
	{
		saveFile.close();
		return;
	}
	std::getline(saveFile, line);
	istringstream basic(line);
	float hp;
	int coins;
	bool djump;
	basic >> hp >> coins >> djump;
	_data->playerInfo.ChangeHealth(hp - _data->playerInfo.HealthMax);
	_data->playerInfo.GiveCoins(coins);
	if(djump) _data->playerInfo.UnlockDoubleJump();
	else playState.InitDoubleJump();
	while(std::getline(saveFile, line))
	{
		istringstream iss(line);
		string type;
		iss >> type;
		if(type == SKELETON_CODE)
		{
			float x,y,left,right;
			iss >> x >> y >> left >> right;
			CreateSkeleton(x,y,left, right, playState);
		}
		else
		{
			float x,y;
			iss >> x >> y;
			_objectCreators[type](x,y,playState);
		}
	}
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
	playState.LoadPlayer(x,y);
}

void ld::SaveModule::CreateSkeleton(float x, float y, float left, float right, PlayState& playState)
{
	playState.LoadSkeleton(x,y,left,right);
}

void ld::SaveModule::CreateGold(float x, float y, PlayState& playState)
{
	playState.LoadGold(x,y);
}

void ld::SaveModule::CreatePotion(float x, float y, PlayState& playState)
{
	playState.LoadHP(x,y);
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
