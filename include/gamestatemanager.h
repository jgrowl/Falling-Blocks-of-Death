#ifndef __GAMESTATEMANAGER_H__
#define __GAMESTATEMANAGER_H__


// GameState is a collection of function pointers, which are described in more detail below.
// Each level in the game will be accessed through a GameState, allowing each level to
// define it's own functions for loading models, applying physics, handling input, etc..
struct GameState
{
    void (*Load)(void);     // Load models, sounds, etc.
    void (*Init)(void);     // Create objects, set to initial positions (restart level)
    void (*Update)(void);   // Update positions, handle input, do physics
    void (*Draw)(void);     // Render the scene
    void (*Free)(void);     // Destroy game objects
    void (*Unload)(void);   // Unload models, sounds, etc.
};

// These three GameState pointers will be used heavily in the GameLoop function. It allows for
// a generic game loop algorithm for each level and easy switching between levels.
extern const struct GameState* GS_current;
extern const struct GameState* GS_previous;
extern const struct GameState* GS_next;

extern const struct GameState* GS_QUIT;
extern const struct GameState* GS_RESTART;

// Be sure to initialize the game state manager before using the above 3 GameState pointers.
void GS_Initialize( const struct GameState* );


#endif // __GAMESTATEMANAGER_H__
