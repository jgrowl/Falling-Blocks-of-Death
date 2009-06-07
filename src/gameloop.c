#include "gameloop.h"
#include "windowmanager.h"
#include "graphicsmanager.h"
#include "gamestatemanager.h"
#include "level_demo.h"

void GameLoop( void )
{
    GS_Initialize( &GS_level_demo );
    WinMgr_Init( 800, 800 );    // set window size
    Graphics_Init( 800, 800 );
    FrameRate_Init( 30 );    // Set max frame rate
    Input_Init();

	while( GS_current != GS_QUIT )
	{
		// reset the system modules
        //System::Reset();

		// If not restarting, load the gamestate
        if( GS_current != GS_RESTART )
		{
            //GameStateManager::Update();
            GS_current->Load();
		}
		else
			GS_next = GS_current = GS_previous;

		// Initialize the gamestate
        GS_current->Init();
        FrameRate_Reset(); // reset the clock

		while( GS_current == GS_next )
		{
            Graphics_BeginFrame();
            Input_Update();
            GS_current->Update();
            GS_current->Draw();
			Graphics_EndFrame();

            FrameRate_Wait();
            WinMgr_Swap();
            
            // handle signals from window
            switch( WinMgr_Update() )
            {
                case WM_NONE:
                    break;
                
                case WM_CLOSE:
                    GS_next = GS_QUIT;
                
                case WM_RESIZE:
                    // TODO: update graphics viewport
                    break;
                
                default:
                    // error
                    break;
            }
            
            //System::Update();
		}

        GS_current->Free();

		if(GS_next != GS_RESTART)
            GS_current->Unload();

		GS_previous = GS_current;
		GS_current = GS_next;
	}
	
	Input_Exit();
	FrameRate_Exit();
	Graphics_Exit();
	WinMgr_Exit();
}
