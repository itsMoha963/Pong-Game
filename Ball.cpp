#include <iostream>
#include "Ball.h"
#include <raylib.h>
using namespace std;
Color yellow = Color{243,213,91,155};
Color DarkYellow = Color{189, 183, 107, 255};
Color coral = Color{255, 127, 80, 255};
Ball::Ball(int screenWidth, int screenHeight)
{
    radius = 20; // Set the radius of the ball
    x = screenWidth / 2;
    y = screenHeight / 2;
    speedX = 8;
    speedY = 8;
}
void Ball::Draw() {
    DrawCircle(x, y, radius, coral);
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
void Ball::ResetBall() {
    x = GetScreenWidth() / 2; // Reset ball position to the center of the screen
    y = GetScreenHeight() / 2;
    int speedchoices[2] = {-1, 1};
   // Randomly choose direction for speedX
   speedX *= speedchoices[GetRandomValue(0,1)];
   speedY *= speedchoices[GetRandomValue(0, 1)];
}