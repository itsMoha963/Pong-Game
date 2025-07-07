#include <iostream>
#include "CPUPaddle.h"

using namespace std;
CPUPaddle::CPUPaddle(float xPos, float yPos):Paddle(xPos,yPos){
    width = 25;
    height = 120;
    speed = 4; // Set the speed of the paddle
    x = xPos;   // Initial x position
    y = yPos;   // Center the paddle vertically
}
void CPUPaddle::Update(int ball_y) {
    // Simple AI to follow the ball
    if (y + height / 2 < ball_y) {
        y += speed; // Move down
    } else if (y + height / 2 > ball_y) {
        y -= speed; // Move up
    }
    LimitMovement(); //protected method to check paddle bounds
}   