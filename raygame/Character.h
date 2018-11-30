#pragma once
#include <iostream>
#include "menustate.h"
#include"raylib.h"
class Character {
public:
	Vector2 pos;
	Rectangle steve{pos.x+10,pos.y+30,20,5};

	float max = 0.2f;
	float iterator = 0;
	float speed;
	
	Texture2D texture[4]{
	texture[0] = LoadTexture("soldierIdle/soldier_0.png"),
	texture[1] = LoadTexture("soldierIdle/soldier_1.png"),
	texture[2] = LoadTexture("soldierIdle/soldier_2.png"),
	texture[3] = LoadTexture("soldierIdle/soldier_3.png")};
	Texture2D runRight[4]{
	runRight[0] = LoadTexture("soldierRun/soldier_0.png"),
	runRight[1] = LoadTexture("soldierRun/soldier_1.png"),
	runRight[2] = LoadTexture("soldierRun/soldier_2.png"),
	runRight[3] = LoadTexture("soldierRun/soldier_3.png") };
	int cellcount = 0;
	void update(float delta);
	void movement(float delta);
	void draw(); //draw the sprite on screen
	Character();
	~Character();
	
};
struct highscore {
	public:
		float finaltimer;
		int finalscore;

};