/*
** simple_sdl_test.c
** 
** Made by (Jonathan Rowlands)
** Login   <jonathan@cacodemon>
** 
** This file checks to make sure SDL is properly set up on your machine
** 
** Modified from examle on page 14 of Focus on SDL
**
** Started on  Mon Jun  1 14:43:38 2009 Jonathan Rowlands
** Last update Mon Jun  1 14:51:18 2009 Jonathan Rowlands
*/

#include "SDL.h"
#include <stdio.h>
int main(int argc, char* argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Could not initialize SDL!\n");
    }
  else
    {
      fprintf(stdout, "SDL initialized properly!\n");
      SDL_Quit();
    }
  return(0);
}


