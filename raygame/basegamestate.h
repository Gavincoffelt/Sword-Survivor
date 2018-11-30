#pragma once
#include "gamestate.h"
#include"Character.h"
#include "SimpleSprite.h"
#include <string>
#include <fstream>
#include <string.h>
#include <filesystem>
using namespace std;
class basegamestate : public gamestate
{
	bool dead = false;

public:
	Texture2D backround = LoadTexture("Weapons/Backround.png");
	int maxSwords = 3;
	int score = 0;
	float timer = 0;
	Rectangle bob;
	Character Player;
	SimpleSprite swords[25];
	basegamestate()
	{
		
	}
	/*virtual void game() {
		Texture2D backround = LoadTexture("Weapons/Backround.png");
		int maxSwords = 3;
		int score = 0;
		float timer = 0;
		Rectangle bob();
		Character Player;
		SimpleSprite swords[25];
		BeginDrawing();

		ClearBackground(RAYWHITE);
		DrawTextureEx(backround, { 0,0 }, 0, 1, WHITE);
		while (dead != true)
	{
		Player.movement(GetFrameTime());
		Player.draw();
		Player.update(GetFrameTime());

		timer += GetFrameTime();
		if (timer >= 5) {
			maxSwords = 6;
		}

		if (timer >= 10)
		{
			maxSwords = 20;
		}
		DrawText("Time:", 15, 500, 20, WHITE);
		DrawText(std::to_string(timer).c_str(), 100, 500, 20, WHITE);
		DrawText("Swords Dodged:", 15, 550, 20, WHITE);
		DrawText(std::to_string(score).c_str(), 250, 550, 20, WHITE);
		for (int i = 0; i <= maxSwords; i++) {

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

				DrawText("YOU LOSE", 200, 200, 35, RED);
				dead = true;
			}
		}

		}
	}*/
	virtual void draw() {
		if (!dead)
		{
			DrawTextureEx(backround, { 0,0 }, 0, 1, WHITE);
			Player.movement(GetFrameTime());
			Player.draw();
			Player.update(GetFrameTime());
			if (Player.pos.x > GetScreenWidth()-50) { Player.pos.x = 550; }
			if (Player.pos.x < 0) { Player.pos.x = 0; }
			timer += GetFrameTime();
			if (timer >= 5) {
				maxSwords = 6;
			}

			if (timer >= 10)
			{
				maxSwords = 20;
			}
			DrawText("Time:", 15, 500, 20, WHITE);
			DrawText(std::to_string(timer).c_str(), 100, 500, 20, WHITE);
			DrawText("Swords Dodged:", 15, 550, 20, WHITE);
			DrawText(std::to_string(score).c_str(), 250, 550, 20, WHITE);
			for (int i = 0; i <= maxSwords; i++) {

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
					highscore final;
					final.finalscore = score;
					final.finaltimer = timer;

				}
			}
			
		}
	};
		virtual GameStates next()
		{
			if (dead == true) { return GameStates::END; }
			else { return GameStates::GAME; }
		}
	
};