#include "inputmanager.h"
#include "defs.h"
#include "SDL.h"
#include "SDL_keyboard.h"
#include "string.h"


static u8 keys_current[SDLK_LAST] = {0};
static u8 keys_previous[SDLK_LAST] = {0};
static u8* key_state = 0;

void Input_Init( void )
{
    key_state = SDL_GetKeyState(NULL);
}

void Input_Update( void )
{
    memcpy( keys_previous, keys_current, sizeof(keys_previous) );
    memcpy( keys_current, key_state, sizeof(keys_current) );
}

void Input_Exit( void )
{
    // nothing to do here
}


unsigned KeyPressed( unsigned keycode )
{
    return keys_current[ (keycode & 0xff) ];
}

unsigned KeyTriggered( unsigned keycode )
{
    return keys_current[ (keycode & 0xff) ] && !keys_previous[ (keycode & 0xff) ];
}

unsigned KeyReleased( unsigned keycode )
{
    return !keys_current[ (keycode & 0xff) ] && keys_previous[ (keycode & 0xff) ];
}
