#include "helpMenu.h"

// This function draws the help menu which will overlay the main window and display the controls

void drawHelpMenu(void) {
  DrawRectangle(0, 0, 1280, 860, Fade(RAYWHITE, 0.5f));
  DrawRectangle(20, 20, 1280 - 40, 860 - 40, WHITE);
  DrawText("Controls", 40, 40, 20, BLACK);
  DrawText("Press 'H' to toggle this menu", 40, 70, 20, BLACK);
  DrawText("Press 'Q' to open the utility menu", 40, 90, 20, BLACK);
  DrawText("Press 'R' to clear the canvas", 40, 110, 20, BLACK);
  DrawText("Press 'CTRL + S' to save the canvas, the save location is located in the same directory as the program", 40, 150, 20, BLACK);
  DrawText("Press 'Up Arrow' to change the brush size up", 40, 170, 20, BLACK);
  DrawText("Press 'Down Arrow' to change the brush size down", 40, 190, 20, BLACK);
  DrawText("Press 'Left Arrow' to change to the previous color", 40, 210, 20, BLACK);
  DrawText("Press 'Right Arrow' to change to the next color", 40, 230, 20, BLACK);
  DrawText("Press 'E' to toggle erasing mode", 40, 250, 20, BLACK);
  DrawText("Press 'D' to toggle drawing mode", 40, 270, 20, BLACK);
}