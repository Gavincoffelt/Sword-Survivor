#include "raylib.h"
#include "SimpleSprite.h"
#include "Character.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	Rectangle bob();
	int screenheight = 800;
	int screenwidth = 600;
	InitWindow(screenwidth, screenheight, "Half Life 3");
	Character Player;
	SimpleSprite swords[8];
	
	SetTargetFPS(60);
	//FallingFactory::init();
	Vector2 delta; delta.x = 0; delta.y = 6;
	
				
    
	while (!WindowShouldClose())   
	{
		Player.update(GetFrameTime());

		// Update

		// Draw
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		
		Player.movement(GetFrameTime());
		Player.draw();
		for (int i = 0; i < 8; i++) {
			swords[i].translate(delta);
			swords[i].draw();
		}
		
		if (CheckCollisionRecs(Player.steve,swords[1].bob)) {

			DrawText("YOU LOSE", 200, 200, 35, RED);
		}
								
		
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	return 0;
}