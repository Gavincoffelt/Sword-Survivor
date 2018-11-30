#pragma once
#include "gamestate.h"


class menustate : public gamestate
{
	//bool knighttrue;
	bool readyForNext;

public:
	menustate()
	{
		readyForNext = false;
	}

	virtual void tick(float deltaTime)
	{
		readyForNext = IsMouseButtonPressed(0) || readyForNext;
	}

	virtual void draw()
	{
		ClearBackground(DARKBLUE);
		DrawText("START.", 200, 200, 55, BLACK);
		DrawText("LMB to begin!", 100, 500, 62, BLACK);
	
	}

	virtual GameStates next()
	{
		if (readyForNext) { return GameStates::GAME; }
		else { return GameStates::MENU; }
	}
};
