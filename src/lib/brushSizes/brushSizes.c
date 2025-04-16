#include "brushSizes.h"

void initBrushSizeButtons(void){
  int sizes[MAX_SIZES] = {2, 4, 6, 8, 10, 12 ,14 ,16, 18, 20};

  for (int i = 0; i < MAX_SIZES; i++) {
    int half = MAX_SIZES/2;
    
    // Calculate the position of each size button and then set them accordingly

    int row = i < half ? 0 : 1;
    int column = i < half ? i : i - half;

    sizeButtons[i].rect = (Rectangle){ 210 + column * 50, 360 + row * 50, 25, 25 };
    sizeButtons[i].size = sizes[i]; 
  }
  currentSize = sizeButtons[0].size;
}

extern bool showUI;
extern int currentSizeIndex;

void updateBrushSizeButtons(void) {
  if(showUI){
    Vector2 mousePos = GetMousePosition();
    for (int i = 0; i < MAX_SIZES; i++) {
      if (CheckCollisionPointRec(mousePos, sizeButtons[i].rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
          currentSize = sizeButtons[i].size;
          currentSizeIndex = i;
        }
      }
    }
  }
}


// Draw each of the brush size buttons

void drawBrushSizeButtons(void) {
  Vector2 mousePos = GetMousePosition();
  for (int i = 0; i < MAX_SIZES; i++) {

    // Check if mouse is over the button
    // The code below is used to calculate the border and button size based on mouse hover and give the button a hover effect

    bool isMouseOver = CheckCollisionPointRec(mousePos, sizeButtons[i].rect);

    // Calculate border and button size based on mouse hover

    int borderOffset = isMouseOver ? 3 : 2;
    int buttonOffset = isMouseOver ? 1 : 0;
    Rectangle borderRect = {sizeButtons[i].rect.x - borderOffset, sizeButtons[i].rect.y - borderOffset, sizeButtons[i].rect.width + 2*borderOffset, sizeButtons[i].rect.height + 2*borderOffset};
    Rectangle buttonRect = {sizeButtons[i].rect.x - buttonOffset, sizeButtons[i].rect.y - buttonOffset, sizeButtons[i].rect.width + 2*buttonOffset, sizeButtons[i].rect.height + 2*buttonOffset};

    // Draw border and button

    DrawRectangleRec(borderRect, BLACK);
    DrawRectangleRec(buttonRect, WHITE);

    // Draw the and align to the center circle

    int radius = isMouseOver ? sizeButtons[i].size + 2 : sizeButtons[i].size;
    Vector2 center = {buttonRect.x + buttonRect.width / 2, buttonRect.y + buttonRect.height / 2};
    DrawCircleV(center, radius / 2, BLACK);
  }
}