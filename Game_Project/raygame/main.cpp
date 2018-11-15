#include "raylib.h"
#include "FallingFactory.h"
#include "SimpleSprite.h"
#include <iostream>
#include <string>
int main()

{
	int screenheight = 800;
	int screenwidth = 600;
	InitWindow(screenwidth, screenheight, "Half Life 3");
	SetTargetFPS(60);
	FallingFactory::init();
	Vector2 delta; delta.x = 0; delta.y = 6;
	
				
    
	while (!WindowShouldClose())   
	{
		// Update
		FallingFactory::spriteMasters[1].translate(delta);

		// Draw
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		FallingFactory::getRandom();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	return 0;
}