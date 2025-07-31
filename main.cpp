#include "./include/raylib.h"
#include "./include/colors.h"
#include "./include/settings.h"
#include "./include/ball.h"

const int screenWidth  = 225 * 2;
const int screenHeight  = 225 * 2;

int main() {
  InitWindow(BLOCK * BOARD + BORDER * BLOCK * 4, BLOCK * BOARD + BORDER * BLOCK, "Scale your Path");
  SetTargetFPS(60);

  Ball ball = Ball((float)screenWidth/2, (float)screenHeight/2);

  Vector2 center = { screenWidth / 2.0f, screenHeight / 2.0f };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRUVBOX_DARK0);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
