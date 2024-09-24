#ifndef _RAYCAST_CORE_H_
#define _RAYCAST_CORE_H_

#include "player.h"
#include "world.h"

extern RAY *rays;
extern INTERSECTION *intersection;
extern PLAYER player;
extern WORLD world;

void init_rays(int NOR);
void destroy_rays(int NOR);

void init_mindist(int NOR);
void destroy_mindist(void);

void renddis(float POV, int FOV, int NOR); 
void ray(float ang, RAY *r);
void min_distance(int NOR);

#endif
