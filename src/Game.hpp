#pragma once
#include <memory>
#include <string>

namespace ld
{

class Game
{
private:
	int width, height;
	std::string title;
public:
	Game(int width, int height, std::string title);
};

}

