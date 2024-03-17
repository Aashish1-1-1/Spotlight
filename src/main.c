// Copyright(c) 2024 Aashish Adhikari
// This software is distributed under MIT license

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#define MOUSEFILE "/dev/input/event9"

int fd;
struct input_event ie;


typedef struct Button
{
    Rectangle rect;
    Color color;
} Button;

Button button_0 = {0}; // The button

// bool to check if the button is clicked
bool button_0_clicked = false;

// Function to initialize the button
void init_button(Button *button, Rectangle rect, Color color)
{
    /*
        This function will initialize the button
        button: the button to initialize
        rect: the button rectangle
        color: the button color
    */

    button->rect = rect;
    button->color = color;
}

// Function to check if the mouse is over the button
bool is_mouse_over_button(Button button)
{
    /*
        This function will check if the mouse is over the button
        button: the button to check
    */

    return CheckCollisionPointRec(GetMousePosition(), button.rect);
}

// Local Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void); // Update and draw one frame

void createSpot(){
    system("gsettings set org.gnome.desktop.interface cursor-theme Spotlight");
}

void offSpot(){
    system("gsettings set org.gnome.desktop.interface cursor-theme Adwaita");
}
//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Spotlight");

    // Initialize the button
    init_button(&button_0, (Rectangle){screenWidth / 2 - 100, screenHeight / 2 - 50, 200, 100}, RED);

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    //Reading the mouseinput file
	if((fd = open(MOUSEFILE, O_RDONLY)) == -1) {
		perror("opening device");
		exit(EXIT_FAILURE);
	}
    // Main game loop
    while (!WindowShouldClose() && read(fd, &ie, sizeof(struct input_event))) // Detect window close button or ESC key
    {
        UpdateDrawFrame();

      	printf("time %ld.%06ld\ttype %d\tcode %d\tvalue %d\n", ie.time.tv_sec, ie.time.tv_usec, ie.type, ie.code, ie.value);
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    offSpot();
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------

    // Check if the mouse is over the button
    if (is_mouse_over_button(button_0))
    {
        button_0.color = BLUE;
    }
    else
    {
        button_0.color = RED;
    }

    // Change the screen collor when the button is clicked
    if (is_mouse_over_button(button_0) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        button_0_clicked = !button_0_clicked;
    }

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Draw the button
    DrawRectangleRec(button_0.rect, button_0.color);

    // Draw the button text
    DrawText("Click to on/off", button_0.rect.x + button_0.rect.width / 2 - MeasureText("Click to on/off", 20) / 2, button_0.rect.y + button_0.rect.height / 2 - 20 / 2, 20, WHITE);

    // Change the screen color when the button is clicked
    if (button_0_clicked)
    {
        ClearBackground(GREEN);
            if(ie.value==120){
             createSpot();
           }
           if(ie.value==-120){
             offSpot();
    }
  
    }
    else {
        offSpot();
        ClearBackground(WHITE);
    }

    DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}
