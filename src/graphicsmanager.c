#include "graphicsmanager.h"
#include "GL/gl.h"
#include "GL/glu.h"

void Graphics_Init( unsigned width, unsigned height )
{
    // Enable smooth shading
    glShadeModel( GL_SMOOTH );

    glEnable(GL_CULL_FACE);

    // Textures
    //glActiveTexture(GL_TEXTURE0);
    //glEnable(GL_TEXTURE_2D);
    //glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    // Background color
    glClearColor( 0.0f, 1.0f, 0.0f, 1.0f );

    // Depth buffer setup
    glClearDepth( 1.0f );

    // Enables Depth Testing
    glEnable( GL_DEPTH_TEST );

    // Lighting
    //vec3_t flashLightPos = {0,0,0};
    //vec4_t flashLightColor = {1.0, 0.0, 0.0, 1.0};
    //vec3_t flashLightDir = {0,0,-1};
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_POSITION, flashLightPos);
    //glLightfv(GL_LIGHT0, GL_AMBIENT, flashLightColor);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, flashLightColor);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, flashLightColor);
    //glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, flashLightDir);
    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 120.0);

    // Blending
    //glEnable( GL_BLEND );
    //glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // The Type Of Depth Test To Do
    glDepthFunc( GL_LEQUAL );

    // Really Nice Perspective Calculations
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
    
    Graphics_Resize( width, height );
}

void Graphics_Resize( unsigned width, unsigned height )
{
    // width and height must be positive
    if ( width == 0 )
        width = 1;
    if ( height == 0 )
        height = 1;

    // setup viewport
    glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

    // change to the projection matrix and set viewing volume
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    // set up a 2D projection
    // rendering dimmensions are (0,0) to (10, 10) with a z-value of -1.0 to 1.0
    gluOrtho2D( 0, 10, 0, 10 );

    // done with project settings
    glMatrixMode( GL_MODELVIEW );
}

void Graphics_BeginFrame( void )
{
    // Clear the screen
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void Graphics_EndFrame( void )
{
}

void Graphics_Draw( void )
{
    // NOTE: this is just a temporary draw function to confirm that rendering is working properly
    
    glLoadIdentity();
    glColor4f(1.0, 0.0, 1.0, 1.0 );
    glBegin( GL_TRIANGLES );      
        // REMINDER: draw vertices CCW
        
        // triangle
        glVertex3f(1.0, 1.0, 0.0);
        glVertex3f(9.0, 1.0, 0.0);
        glVertex3f(1.0, 9.0, 0.0);
        
        // unit square in upper right corner
        glVertex2i(10, 10);
        glVertex2i( 9, 10);
        glVertex2i(10,  9);
        glVertex2i( 9, 10);
        glVertex2i( 9,  9);
        glVertex2i(10,  9);
    glEnd();
}

void Graphics_Exit( void )
{
}

