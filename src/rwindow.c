#include "rwindow.h"

unsigned int window_width=1920;
unsigned int window_height=1080;

#include <X11/Xlib.h>
#include <stdlib.h>

Display *d;
Window w;
XEvent e;
int s;

void create_window() {
}

void close_window() {
}

void draw_ray_line( int H_pix, int pos_x_pix, TEXTURE *texture  ) {
  //XDrawLine( d, w, DefaultGC(d, s), pos_x_pix, H_pix - (SCREEN_HEIGHT >> 2), pos_x_pix, H_pix );
}
