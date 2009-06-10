#ifndef __GRAPHICSMANAGER_H__
#define __GRAPHICSMANAGER_H__

#include "defs.h"

void Graphics_Init( unsigned width, unsigned height );
void Graphics_Resize( unsigned width, unsigned height );

void Graphics_BeginFrame( void );
void Graphics_EndFrame( void );

// Draws object to rendering surface
// TODO: take a mesh object as a parameter to draw
void Grahpics_Draw( void );
void Graphics_DrawBlock( vec2_t pos );
void Graphics_MoveCamera( void );

void Graphics_Exit( void );



#endif // __GRAPHICSMANAGER_H__
