#include "player.h"
#include "raycast_core.h"
#include "raylib_window.h"
#include <stdio.h>

int main_loop(void);
int main_destroy(void);

int main() {
  int exit_status;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "test");
  SetWindowState(FLAG_FULLSCREEN_MODE | FLAG_WINDOW_RESIZABLE);
  SCREEN_WIDTH = GetScreenWidth();
  SCREEN_HEIGHT = GetScreenHeight();
  exit_status = init_rays(SCREEN_WIDTH);
  if (exit_status) {
    printf("Error: init_rays");
    goto dest;
    return 1;
  }
  init_mindist(SCREEN_WIDTH);
  exit_status = main_loop();
  if (exit_status) {
    printf("Error: main_loop");
    goto dest;
    return 1;
  }
dest:
  main_destroy();
  return 0;
}

int main_loop() {
  for (;;) {
    if (IsKeyPressed(KEY_END)) {
      return 0;
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    renddis(player.angle, player.FOV, SCREEN_WIDTH);
    min_distance(SCREEN_WIDTH);
    EndDrawing();
  }
}

int main_destroy() { CloseWindow(); return 0; }
