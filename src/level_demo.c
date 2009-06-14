#include "level_demo.h"
#include "frameratecontroller.h"
#include "graphicsmanager.h"
#include "inputmanager.h"
#include <stdio.h>

static vec2_t block_pos = {0.0f, 0.0f};
// 10x10 grid; (0,0) to (9,9)
static const unsigned grid_width = 10;
static const unsigned grid_height = 10;

static float lasttime;

// move block around the perimeter of the screen in the a CCW fashion
static void advance_block( void )
{
    // should be either 1 or -1 depending on which direction it should move in the x and y coordinates
    // 0 means it's not moving in that axis
    static int x_dir = 1;
    static int y_dir = 0;
    
    block_pos[0] += x_dir;
    block_pos[1] += y_dir;
    
    if ( x_dir )
    {
        if ( block_pos[0] >= grid_width - 1 )
        {
            x_dir = 0; // stop moving in the x direction
            y_dir = 1; // move upwards
            block_pos[0] = grid_width - 1;
        }
        else if ( block_pos[0] <= 0 )
        {
            x_dir = 0;
            y_dir = -1;
            block_pos[0] = 0;
        }
    }
    else if ( y_dir )
    {
        if ( block_pos[1] >= grid_height - 1 )
        {
            y_dir = 0;
            x_dir = -1;
            block_pos[1] = grid_height - 1;
        }
        else if ( block_pos[1] <= 0 )
        {
            y_dir = 0;
            x_dir = 1;
            block_pos[1] = 0;
        }
    }
}

static void Load( void )
{
    printf("Load::level_demo\n");
}

static void Init( void )
{
    lasttime = 0.0f;
    Vec2Set( block_pos, 0.0f, 0.0f );
    printf("Init::level_demo\n");
}

static void Update( void )
{
    // Note that even though GS_QUIT is being set here in Update(), the
	// following Draw() will still be executed.
    
    // draw every .25 seconds
    lasttime += frame_time;
    if ( lasttime > .25f )
    {
        lasttime -= .25f;
        advance_block();
    }
    
    
    printf("Update::level_demo\n");
    printf("\tframe_time = %.04f sec\n\tlevel_time = %.04f sec\n", frame_time,
		   level_time);
    
    
    
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
    Graphics_DrawBlock( block_pos );
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
