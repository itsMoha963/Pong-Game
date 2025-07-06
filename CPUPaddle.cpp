#include <iostream>
#include "CPUPaddle.h"

using namespace std;

void CPUPaddle::Update(int ball_y) {
    // Simple AI to follow the ball
    if (y + height / 2 < ball_y) {
        y += speed; // Move down
    } else if (y + height / 2 > ball_y) {
        y -= speed; // Move up
    }
    LimitMovement(); // Ensure the paddle does not move out of bounds
}   