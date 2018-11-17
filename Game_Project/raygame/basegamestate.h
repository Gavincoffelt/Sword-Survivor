#pragma once
#include "gamestate.h"
#include <string>

class basegamestate : public gamestate
{
	float duration;
	float timeLimit;

	bool clicked;

public:

	basegamestate()
	{
	
	}

	virtual GameStates next()
	{
		if (duration >= timeLimit) { return GameStates::END; }
		else { return GameStates::GAME; }
	}
};