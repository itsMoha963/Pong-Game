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
    Paddle(int screenWidth, int screenHeight);
    void Draw();
    void Update();
};
#endif