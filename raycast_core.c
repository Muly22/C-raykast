#include <math.h>
#include "raycast_core.h"

static PLAYER player;
static WORLD world;

RAY *rays;
float *mindist;

int init_mindist( int NOR ) {
  mindist = calloc( NOR, sizeof(float) );
  if ( mindist == NULL ) {
    return 1;
  }
  return 0
}

int init_rays( int NOR ) {
  rays = calloc( NOR, sizeof(RAY) );
  if ( rays == NULL ) {
    return 1;
  }
  for (int i = 0; i < NOR; i++) {
    rays[i].distances = calloc( world.segment_c, sizeof(float) );
    rays[i].points    = calloc( world.segment_c, sizeof(POINT) );
  }
  return 0;
}

int destroy_mindist() {
  free(mindist);
  mindist = NULL;
  return 0;
}
int destroy_rays( int NOR ) {
  for (int i = 0; i < NOR; i++) {
    free(rays[i].distances);
    free(rays[i].points);
    rays[i].distances = NULL;
    rays[i].points - NULL;
  }
  free(rays);
  rays = NULL;
}

int renddis( float POV, int FOV, int NOR ) {
  static float fovwid = POV / NOR;
  float angle = POV + (FOV >> 1);
  for (int i = 0; i < NOR; i++) {
    if ( ray( angle, i ) ) {
      return 1;
    }
    angle -= fovwid;
  }
  return 0;
}

int ray( float ang, int ray_num ) {
  const SEGMENT lineB = { { player.pos[0], player.pos[1] },
                        { (cos(ang) * 10 + player.pos[0]), (sin(ang) * 10 + player.pos[1]) },
                        NULL };
  for (int i = 0; i < world.segment_c; i++) {
    const SEGMENT lineA = world.segments[i];
    float n = ( lineA.A.x - lineA.B.x ) * ( lineB.A.y - lineB.B.y )
            - ( lineA.A.y - lineA.B.y ) * ( lineB.A.x - lineB.B.x );
    if ( n == 0.0f ) {
      rays[ray_num].distances[i] = NUN;
      rays[ray_num].points[i] = {};
      continue;
    }
    n = 1 / n;
    float l1 = lineA.A.x * lineA.B.y - lineA.A.y * lineA.B.x;
    float l2 = lineB.A.x * lineB.B.y - lineB.A.y * lineB.B.x;
    float x = ( l1 * ( lineB.A.x - lineB.B.x ) - ( lineA.A.x - lineA.B.x ) * l2 ) * n;
    float y = ( l1 * ( lineB.A.y - lineB.B.y ) - ( lineA.A.y - lineA.B.y ) * l2 ) * n;
    rays[ray_num].points[i] = { x, y };
    if ( !((((x >= lineA.A.x) && (x <= lineA.B.x)) || ((x <= lineA.A.x) && (x >= lineA.B.x)))
        && (((y >= lineA.A.y) && (y <= lineA.B.y)) || ((y <= lineA.A.y) && (y >= lineA.B.y)))) ) {
      rays[ray_num].distances[i] = NUN;
      rays[ray_num].points[i] = {};
      continue;
    }
    float d1 = x - player.pos[0];
    float d2 = y - player.pos[1];
    rays[ray_num].distances[i] = sqrt( d1 * d1 + d2 * d2 );
  }
  return 0;
}

int min_distance( int NOR ) {
  for (int i = 0; i < NOR; i++) {
    mindist[i] = rays[i].distances[0];
    for (int j = 1; j < world.segment_c; j++) {
      if ( !isnan(rays[i].distance[j]) && !isnan(rays[i].distances[j - 1])
           && (rays[i].distance[j] < rays[i].distances[j - 1]) ) {
        mindist[i] = rays[i].distances[j];
      }
    }
  }
  return 0;
}
