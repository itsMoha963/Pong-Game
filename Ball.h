#ifndef _BALL_H
#define _BALL_H
#include <iostream>
class Ball{
    public:
        float x, y;
        int speedX, speedY;
        int radius;
        Ball(int screenWidth, int screenHeight);

        void Draw();
        void Update();
};
#endif