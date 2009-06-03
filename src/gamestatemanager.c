#include "gamestatemanager.h"

// globals
const GameState* GS_current = 0;
const GameState* GS_previous = 0;
const GameState* GS_next = 0;

const GameState* GS_QUIT = (GameState*)0;
const GameState* GS_RESTART = (GameState*)1;

void GS_Initialize( const GameState* initial )
{
    GS_current = initial;
    GS_previous = initial;
    GS_next = initial;
}
