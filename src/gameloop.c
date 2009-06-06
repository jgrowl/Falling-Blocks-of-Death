#include "gameloop.h"
#include "gamestatemanager.h"
#include "level_demo.h"

void GameLoop( void )
{
    GS_Initialize( &GS_level_demo );
    FrameRate_Init( 60 );    // Set max frame rate

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
            //pGraphics->BeginFrame();
            //Input::Update();
            GS_current->Update();
            GS_current->Draw();
			//pGraphics->EndFrame();

            FrameRate_Wait();
            //pWindow->Swap();
            //System::Update();
		}

        GS_current->Free();

		if(GS_next != GS_RESTART)
            GS_current->Unload();

		GS_previous = GS_current;
		GS_current = GS_next;
	}
	
	FrameRate_Exit();
}
