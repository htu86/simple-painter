#include "mousePos.h"

// Get the brush position, this function is used in both the drawing and erasing algorithms

void getBrushPosition(Vector2 *currentMousePos, Vector2 *previousMousePos){
  *previousMousePos = *currentMousePos;
  currentMousePos->x = GetMouseX();
  currentMousePos->y = GetMouseY();
}