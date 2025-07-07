#ifndef _PADDLE_H
#define _PADDLE_H
#include <raylib.h>
class Paddle {
protected:
    void LimitMovement();
public:
    float x, y;
    float width, height;
    int speed;
    Paddle(float xPos, float yPos);
    void Draw();
    void Update();
};
#endif