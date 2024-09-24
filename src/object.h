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
  TEXTURE **textures;
} RAY;

typedef struct {
  float distance;
  POINT point;
  TEXTURE *texture;
} INTERSECTION;

typedef struct {
  POINT A;
  POINT B;
  TEXTURE *texture;
} SEGMENT;

typedef struct {
  SEGMENT *segment;
  unsigned char open:1;
  unsigned char unclose:1;
} DOOR;

#endif
