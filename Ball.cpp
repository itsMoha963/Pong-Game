#include <iostream>
#include "Ball.h"
#include <raylib.h>
using namespace std;

Ball::Ball(int screenWidth, int screenHeight) {
    radius = 20; // Set the radius of the ball
    x = screenWidth / 2;
    y = screenHeight / 2;
    speedX = 7;
    speedY = 7;
}
void Ball::Draw() {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Update() {
    x += speedX;
    y += speedY;

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speedY *= -1; // Reverse the speed when hitting the top or bottom of the screen
    }
    if (x + radius >= GetScreenWidth() || x - radius <= 0) {
        speedX *= -1; // Reverse the speed when hitting the left or right side of the screen
    }
}