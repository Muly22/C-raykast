#ifndef _RAYCAST_CORE_H_
#define _RAYCAST_CORE_H_

#include <player.h>
#include <world.h>

extern RAY *rays;
extern float *mindist;

extern static PLAYER player;
extern static WORLD world;

int init_rays   ( int NOR );
int destroy_rays( int NOR );

int init_mindist( int NOR );
int destroy_mindist( void );

int renddis( float POV, int FOV, int NOR ); 
int ray( float ang, int ray_num );
int min_distance( int NOR );


#endif
