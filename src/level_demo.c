#include "level_demo.h"
#include <stdio.h>


static void Load( void )
{
    printf("Load::level_demo\n");
}

static void Init( void )
{
    printf("Init::level_demo\n");
}

static void Update( void )
{
    // Note that even though GS_QUIT is being set here in Update(), the following Draw()
    // will still be executed.
    
    // do main loop (Update and Draw) 3 times, then quit
    static int times = 2;
    if( times <= 0 )
        GS_next = GS_QUIT;
    --times;
    
    printf("Update::level_demo\n");
}

static void Draw( void )
{
    printf("Draw::level_demo\n");
}

static void Free( void )
{
    printf("Free::level_demo\n");
}

static void Unload( void )
{
    printf("Unload::level_demo\n");
}

// global accessor
const GameState GS_level_demo = {Load, Init, Update, Draw, Free, Unload};
