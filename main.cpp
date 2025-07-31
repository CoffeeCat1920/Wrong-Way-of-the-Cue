#include "./include/raylib.h"
#include "./include/colors.h"
#include <cmath>

const int screenWidth  = 225 * 2;
const int screenHeight  = 225 * 2;

class HexPattern {
  
private:

  Vector2 center;
  float radius;
  Color circleColor;
  Color pointColor;
  Vector2 points[24];

public:

  HexPattern(Vector2 center, float radius, Color circleColor, Color pointColor)
      : center(center), radius(radius), circleColor(circleColor), pointColor(pointColor) {
    for (int i = 0; i < 24; i++) {
      float angleRad = i * 15.0f * (PI / 180.0f);
      points[i] = {
        center.x + radius * cosf(angleRad),
        center.y + radius * sinf(angleRad)
      };
    }

  }

  void Draw() const {
    DrawCircleLines((int)center.x, (int)center.y, radius, circleColor);
    DrawCircleLines((int)center.x, (int)center.y, radius/2 - 5, GRUVBOX_BLUE);
    for (int i = 100; i > 10; i -= 5) {
      DrawCircleLines((int)center.x, (int)center.y, radius/2 - i, GRUVBOX_BLUE);
    }

    DrawCircleLines((int)center.x, (int)center.y, radius + 10, GRUVBOX_ORANGE);

    for (int i = 0; i < 24; i++) {
      Vector2 pointA = points[i];

      Vector2 pointB1 = points[(i + 8) % 24];
      Vector2 pointB2 = points[(i + 16) % 24]; // same as (i - 6 + 24) % 12

      DrawLineV(pointA, pointB1, pointColor);
      DrawLineV(pointA, pointB2, pointColor);
    }
  }

};

int main() {
  InitWindow(screenWidth, screenHeight, "HexPattern Simple Class");
  SetTargetFPS(60);

  Vector2 center = { screenWidth / 2.0f, screenHeight / 2.0f };
  HexPattern hex(center, screenWidth / 2.5f, GRUVBOX_LIGHT0, GRUVBOX_AQUA);  // change colors as you like

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRUVBOX_DARK0);

    hex.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
