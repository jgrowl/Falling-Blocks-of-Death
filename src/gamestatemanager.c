#include "gamestatemanager.h"

// globals
const struct GameState* GS_current = 0;
const struct GameState* GS_previous = 0;
const struct GameState* GS_next = 0;

const struct GameState* GS_QUIT = (struct GameState*)0;
const struct GameState* GS_RESTART = (struct GameState*)1;

void GS_Initialize( const struct GameState* initial )
{
    GS_current = initial;
    GS_previous = initial;
    GS_next = initial;
}
