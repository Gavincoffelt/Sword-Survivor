#include "SimpleSprite.h"
void SimpleSprite::translate(Vector2 delta)
{
	pos.x += delta.x;
	pos.y += delta.y;
	if (pos.y >= 800) {
		pos.y = -25;
		pos.x = 10 + rand() % 580;
	}
}

void SimpleSprite::draw()
{
	DrawTextureEx(texture, pos, 180, 3, WHITE);
}

SimpleSprite::SimpleSprite()
{

}

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType)
{
	texture =  LoadTexture(filename.c_str());
	pos.x = xrand;
	pos.y = 0;
}

SimpleSprite::~SimpleSprite()
{

}
