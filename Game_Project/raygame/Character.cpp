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
	DrawRectangle (steve.x, steve.y, steve.width, steve.height, BLACK);
}


Character::Character()
{
	texture[0] = LoadTexture("soldierIdle/soldier_0.png");
	texture[1] = LoadTexture("soldierIdle/soldier_1.png");
	texture[2] = LoadTexture("soldierIdle/soldier_2.png");
	texture[3] = LoadTexture("soldierIdle/soldier_3.png");
    runRight[0] = LoadTexture("soldierRun/soldier_0.png");
    runRight[1] = LoadTexture("soldierRun/soldier_1.png");
    runRight[2] = LoadTexture("soldierRun/soldier_2.png");
    runRight[3] = LoadTexture("soldierRun/soldier_3.png");
	pos.x = 200;
	pos.y = 600;
	speed = 300;
}


Character::~Character()
{
}
