#include "SimpleSprite.h"
void SimpleSprite::translate(Vector2 delta)
{
	pos.x += delta.x;
	pos.y += delta.y;
	if (pos.y >= 800) {
		pos.y = -25;
		pos.x = 10 + rand() % 580;
		int arrnum = rand() % 7;
	}
	bob.x = pos.x;
	bob.y = pos.y;
}

void SimpleSprite::draw()
{
	
		DrawTextureEx(texture[1], pos, 180, 3, WHITE);
	
	DrawRectangle(bob.x - 25, bob.y - 8, bob.width, bob.height,YELLOW);
}

SimpleSprite::SimpleSprite()
{
	texture[0] = LoadTexture("Weapons/weapon_0.png");
	texture[1] = LoadTexture("Weapons/weapon_1.png");
	texture[2] = LoadTexture("Weapons/weapon_2.png");
	texture[3] = LoadTexture("Weapons/weapon_3.png");
	texture[4] = LoadTexture("Weapons/weapon_4.png");
	texture[5] = LoadTexture("Weapons/weapon_5.png");
	texture[6] = LoadTexture("Weapons/weapon_6.png");
	texture[7] = LoadTexture("Weapons/weapon_7.png");

	pos.x = xrand;
	pos.y = 0;

}


SimpleSprite::~SimpleSprite()
{

}
