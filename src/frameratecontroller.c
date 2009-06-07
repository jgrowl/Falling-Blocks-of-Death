#include "frameratecontroller.h"
#include "SDL.h"

// For debugging
#include "stdio.h"

float frame_time = 0.0f;
float level_time = 0.0f;

static unsigned t0;
static unsigned t1;
static unsigned level_t0;
static unsigned min_frame_time = 0;

// Get time since application started in milliseconds
static inline unsigned now( void )
{
    return SDL_GetTicks();
}

static inline float delta( unsigned t0, unsigned t1 )
{
    return (float)(t1-t0)/1000.f;
}

void FrameRate_Init( unsigned target )
{
    SDL_InitSubSystem( SDL_INIT_TIMER );
    
    if( target == 0 )
        target = 1000;
        
    min_frame_time = 1000/target;
    printf("min_frame_time = %u ms\n", min_frame_time);
    
    FrameRate_Reset();
}

// Call right before starting each level's game loop
void FrameRate_Reset( void )
{
    t0 = t1 = level_t0 = now();
}

// Call at the end of the game loop
void FrameRate_Wait( void )
{
    t1 = now();
    
    while( (t1-t0) <= min_frame_time )
        t1 = now();
        
    frame_time = delta( t0, t1 );
    level_time = delta( level_t0, t1 );
    
    t0 = t1;
}

// Clean up
void FrameRate_Exit( void )
{
    // nothing to clean up
}
