#include "FallingFactory.h"
#include <time.h>
SimpleSprite* FallingFactory::spriteMasters = nullptr;
size_t FallingFactory::spriteCount = 0;

void FallingFactory::init()
{
	
	spriteCount = 8;
	spriteMasters =  new SimpleSprite[spriteCount];
	spriteMasters[0] = *(new SimpleSprite("Weapons/weapon_0.png", "Weapon"));
	spriteMasters[1] = *(new SimpleSprite("Weapons/weapon_1.png", "Weapon"));
	spriteMasters[2] = *(new SimpleSprite("Weapons/weapon_2.png", "Weapon"));
	spriteMasters[3] = *(new SimpleSprite("Weapons/weapon_3.png", "Weapon"));
	spriteMasters[4] = *(new SimpleSprite("Weapons/weapon_4.png", "Weapon"));
	spriteMasters[5] = *(new SimpleSprite("Weapons/weapon_5.png", "Weapon"));
	spriteMasters[6] = *(new SimpleSprite("Weapons/weapon_6.png", "Weapon"));
	spriteMasters[7] = *(new SimpleSprite("Weapons/weapon_7.png", "Weapon"));


}

SimpleSprite * FallingFactory::getRandom()
{
	int arrnum = rand() % 8;
	spriteMasters[1].draw();
	
	return nullptr;
}

SimpleSprite * FallingFactory::getFromType(const std::string & _sprType)
{
	return nullptr;
}

FallingFactory::FallingFactory()
{
}

FallingFactory::~FallingFactory()
{
	delete[] spriteMasters;
}
