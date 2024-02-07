#include <stdio.h>
#include "SDL_mywindow.h"
#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Event event;

int main_loop(void);

int main() {
  int exit_status;
  if ( SDL_Init(SDL_INIT_EVERYTHING) ) {
    return 1;
  }
  exit_status = window_create( window );
  if (exit_status) { 
    printf("Error: window_create");
    return 1;
  }
  exit_status = surface_create( surface, window );
  if (exit_status) { 
    printf("Error: surfase_create");
    return 1;
  }
  exit_status = main_loop();
  if (exit_status) { 
    printf("Error: main_loop");
    return 1;
  }
  return 0;
}

int main_loop(){
  for (;;) {
    for (; SDL_PollEvent(&event) ;) {
      if ( event.type == SDL_QUIT )
        return 0;
    }
    //SDL_FillRect( surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255) );
    SDL_UpdateWindowSurface(window);
  }
}
