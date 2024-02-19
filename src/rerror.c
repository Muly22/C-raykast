#include <string.h>
#include <stdio.h>
#include "rerror.h"

STATUS exit_status;
char exit_message[255] = "";

int check_error( STATUS exit_code ) {
  switch (exit_code) {
    case ERROR_INIT:
      printf("ERROR: init: %s\n", exit_message);
    break;
    case ERROR_RAY:
      printf("ERROR: ray: %s\n", exit_message);
    break;
    case ERROR_RENDDIS:
      printf("ERROR: renddis: %s\n", exit_message);
    break;
    case ERROR_DISPLAY:
      printf("ERROR: display_cereate: %s\n", exit_message);
    break;
    case ERROR_CLEAR_WINDOW:
      printf("ERROR: clear_window: %s\n", exit_message);
    break;
    case ERROR_MAIN_LOOP:
      printf("ERROR: main_loop: %s\n", exit_message);
    break;
  }
  
  return (int)exit_code;
}
