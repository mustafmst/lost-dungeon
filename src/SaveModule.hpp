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
class PlayState;
typedef std::shared_ptr<GameData> GameDataRef;

class SaveModule
{
	bool _saveExists = false;
	map<string, function<void(float,float, PlayState&)>> _objectCreators;
	GameDataRef _data;
	
	static void CreatePlayer(float x, float y, PlayState& playState);
	static void CreateSkeleton(float x, float y, float left, float right, PlayState& playState);
	static void CreateGold(float x, float y, PlayState& playState);
	static void CreatePotion(float x, float y, PlayState& playState);
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

