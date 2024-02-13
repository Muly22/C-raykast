#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdbool.h>

#include "player.h"
#include "object.h"

typedef struct {
  DOOR *doors;
  int door_c;
} OBJECT;

typedef struct {
  SEGMENT *segments;
  int segment_c;
  PLAYER *players;
  int player_c;
  OBJECT objects;
} WORLD;

#endif
