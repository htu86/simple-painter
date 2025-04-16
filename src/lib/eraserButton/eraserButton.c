#include "eraserButton.h"
#include "../paintingButton/paintingButton.h"
#include "../mousePos/mousePos.h"

// Draw the eraser button

void drawEraserButton(Button *eraser){
  createButton(eraser, 260);
}
// Here we are using the same drawing algorithm as the painting algorithm, but we are using the background color to erase

void initErasing(float currentSize) {
  initPainting(RAYWHITE, currentSize);
}

// Get the global variables from the main file

extern bool drawingMode;
extern bool erasingMode;
extern bool showUI;

// This button turns on the erasing mode

void updateEraserButton(Button *eraser){
  if(showUI){
    if (CheckCollisionPointRec(GetMousePosition(), eraser->rect)) {
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        drawingMode = false;
        erasingMode = true;
      }
    }
  }
}