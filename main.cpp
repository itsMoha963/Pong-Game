#include <iostream>
#include <raylib.h>
#include "Ball.h"
using namespace std;
Ball ball;

int main()
{

    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 400;

    const int RECTANGLE_WIDTH = 25;
    const int RECTANGLE_HEIGHT = 120;


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My Pong Game");
    SetTargetFPS(60);
    ball.radius = 20; // Set the radius of the ball
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    while (WindowShouldClose() == false){
   
        
        BeginDrawing();
        ClearBackground(BLUE);
        ball.Update();
        DrawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2,SCREEN_HEIGHT, WHITE); // Draw a vertical line in the middle of the screen to separate the two sides of the game.

        ball.Draw();

        DrawRectangle(10,SCREEN_HEIGHT/2 - RECTANGLE_HEIGHT/2, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, WHITE);// to center the rectangle on the screen, we need to subtract half of its height from the center y position since when we only devide the height by two we just use the corner of the rectangle as the center point, but we want the center of the rectangle to be at the center of the screen.
        DrawRectangle(SCREEN_WIDTH -35, SCREEN_HEIGHT/2 - RECTANGLE_HEIGHT/2, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, WHITE);// rectangle is drawn at the to left corner of the screen so we need to subtract the width of the rectangle from the screen width to get the correct position for the right side of the rectangle. plus 10px that we added to the right side of the rectangle to make it look like a paddle.

       
        EndDrawing();
    }

    CloseWindow();
}
