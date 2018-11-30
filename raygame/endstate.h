#pragma once
#include "gamestate.h"
#include "basegamestate.h"
class endstate : public gamestate
{
	bool readyForNext;

public:
	
	endstate()
	{
		readyForNext = false;
	}

	virtual void tick(float deltaTime)
	{
		readyForNext = IsMouseButtonPressed(1) || readyForNext;
	}

	virtual void draw()
	{
		ClearBackground(DARKBLUE);
		const int fontSize = 62;
		int xPos = 250;
		int yPos = 50;
		DrawText("End", xPos, yPos, fontSize, BLACK);
		DrawText("RMB to Restart!", 50, 500, fontSize, BLACK);
		
	}

	virtual GameStates next()
	{
		if (!readyForNext) { return GameStates::END; }
		return GameStates::MENU;
	}
};