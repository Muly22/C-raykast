#include "SDL_mywindow.h"

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int window_create( SDL_Window *window ) {
  SCREEN_WIDTH = 640;
  SCREEN_HEIGHT = 480; 
  window = SDL_CreateWindow( "Hello, SDL 2!",
  SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED,
  SCREEN_WIDTH, SCREEN_HEIGHT,
  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
  if ( !window ) {
    return 1;
  }
  return 0;
}
int surface_create( SDL_Surface *surface, SDL_Window *window ) {
  surface = SDL_GetWindowSurface( window );
  return 0;
}
