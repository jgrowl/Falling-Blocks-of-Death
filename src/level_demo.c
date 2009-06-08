#include "level_demo.h"
#include "frameratecontroller.h"
#include "graphicsmanager.h"
#include "inputmanager.h"
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
    
    printf("Update::level_demo\n");
    printf("\tframe_time = %.04f sec\n\tlevel_time = %.04f sec\n", frame_time, level_time);
    
    if( KeyTriggered( KEY_r ) )
        GS_next = GS_RESTART;
    
    // Quit if escape is pressed
    if( KeyTriggered( KEY_ESCAPE ) )
        GS_next = GS_QUIT;
}

static void Draw( void )
{
    printf("Draw::level_demo\n\n");
    
    Graphics_Draw();
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
const struct GameState GS_level_demo = {Load, Init, Update, Draw, Free, Unload};
