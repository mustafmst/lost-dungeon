#pragma once
#include <map>
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include "GameObject.hpp"

namespace ld
{
using namespace std;
class SaveModule
{
	bool saveExists = false;
	map<string, function<GameObject(float,float)>> _objectCreators;
	
	GameObject CreatePlayer(float x, float y);
	GameObject CreateSkeleton(float x, float y);
	GameObject CreateGold(float x, float y);
	GameObject CreatePotion(float x, float y);
public:
	SaveModule();
	~SaveModule();
	
	void LoadSave();
	void SaveGame();
	bool SaveExists();
};

}

