#ifndef _MYWINDOW_H_
#define _MYWINDOW_H_

#include <SDL2/SDL.h>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

int window_create( SDL_Window *window );
int surface_create( SDL_Surface *surface, SDL_Window *window ); 

#endif
