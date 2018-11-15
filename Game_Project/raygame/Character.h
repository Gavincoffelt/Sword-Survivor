#pragma once
#include <iostream>
#include"raylib.h"
class Character {
	std::string sprType;
	Vector2 pos;
	float rot;
	float speed;
	Texture2D texture;

	void movement(float delta);
	void draw(); //draw the sprite on screen
	Character();
	Character(const std::string & filename, const std::string _sprType = "");
	~Character();
};