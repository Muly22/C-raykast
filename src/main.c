#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raycast_core.h"
#include "rwindow.h"
#include "player.h"

int main() {
  init_rays(window_width);
  init_mindist(window_width);
  create_window();
  world.segments = malloc(sizeof(SEGMENT));
  world.segment_c = 1;
  world.segments[0].A.x = 1;
  world.segments[0].A.y = 1;
  world.segments[0].B.x = 5;
  world.segments[0].B.y = 5;
  world.segments[0].texture = NULL;

  /*for (;;)*/ {
    renddis( player.angle, player.FOV, window_width );
    min_distance(window_width);
    for (int i = 0; i < window_width; i++) {
      if (intersection[i].distance < 0)
        continue;
      if (intersection[i].distance < 1)
        intersection[i].distance = 1;

      draw_ray_line(window_height / intersection[i].distance, i, intersection[i].texture); 
    }
  }
  close_window();
  return 0;
}

