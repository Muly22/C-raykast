#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "raycast_core.h"

RAY *rays;
INTERSECTION *intersection;

static PLAYER player;
static WORLD world;

void init_mindist( int NOR ) {
  intersection = calloc( NOR, sizeof(INTERSECTION) );
  if (!intersection) {
    fprintf(stderr, "intersection == NULL");
  }
  for (int i = 0; i < NOR; i++) {
    intersection[i].distance = NAN;
    intersection[i].point.x  = NAN;
    intersection[i].point.y  = NAN;
    intersection[i].texture  = NULL;
  }
}

void init_rays(int NOR) {
  rays = calloc( NOR, sizeof(RAY) );
  if (!rays) {
    fprintf(stderr, "rays == NULL");
  }
  for (int i = 0; i < NOR; i++) {
    rays[i].distances = calloc( world.segment_c, sizeof(float) );
    rays[i].points    = calloc( world.segment_c, sizeof(POINT) );
    rays[i].textures  = calloc( world.segment_c, sizeof(TEXTURE*) );
  }
}

void destroy_mindist() {
  free(intersection);
  intersection = NULL;
}

void destroy_rays( int NOR ) {
  for (int i = 0; i < NOR; i++) {
    free(rays[i].distances);
    free(rays[i].points);
    rays[i].distances = NULL;
    rays[i].points = NULL;
  }
  free(rays);
  rays = NULL;
}

void renddis( float POV, int FOV, int NOR ) {
  float fovwid = POV / NOR;
  float angle = POV + (FOV >> 1);
  for (int i = 0; i < NOR; i++) {
    ray(angle, rays + i);
    angle -= fovwid;
  }
}

void ray(float ang, RAY *r) {
  float n, l1, l2, x, y, d1, d2;

  const SEGMENT lineB = { { player.pos[0], player.pos[1] },
                        { (cos(ang) * 10 + player.pos[0]), (sin(ang) * 10 + player.pos[1]) },
                        NULL };
  for (int i = 0; i < world.segment_c; i++) {
    const SEGMENT lineA = world.segments[i];
    n = ( lineA.A.x - lineA.B.x ) * ( lineB.A.y - lineB.B.y )
            - ( lineA.A.y - lineA.B.y ) * ( lineB.A.x - lineB.B.x );
    if ( n == 0.0f )
      goto no_intersection;
    n = 1 / n;
    l1 = lineA.A.x * lineA.B.y - lineA.A.y * lineA.B.x;
    l2 = lineB.A.x * lineB.B.y - lineB.A.y * lineB.B.x;
    x = ( l1 * ( lineB.A.x - lineB.B.x ) - ( lineA.A.x - lineA.B.x ) * l2 ) * n;
    y = ( l1 * ( lineB.A.y - lineB.B.y ) - ( lineA.A.y - lineA.B.y ) * l2 ) * n;
    r->points[i].x = x;
    r->points[i].y = y;
    if ( !((((x >= lineA.A.x) && (x <= lineA.B.x)) || ((x <= lineA.A.x) && (x >= lineA.B.x)))
        && (((y >= lineA.A.y) && (y <= lineA.B.y)) || ((y <= lineA.A.y) && (y >= lineA.B.y)))) ) {
      goto no_intersection;
    }
    d1 = x - player.pos[0];
    d2 = y - player.pos[1];
    r->distances[i] = sqrt( d1 * d1 + d2 * d2 );
    r->textures[i] = lineA.texture;
    continue;
    
    no_intersection:
    r->distances[i] = NAN;
    r->points[i].x  = NAN;
    r->points[i].y  = NAN;
    r->textures[i]  = NULL;
  }
}

void min_distance( int NOR ) {
  for (int i = 0; i < NOR; i++) {
    intersection[i].distance = rays[i].distances[0];
    for (int j = 1; j < world.segment_c; j++) {
      if ( !(isnan(rays[i].distances[j]) && isnan(rays[i].distances[j - 1]))
           && (rays[i].distances[j] < rays[i].distances[j - 1]) ) {
        intersection[i].distance = rays[i].distances[j];
        intersection[i].point.x  = rays[i].points[j].x;
        intersection[i].point.y  = rays[i].points[j].y;
        intersection[i].texture  = rays[i].textures[j];
      }
    }
  }
}
