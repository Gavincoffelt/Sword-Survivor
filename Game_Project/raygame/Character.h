#pragma once
#include <iostream>
#include"raylib.h"
class Character {
public:
	Vector2 pos;
	Rectangle steve{pos.x+10,pos.y+30,30,5};

	float max = 0.2f;
	float iterator = 0;
	float speed;
	Texture2D texture[4];
	Texture2D runRight[4];
	int cellcount = 0;
	void update(float delta);
	void movement(float delta);
	void draw(); //draw the sprite on screen
	Character();
	~Character();
};