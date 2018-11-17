#pragma once
#include "gamestate.h"


class menustate : public gamestate
{
	//bool knighttrue;
	bool readyForNext;
	//Rectangle knightrec{100,270,150,150};
	//Rectangle soldierrec{ 300,270,150,150 };
	//Texture2D character1 = LoadTexture("knightIdle/knight_0.png");
	//Texture2D character2 = LoadTexture("soldierIdle/soldier_0.png");
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
		DrawText("START.", 200, 200, 35, BLACK);
		/*DrawRectangle(knightrec.x, knightrec.y, knightrec.width, knightrec.height, SKYBLUE);
		DrawRectangle(soldierrec.x, soldierrec.y, soldierrec.width, soldierrec.height, LIME);
		DrawText("PICK YOUR CHARACTER", 100, 100, 32, BLACK);
		DrawTextureEx(character1, { 100,200 }, 0, 8, WHITE);
		DrawTextureEx(character2, { 300,200 }, 0, 8, WHITE);*/
	/*	if (CheckCollisionPointRec(GetMousePosition(), knightrec)) {
			knighttrue = true;
		}
		CheckCollisionPointRec(GetMousePosition(), soldierrec);*/
	}

	virtual GameStates next()
	{
		if (readyForNext) { return GameStates::GAME; }
		else { return GameStates::MENU; }
	}
};
