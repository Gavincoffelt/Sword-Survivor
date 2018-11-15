#pragma once
#include "raylib.h"
#include "SimpleSprite.h"

class FallingFactory
{ public:
	static SimpleSprite* spriteMasters;
	static size_t spriteCount;
	static void init();

	static SimpleSprite * getRandom();// returns a random sprite from all sprites loaded
	static SimpleSprite * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.

	FallingFactory();
	~FallingFactory();
};