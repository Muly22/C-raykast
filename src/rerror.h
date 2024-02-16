#ifndef _RERROR_H_ 
#define _RERROR_H_

#include <stdio.h>

typedef enum {
  SUCCESS = 0,
  ERROR_INIT,
  ERROR_RENDDIS,
  ERROR_RAY
} STATUS;

int check_error( STATUS exit_code, char *error );

#endif
