#include "SimpleSprite.h"
#include <string>
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
	
	DrawRectangle(bob.x - 20, bob.y - 8, bob.width, bob.height,BLANK);
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
		sword.speed = 265.0f;
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
		pos.y = -25;
		pos.x = 10 + rand() % 580;
	}
	bob.x = pos.x;
	bob.y = pos.y;
}

SimpleSprite::SimpleSprite()
{
	for (int i = 0; i < 8; i++) {
		texture[i] = LoadTexture(("Weapons/weapon_" + std::to_string(i) + ".png").c_str());
	}
	pos.x = xrand;
	pos.y = 0;

}


SimpleSprite::~SimpleSprite()
{

}
