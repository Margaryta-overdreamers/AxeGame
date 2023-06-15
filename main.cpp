#include "raylib.h"

int main() 
{
    //window dimentions
    int width = 500;
    int hight = 500;
    InitWindow(width, hight, "Axe Game");

    //circle coordinates
    int circle_x = 250;
    int circle_y = 250;
    int circleRadius = 25;

    //circle adges 
    int l_circle_x = circle_x - circleRadius;
    int r_circle_x = circle_x + circleRadius;
    int u_circle_y = circle_y - circleRadius;
    int b_circle_y = circle_y + circleRadius;

    // axe coordinates 
    int axe_lenth = 50;
    int axe_x = 250;
    int axe_y = 0;

    // axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_lenth;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_lenth;

    int step = 5;
    int direction = 10;

    bool collision_with_axe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

    SetTargetFPS(60);

    while( WindowShouldClose() == false )
    {
        BeginDrawing();
        ClearBackground(RED);

        if (collision_with_axe) 
        {
            DrawText("Game Over!", 150, 250,40, BLACK);
        } 
        else {
            /*
            * Game logic begins
            */

            // update the edges 
            l_circle_x = circle_x - circleRadius;
            r_circle_x = circle_x + circleRadius;
            u_circle_y = circle_y - circleRadius;
            b_circle_y = circle_y + circleRadius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_lenth;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_lenth;

            // update collision with axe
            collision_with_axe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

            //circle more area
            DrawCircle(circle_x, circle_y, circleRadius, YELLOW);
            if ( IsKeyDown(KEY_RIGHT) && r_circle_x < width )
            {
                circle_x += step;
            }
            if (IsKeyDown(KEY_LEFT) && l_circle_x > 0)
            {
                circle_x -= step;
            }
            if (IsKeyDown(KEY_UP) && - u_circle_y < 0)
            {
                circle_y -= step; 
            }
            if (IsKeyDown(KEY_DOWN) && - b_circle_y > - hight)
            {
                circle_y += step;
            }

            DrawRectangle(axe_x, axe_y , axe_lenth, axe_lenth, PURPLE);

            // axe movement
            axe_y += direction;
            if (axe_y > (hight - axe_lenth) || axe_y < 0)
            {
                direction = -direction;
            }
            /*
            * Game logic ends
            */
        }

        EndDrawing(); 

    }
}