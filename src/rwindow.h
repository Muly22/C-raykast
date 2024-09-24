#ifndef _RWINDOW_H_
#define _RWINDOW_H_

#include "texture.h"

extern unsigned int window_width;
extern unsigned int window_height;

void create_window(void);
void close_window(void);

void draw_ray_line(int H_pix, int pos_x_pix, TEXTURE *texture);

#endif
