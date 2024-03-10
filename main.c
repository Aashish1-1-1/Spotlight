#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Spotlight");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            int x=GetMouseX();
            int y=GetMouseY();
            DrawFPS(x, y); 
            DrawText("Click to activate", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
