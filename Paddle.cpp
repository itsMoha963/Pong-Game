#include <iostream>
#include "Paddle.h"
#include <raylib.h>

using namespace std;
Paddle::Paddle(int screenWidth, int screenHeight) {
    width = 25;
    height = 120;
    speed = 10; // Set the speed of the paddle
    x = screenWidth - this->width -10; // Initial x position
    y = screenHeight / 2 - this->height /2; // Center the paddle vertically
    speed = 6;
}

void Paddle::Draw() {
    DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::LimitMovement() {
    // Ensure the paddle does not move out of bounds
    if(y <= 0) {
        y = 0; // Prevent paddle from going above the screen
    }
    if(y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height; // Prevent paddle from going below the screen
    }
}
void Paddle::Update(){
    if(IsKeyDown(KEY_UP)){
        y -= speed; // Move up
    }
    if(IsKeyDown(KEY_DOWN)){
        y += speed; // Move down
    }
    LimitMovement();
}