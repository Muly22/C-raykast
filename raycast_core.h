#ifndef _RAYCAST_CORE_H_
#define _RAYCAST_CORE_H_

#include <player.h>
#include <world.h>

extern RAY *rays;

extern static PLAYER player;
extern static WORLD world;

int init_rays   ( int NOR );
int destroy_rays( int NOR );

int renddis( float POV, int FOV, int NOR ); 
int ray( float ang, int ray_num );

#endif
