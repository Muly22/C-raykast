#ifndef _OBJECT_H_ 
#define _OBJECT_H_

#include "texture.h"

typedef struct {
  float x;
  float y;
} POINT;

typedef struct {
  float *heights;
  float *distances;
  POINT *points;
} RAY;

typedef struct {
  POINT A;
  POINT B;
  float height;
  TEXTURE *texture;
} SEGMENT;

typedef struct {
  SEGMENT *segment;
  bool open;
  bool unclose;
} DOOR;

#endif
