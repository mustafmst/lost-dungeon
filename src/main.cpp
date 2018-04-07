#include "assetsAndDefinitions.h"
#include "Game.hpp"

int main(int argc, char **argv)
{
	ld::Game game(SCREEN_WIDTH, SCREEN_HEIGTH, GAME_TITLE);
	game.Run();
}
