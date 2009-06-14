#include <stdio.h>
#include "gameloop.h"
#include "gamestatemanager.h"
#include "level_demo.h"
#include "defs.h"

int main(int argc, char** argv)
{
#if SYSTEM == 1
	SDL_Init();
#endif
    //printf("\nFuck you, world!\n\n");
	printf("\nSwearing is dirty.\n\n");
    
    GameLoop();
    
    return 0;
}
