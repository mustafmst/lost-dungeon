#pragma once
#include <map>
#include <vector>
#include <memory>
#include <string>
#include <functional>


namespace ld
{
using namespace std;

class GameObject;
class GameData;
typedef std::shared_ptr<GameData> GameDataRef;

class SaveModule
{
	bool _saveExists = false;
	map<string, function<shared_ptr<GameObject>(float,float)>> _objectCreators;
	GameDataRef _data;
	
	static shared_ptr<GameObject> CreatePlayer(float x, float y);
	static shared_ptr<GameObject> CreateSkeleton(float x, float y);
	static shared_ptr<GameObject> CreateGold(float x, float y);
	static shared_ptr<GameObject> CreatePotion(float x, float y);
public:
	SaveModule();
	~SaveModule();
	
	void SetData(GameDataRef data);
	void LoadSave();
	void SaveGame();
	void DeleteSave();
	bool SaveExists();
};

}

