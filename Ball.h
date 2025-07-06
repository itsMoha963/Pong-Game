#ifndef _BALL_H
#define _BALL_H
#include <iostream>
class Ball{
    public:
        float x, y;
        int speedX, speedY;
        int radius;
        void Draw();
        void Update();
};
#endif