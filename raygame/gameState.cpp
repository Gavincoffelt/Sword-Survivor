#include "gamestate.h"
#include "menustate.h"
#include "basegamestate.h"
#include "endstate.h"

#include <cassert>

void setupGameState(gamestate *&ptr, GameStates newState)
{
	switch (newState)
	{
	case GameStates::NONE:  ptr = new gamestate();  break;
	case GameStates::MENU:  ptr = new menustate();  break;
	case GameStates::GAME: ptr = new basegamestate(); break;
	case GameStates::END:   ptr = new endstate();   break;
	default: assert(false && "Invalid state specified.");
	}
}