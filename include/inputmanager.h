#ifndef __INPUTMANAGER_H__
#define __INPUTMANAGER_H__

#include "keycodes.h"


void Input_Init( void );
void Input_Update( void );
void Input_Exit( void );

// keyboard
unsigned KeyPressed( unsigned keycode );
unsigned KeyTriggered( unsigned keycode );
unsigned KeyReleased( unsigned keycode );



#endif // __INPUTMANAGER_H__
