#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball {
private:
  float radius;
  Vector2 position; 

public:
  Ball(float x, float y); 
};

#endif //BALL_H
