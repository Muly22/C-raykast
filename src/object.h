#ifndef _OBJECT_H_ 
#define _OBJECT_H_

#include "texture.h"

typedef struct {
  float x;
  float y;
} POINT;

typedef struct {
  float *distances;
  POINT *points;
} RAY;

typedef struct {
  POINT A;
  POINT B;
  TEXTURE *texture;
} SEGMENT;

typedef struct {
  SEGMENT *segment;
  bool open;
  bool unclose;
} DOOR;

#endif
