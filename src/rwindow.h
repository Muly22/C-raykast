#ifndef _RWINDOW_H_
#define _RWINDOW_H_

#include "rerror.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

STATUS create_window( void );
int    next_event   ( void );
STATUS window_clear ( void );
void   close_window ( void );

#endif
