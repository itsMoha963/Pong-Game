#include <iostream>
#include "Paddle.h"
#include <raylib.h>

using namespace std;
Paddle::Paddle(float xPos, float yPos) {
    width = 25;
    height = 120;
    x = xPos;   // screenWidth - this->width -10; // Initial x position
    y = yPos;   // screenHeight / 2 - this->height /2; // Center the paddle vertically
    speed = 6;
}

void Paddle::Draw() {
   // DrawRectangle(x, y, width, height, WHITE);
    DrawRectangleRounded(Rectangle{ x, y, width, height }, 0.8f, 0, Color{112, 128, 144, 255}); // Draw rounded rectangle for paddle
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