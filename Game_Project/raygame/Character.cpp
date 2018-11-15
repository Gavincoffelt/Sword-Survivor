#include "Character.h"

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
	DrawTextureEx(texture, pos, 0, 3, WHITE);
}

Character::Character()
{
}

Character::Character(const std::string & filename, const std::string _sprType)
{
	texture = LoadTexture(filename.c_str());
	
}

Character::~Character()
{
}
