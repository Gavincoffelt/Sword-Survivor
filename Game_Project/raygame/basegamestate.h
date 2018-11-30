#pragma once
#include "gamestate.h"
#include"Character.h"
#include "SimpleSprite.h"
#include <string>
using namespace std;
class basegamestate : public gamestate
{
	bool dead = false;

public:
	Texture2D backround = LoadTexture("Weapons/Backround.png");
	Rectangle bob;
	Character Player;
	SimpleSprite swords[25];
	int maxSwords = 4;
	int score = 0;
	float timer = 0;
	basegamestate()
	{
		
	}
	virtual void draw() {
		if (!dead)
		{
			DrawTextureEx(backround, { 0,0 }, 0, 1, WHITE);
			Player.movement(GetFrameTime());
			Player.draw();
			Player.update(GetFrameTime());
			swordspawner();

			if (Player.pos.x > GetScreenWidth()-50) { Player.pos.x = 550; }
			if (Player.pos.x < 0) { Player.pos.x = 0; }
			timer += GetFrameTime();
			
			DrawText("Time:", 15, 500, 20, WHITE);
			DrawText(std::to_string(timer).c_str(), 100, 500, 20, WHITE);
			DrawText("Swords Dodged:", 15, 550, 20, WHITE);
			DrawText(std::to_string(score).c_str(), 250, 550, 20, WHITE);
		}
	};
		void swordspawner() {
		if (timer >= 5) {
			maxSwords = 6;
		}
		if (timer >= 10) {
			maxSwords = 12;
		}
		if (timer >= 20) {
			maxSwords = 18;
		}
		for (int i = 0; i < maxSwords; i++) {

			swords[i].variables(swords[i], Player);
			swords[i].draw();
			swords[i].movement(GetFrameTime());
			if (swords[i].pos.y <= -25) {
				swords[i].random = rand() % 3;
				score++;
				if (timer >= 10) {
					swords[i].random = rand() % 5;

				}
				if (timer >= 15) {
					swords[i].random = rand() % 8;
				}
			}
			if (CheckCollisionRecs(Player.steve, swords[i].bob)) {
				dead = true;


			}
		}

	}
		virtual GameStates next()
		{
			if (dead == true) { return GameStates::END; }
			else { return GameStates::GAME; }
		}
	
};