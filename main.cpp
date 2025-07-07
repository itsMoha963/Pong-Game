#include <iostream>
#include <vector>
#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "CPUPaddle.h"
using namespace std; 
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 400;
Color Green = Color{38, 185, 154, 255};
Color LightGreen= Color{129, 204, 184, 255};
Color DarkGreen = Color{20, 160, 133, 155};
Color Blue = Color{135, 206, 235, 255};
Color LightBlue = Color{173, 216, 230, 255};
Color mintGreen = Color{152, 255, 152, 255};
Color darkblue = Color{100, 180, 200, 255};
int cpuScore = 0;
int playerScore = 0;
const int RECTANGLE_WIDTH = 25;
const int RECTANGLE_HEIGHT = 120;

Ball ball(SCREEN_WIDTH, SCREEN_HEIGHT);
Paddle player(SCREEN_WIDTH - 35,SCREEN_HEIGHT/2- RECTANGLE_HEIGHT/2);
CPUPaddle cpu(10, SCREEN_HEIGHT/2 - RECTANGLE_HEIGHT/2); // Create a CPU paddle on the left side of the screen
int main()
{


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My Pong Game");
    SetTargetFPS(60);
   

    while (WindowShouldClose() == false){
   
        
        BeginDrawing();
        ClearBackground(darkblue);
        DrawRectangle(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, Blue);
        DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 75, LightBlue);
        ball.Update();

        // Check if the ball hits the left or right screen edges
    if (ball.x - ball.radius <= 0) {
        playerScore++;  // Player scores when ball hits the left wall
       
        ball.ResetBall();
    }

    if (ball.x + ball.radius >= SCREEN_WIDTH) {
        cpuScore++;  // CPU scores when ball hits the right wall
      
        ball.ResetBall();
    }



        player.Update();
        cpu.Update(ball.y); // Update the CPU paddle based on the ball's position
       if(CheckCollisionCircleRec(::Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})){
            ball.speedX *= -1; // Reverse the ball's direction when it collides with the player's paddle
        }
       
        if(CheckCollisionCircleRec(::Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
            ball.speedX *= -1; // Reverse the ball's direction when it collides with the CPU paddle
        }

        DrawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2,SCREEN_HEIGHT, WHITE); // Draw a vertical line in the middle of the screen to separate the two sides of the game.

        ball.Draw();

        //DrawRectangle(10,SCREEN_HEIGHT/2 - RECTANGLE_HEIGHT/2, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, WHITE);// to center the rectangle on the screen, we need to subtract half of its height from the center y position since when we only devide the height by two we just use the corner of the rectangle as the center point, but we want the center of the rectangle to be at the center of the screen.
       // DrawRectangle(SCREEN_WIDTH -35, SCREEN_HEIGHT/2 - RECTANGLE_HEIGHT/2, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, WHITE);// rectangle is drawn at the to left corner of the screen so we need to subtract the width of the rectangle from the screen width to get the correct position for the right side of the rectangle. plus 10px that we added to the right side of the rectangle to make it look like a paddle.
        player.Draw();
        cpu.Draw(); // Draw the CPU paddle
       

        DrawText(TextFormat("%i",cpuScore), SCREEN_WIDTH /4 -20, 20, 80, WHITE);
        DrawText(TextFormat("%i",playerScore), 3*SCREEN_WIDTH/4-20, 20, 80, WHITE);
        EndDrawing();
    }

    CloseWindow();
}
