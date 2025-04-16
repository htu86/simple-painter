#include "colorButtons.h"

void initColorButtons(void) {
  Color colors[MAX_COLORS] = {RED, BLUE, GREEN, YELLOW, BLACK, SKYBLUE, PINK, ORANGE, BROWN, WHITE, PURPLE, GRAY, BEIGE, LIME, MAROON};
  int third = MAX_COLORS/3;

  for (int i = 0; i < MAX_COLORS; i++) {

    // Calculations to split the colors into 3 rows

    int row = i / third;
    int column = i % third;

    // Calculate the position of each color button and then set them accordingly

    colorButtons[i].rect = (Rectangle){ 210 + column * 50, 210 + row * 50, 25, 25 };
    colorButtons[i].color = colors[i]; 
  }
  currentColor = colorButtons[0].color;
}

// This function checks if the mouse is over any of the color buttons
// If the mouse is over the button and is clicked on said button, 
// currentColor is updated to match the button that was clicked

extern bool showUI;
extern int currentColorIndex;

void updateColorButtons(void) {
  if(showUI){
    Vector2 mousePos = GetMousePosition();
    for (int i = 0; i < MAX_COLORS; i++) {
      if (CheckCollisionPointRec(mousePos, colorButtons[i].rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
          currentColor = colorButtons[i].color;
          currentColorIndex = i;
        }
      }
    }
  }
}

// Draw each of the color buttons

void drawColorButtons(void) {
  Vector2 mousePos = GetMousePosition();
  for (int i = 0; i < MAX_COLORS; i++) {

    // Check if mouse is over the button

    bool isMouseOver = CheckCollisionPointRec(mousePos, colorButtons[i].rect);

    // Calculate border and button size based on mouse hover

    int borderOffset = isMouseOver ? 3 : 2;
    int buttonOffset = isMouseOver ? 1 : 0;
    Rectangle borderRect = {colorButtons[i].rect.x - borderOffset, colorButtons[i].rect.y - borderOffset, colorButtons[i].rect.width + 2*borderOffset, colorButtons[i].rect.height + 2*borderOffset};
    Rectangle buttonRect = {colorButtons[i].rect.x - buttonOffset, colorButtons[i].rect.y - buttonOffset, colorButtons[i].rect.width + 2*buttonOffset, colorButtons[i].rect.height + 2*buttonOffset};

    // Draw border and button

    DrawRectangleRec(borderRect, BLACK);
    DrawRectangleRec(buttonRect, colorButtons[i].color);
  }
}