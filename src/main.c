#include "player.h"
#include "raycast_core.h"
#include "rwindow.h"
#include "rerror.h"
#include <stdio.h>

int main_loop(void);
int main_destroy(void);

int main() {
  STATUS exit_status;
  exit_status = init_rays( SCREEN_WIDTH );
  if ( check_error(exit_status, NULL) )
    goto dest;
  exit_status = init_mindist( SCREEN_WIDTH );
  if ( check_error(exit_status, NULL) )
    goto dest;
  exit_status = main_loop();
  if ( check_error(exit_status, NULL) )
    goto dest;
  dest:
  main_destroy();
  return 0;
}

STATUS main_loop() {
  for (;;) {
    renddis(player.angle, player.FOV, SCREEN_WIDTH);
    min_distance(SCREEN_WIDTH);
  }
  return SUCCESS;
}
STATUS main_destroy() { return SUCCESS; }