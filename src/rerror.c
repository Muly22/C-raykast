#include <stdio.h>
#include "rerror.h"

int check_error( STATUS exit_code, char *error ) {
  switch (exit_code) {
    case ERROR_INIT:
      printf("ERROR: init %s\n", error);
    break;
    case ERROR_RAY:
      printf("ERROR: ray %s\n", error);
    break;
    case ERROR_RENDDIS:
      printf("ERROR: renddis %s\n", error);
    break;
  }
  return (int)exit_code;
}
