#ifndef __WINDOWMANAGER_H__
#define __WINDOWMANAGER_H__


enum WinMgr_Signal
{
    WM_NONE=0,
    WM_CLOSE,
    WM_RESIZE
};

// Initialize
void WinMgr_Init( unsigned width, unsigned height );

// Should be called whenever a resize occurs
void WinMgr_Resize( unsigned width, unsigned height );

// Returns the size of the window
void WinMgr_GetSize( unsigned* width, unsigned* height );

// Handles window events and returns a signal
enum WinMgr_Signal WinMgr_Update( void );

// Swap OpenGL buffers
void WinMgr_Swap( void );

// Clean up
void WinMgr_Exit( void );




#endif // __WINDOWMANAGER_H__
