#include "player.h"
#include "raycast_core.h"
#include "rwindow.h"
#include "rerror.h"
#include <stdio.h>

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
  }
  return SUCCESS;
  error_main_loop:
  return ERROR_MAIN_LOOP;
}
STATUS main_destroy() { close_window(); return SUCCESS; }
