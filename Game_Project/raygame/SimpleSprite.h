#pragma once
#include <iostream>
#include "raylib.h"
#include "Character.h"
class SimpleSprite
{
	
public:
	int xrand = rand() % 600;
	int random = 1;
	float speed;
	int rot = 180;
	int score = 0;
	Rectangle bob{pos.x,pos.y,18,5};
	Vector2 pos;
	Texture2D texture[8];
	void translate(Vector2 delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	void variables(SimpleSprite& sword,Character target);
	void movement(float delta);
	SimpleSprite();
	~SimpleSprite();
};