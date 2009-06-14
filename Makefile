# I fucked this up. Sorry. To build, do this from the project root dir:
# gcc -DSYSTEM=0 src/*.c -I./include -I/usr/include/SDL -o FBoD -lSDL -lGL -lGLU

# A bit different in OS X:
# gcc -DSYSTEM=1 src/*.c -I./include -o FBod -lSDLmain -lSDL -framework Cocoa -framework OpenGL
# Based on reading here:
#  - http://goanna.cs.rmit.edu.au/~gl/teaching/Interactive3D/2009/compiling.html
#  - http://www.libsdl.org/faq.php?action=listentries&category=7#62
#  - http://gpwiki.org/index.php/SDL:Tutorials:Setup

