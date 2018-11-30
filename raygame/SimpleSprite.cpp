#include "SimpleSprite.h"

void SimpleSprite::translate(Vector2 delta)
{
	//pos.x += delta.x;
	pos.y += delta.y;
	if (pos.y >= 600) {
		pos.y = -25;
		pos.x = 10 + rand() % 580;
	}
	bob.x = pos.x;
	bob.y = pos.y;
}

void SimpleSprite::draw()
{
	if (random < 0) {
		random = 1;
	}
	DrawTextureEx(texture[random], pos, rot, 3, WHITE);
	
	DrawRectangle(bob.x - 15, bob.y - 8, bob.width, bob.height,BLANK);
}

void SimpleSprite::variables(SimpleSprite& sword, Character target )
{
	if (sword.random != 6 || 7) {
		rot = 180;
	}
	if (sword.random == 0) {
		sword.speed = 500.0f;
		sword.bob.width = 10;
		sword.bob.x += 5;
		
	}if (sword.random == 1) {
		sword.speed = 250.0f;
	}if (sword.random == 2) {
		sword.speed = 250.0f;
	}if (sword.random == 3) {
		sword.speed = 200.0f;
		sword.bob.x += 10;
	}if (sword.random == 4) {
		sword.speed = 375.0f;
	}if (sword.random == 5) {
		sword.speed = 275.0f;
	}if (sword.random == 6) {
		sword.speed = 380.0f;
		if (target.pos.x > sword.pos.x) {
			sword.pos.x++;
			sword.rot = 145;
		}if (target.pos.x < sword.pos.x) {
			sword.pos.x--;
			sword.rot = 225;
		}
	}if (sword.random == 7) {
		sword.speed = 400.0f;
		if (target.pos.x > sword.pos.x) {
			sword.pos.x++;
			sword.rot = 145;
		}if (target.pos.x < sword.pos.x) {
			sword.pos.x--;
			sword.rot = 225;
		}
	}
}

void SimpleSprite::movement(float delta)
{
	pos.y += speed * delta;
	if (pos.y >= 800) {
		pos.y = -30;
		pos.x = 10 + rand() % 580;
	}
	bob.x = pos.x;
	bob.y = pos.y;
}

SimpleSprite::SimpleSprite()
{
	texture[0] = LoadTexture("Weapons/weapon_0.png"),
	texture[1] = LoadTexture("Weapons/weapon_1.png"),
	texture[2] = LoadTexture("Weapons/weapon_2.png"),
	texture[3] = LoadTexture("Weapons/weapon_3.png"),
	texture[4] = LoadTexture("Weapons/weapon_4.png"),
	texture[5] = LoadTexture("Weapons/weapon_5.png"),
	texture[6] = LoadTexture("Weapons/weapon_6.png"),
	texture[7] = LoadTexture("Weapons/weapon_7.png");
	pos.x = xrand;
	pos.y = 0;

}


SimpleSprite::~SimpleSprite()
{

}
