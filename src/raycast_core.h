#ifndef _RAYCAST_CORE_H_
#define _RAYCAST_CORE_H_

#include "player.h"
#include "world.h"
#include "rerror.h"

extern RAY *rays;
extern float *mindist;

static PLAYER player;
static WORLD world;

STATUS init_rays   ( int NOR );
STATUS destroy_rays( int NOR );

STATUS init_mindist( int NOR );
STATUS destroy_mindist( void );

STATUS renddis( float POV, int FOV, int NOR ); 
STATUS ray( float ang, int ray_num );
STATUS min_distance( int NOR );

#endif
