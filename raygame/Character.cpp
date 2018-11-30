#include "Character.h"

void Character::update(float delta)
{
	iterator += delta;
	if (iterator >= max) {
		cellcount++;
		iterator = 0;
	} if (cellcount == 4) {
		cellcount = 0;
	}
	steve.x = pos.x+10;
	steve.y = pos.y+45;
}

void Character::movement(float delta)
{
	if (IsKeyDown(KEY_LEFT)) {
		pos.x -= speed * delta;

	}
	if (IsKeyDown(KEY_RIGHT)) {
		pos.x += speed * delta;

	}
}

void Character::draw()
{
	
	if (IsKeyDown(KEY_RIGHT)|| IsKeyDown(KEY_LEFT)) {
		DrawTextureEx(runRight[cellcount], pos, 0, 3, WHITE);
	}
	else {
		DrawTextureEx(texture[cellcount], pos, 0, 3, WHITE);
	}
	DrawRectangle (steve.x, steve.y, steve.width, steve.height, BLANK);
}


Character::Character()
{
	
	pos.x = 200;
	pos.y = 400;
	speed = 300;
}


Character::~Character()
{
}
