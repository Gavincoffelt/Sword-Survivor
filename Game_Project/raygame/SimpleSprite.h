#pragma once
#include <iostream>
#include "raylib.h"
#include <ctime>
class SimpleSprite
{
	
public:
	int arrnum = 0;
	Rectangle bob{pos.x,pos.y,18,5};
	Vector2 pos;
	int xrand = rand() % 600;
//	Rectangle r1, r2;//r1 = size of texture , r2 = calculated destination size

	Texture2D texture[8];

	void translate(Vector2 delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	SimpleSprite();
	~SimpleSprite();
};