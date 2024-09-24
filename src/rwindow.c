#include "rwindow.h"

int SCREEN_WIDTH=1920;
int SCREEN_HEIGHT=1080;

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
