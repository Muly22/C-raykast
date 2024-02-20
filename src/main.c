#include "player.h"
#include "raycast_core.h"
#include "rwindow.h"
#include "rerror.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define CHECK if ( check_error(exit_status) ) {goto dest;}

STATUS main_loop(void);
STATUS main_destroy(void);

int main() {
  exit_status = init_rays( SCREEN_WIDTH );
  CHECK 
  exit_status = init_mindist( SCREEN_WIDTH );
  CHECK 
  exit_status = create_window();
  CHECK
  world.segments = malloc(sizeof(SEGMENT));
  world.segments[0].A.x = 1;
  world.segments[0].A.y = 1;
  world.segments[0].B.x = 5;
  world.segments[0].B.y = 5;
  world.segments[0].texture = NULL;
  exit_status = main_loop();
  CHECK 
  dest:
  main_destroy();
  return 0;
}

STATUS main_loop() {
  for (;;) {
    if ( next_event() ) {break;}
    if ( check_error(window_clear()) ) {
      strcpy(exit_message, "error_window_clear");
      goto error_main_loop;
    }
    renddis( player.angle, player.FOV, SCREEN_WIDTH );
    min_distance(SCREEN_WIDTH);
    for (int i = 0; i < SCREEN_WIDTH; i++) {
      if ( isnan(intersection[i].distance) )
        continue;
      if ( intersection[i].distance < 1 )
        intersection[i].distance = 1;
      draw_ray_line( SCREEN_HEIGHT/intersection[i].distance, i, intersection[i].texture  ); 
    }
  }
  return SUCCESS;
  error_main_loop:
  return ERROR_MAIN_LOOP;
}
STATUS main_destroy() { close_window(); return SUCCESS; }
