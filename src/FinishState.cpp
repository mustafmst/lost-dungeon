#include "FinishState.hpp"
#include "assetsAndDefinitions.h"


void ld::FinishState::Init()
{
	_data->assets.LoadTexture(FINISH_BACKGROUND_NAME, FINISH_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.GetTexture(FINISH_BACKGROUND_NAME));
	_elapsedTime = 0.f;
}
