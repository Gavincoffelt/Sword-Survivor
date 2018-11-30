#include "raylib.h"
#include "SimpleSprite.h"
#include "Character.h"
#include "menustate.h"
#include <iostream>
#include "basegamestate.h"
using namespace std;
int main()
{
	int screenheight = 600;
	int screenwidth = 600;
	
	InitWindow(screenwidth, screenheight, "Sword Survivor");
	//Texture2D backround = LoadTexture("Weapons/Backround.png");
	//int maxSwords = 3;
	//int score = 0;
	//float timer = 0;
	//Rectangle bob();
	//Character Player;
	//SimpleSprite swords[25];

	
	SetTargetFPS(60);	
	gamestate * stateInstance = new menustate();
	GameStates currentState = MENU;
    
	while (!WindowShouldClose())   
	{
		stateInstance->tick(GetFrameTime());
		GameStates nextState = stateInstance->next();
		if (nextState != currentState)
		{
			delete stateInstance;

			setupGameState(stateInstance, nextState);
			currentState = nextState;
			continue;
		}
		BeginDrawing();
		ClearBackground(WHITE);
		stateInstance->draw();
		EndDrawing();
		/*Player.update(GetFrameTime());

		timer += GetFrameTime();*/
		
	//	// Update

	//	// Draw
	//	BeginDrawing();
	////	
	//	ClearBackground(RAYWHITE);

	//	DrawTextureEx(backround, { 0,0 }, 0, 1, WHITE);
	//	Player.movement(GetFrameTime());
	//	Player.draw();
	//	
	//	if(timer >= 5)  {
	//		maxSwords = 6;
	//	} 

	//	if (timer >= 10)
	//	{
	//		maxSwords = 20;
	//	}
	//	DrawText("Time:", 15, 500, 20, WHITE);
	//	DrawText(std::to_string(timer).c_str(),100,500,20,WHITE);
	//	DrawText("Swords Dodged:", 15, 550, 20, WHITE);
	//	DrawText(std::to_string(score).c_str(), 250, 550, 20, WHITE);
	//		for (int i = 0; i <= maxSwords; i++) {

	//		swords[i].variables(swords[i], Player);
	//		swords[i].draw();
	//		swords[i].movement(GetFrameTime());

	//		if (swords[i].pos.y <= -25) {
	//			swords[i].random = rand() % 3;
	//			score++;
	//			if (timer >= 10) {
	//				swords[i].random = rand() % 5;

	//			}
	//			if (timer >=15) {
	//				swords[i].random = rand() % 8;
	//			}
	//		}
	//		if (CheckCollisionRecs(Player.steve, swords[i].bob)) {

	//			DrawText("YOU LOSE", 200, 200, 35, RED);
	//		}
	//	}
	//	EndDrawing();
	//	
	//	//----------------------------------------------------------------------------------
	}
	
	CloseWindow();  
	      // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	return 0;
}