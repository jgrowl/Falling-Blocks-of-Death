#ifndef __FRAMERATECONTROLLER_H__
#define __FRAMERATECONTROLLER_H__

// frame_time will be used extensively in the level's update function
extern float frame_time;    // time since last frame (seconds)
extern float level_time;    // time since level started (seconds)


void FrameRate_Init( unsigned target_frames_per_second );

// Call right before starting each level's game loop
void FrameRate_Reset( void );

// Call at the end of the game loop
void FrameRate_Wait( void );

// Clean up
void FrameRate_Exit( void );


#endif // __FRAMERATECONTROLLER_H__
