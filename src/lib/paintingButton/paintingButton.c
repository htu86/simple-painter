#include "paintingButton.h"
#include "../mousePos/mousePos.h"

Vector2 prevBrushPosition = {-1.0f, -1.0f};

// Draw the paint button

void drawPaintButton(Button *painter){
  createButton(painter, 210);
}

void initPainting(Color currentColor, float currentSize) {

  getBrushPosition(&brushPosition, &prevBrushPosition);

  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    BeginTextureMode(canvas);

    if(prevBrushPosition.x >= 0 && prevBrushPosition.y >= 0) {

      int points = hypot(brushPosition.x - prevBrushPosition.x, brushPosition.y - prevBrushPosition.y);

      for (int i = 0; i < points; i++) {
        float t = (float)i / (float)points;
        Vector2 interpolated = {
          .x = prevBrushPosition.x + t * (brushPosition.x - prevBrushPosition.x),
          .y = prevBrushPosition.y + t * (brushPosition.y - prevBrushPosition.y)
        };
        DrawCircleV(interpolated, currentSize, currentColor);
      }
    }
    EndTextureMode();
  }
  
  // Draw the brush preview with the currentColor and currentSize

  Color backgroundColor = RAYWHITE;
  
  // Check if the current color is the same as the eraser color

  if (currentColor.r == backgroundColor.r && currentColor.g == backgroundColor.g && currentColor.b == currentColor.b) {
    DrawCircleLines(brushPosition.x, brushPosition.y, currentSize + 1, BLACK);
    DrawCircleV(brushPosition, currentSize, WHITE);
  } 
  else{
    DrawCircleV(brushPosition, currentSize, currentColor);
  }
}

// Get the global variables from the main file

extern bool drawingMode;
extern bool erasingMode;
extern bool showUI;

// This function turns on the drawing mode

void updatePaintButton(Button *painter){
  if(showUI){
    if (CheckCollisionPointRec(GetMousePosition(), painter->rect)) {
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        drawingMode = true;
        erasingMode = false;
      }
    }
  }
}