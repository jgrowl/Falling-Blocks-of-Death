#include "windowmanager.h"
#include "SDL.h"

static SDL_Surface* sdl_surface = 0;
static unsigned win_width = 1;
static unsigned win_height = 1;

void WinMgr_Init( unsigned width, unsigned height )
{
    // TODO: Most of this code was copied from a tutorial somewhere. Adapt it to our engine.
    
    // min size is (1,1)
    if( width == 0 )
        width = 1;
    if( height == 0 )
        height = 1;
        
    unsigned sdl_flags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE;
    
    // this holds some info about our display
    const SDL_VideoInfo *videoInfo;

    // initialize SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
	}

    // Fetch the video info
    videoInfo = SDL_GetVideoInfo( );

    if ( !videoInfo )
	{
	}

    // This checks to see if surfaces can be stored in memory
    if ( videoInfo->hw_available )
        sdl_flags |= SDL_HWSURFACE;
    else
        sdl_flags |= SDL_SWSURFACE;

    // This checks if hardware blits can be done
    if ( videoInfo->blit_hw )
        sdl_flags |= SDL_HWACCEL;

    // Sets up OpenGL double buffering
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    // get a SDL surface
    sdl_surface = SDL_SetVideoMode( width, height, 32, sdl_flags );
    win_width = width;
    win_height = height;

    // Verify there is a surface
    if ( !sdl_surface )
	{
	}

    WinMgr_Resize( width, height );
}

void WinMgr_Resize( unsigned width, unsigned height )
{
    if( width == 0 )
        width = 1;
    if( height == 0 )
        height = 1;
        
    win_width = width;
    win_height = height;
}

void WinMgr_GetSize( unsigned* width, unsigned* height )
{
    *width = win_width;
    *height = win_height;
}

enum WinMgr_Signal WinMgr_Update( void )
{
    static SDL_Event event;
    while( SDL_PollEvent( &event ) )
    {
        switch( event.type )
        {
        case SDL_QUIT:
            return WM_CLOSE;
            
        case SDL_VIDEORESIZE:
            return WM_RESIZE;
            
        default:
            break;
        }
    }

    return WM_NONE;
}

void WinMgr_Swap( void )
{
    SDL_GL_SwapBuffers();
}

void WinMgr_Exit( void )
{
}
