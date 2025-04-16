#ifndef ERASERBUTTON_H
#define ERASERBUTTON_H

#include <math.h>
#include "raylib.h"
#include "../createButton/createButton.h"

// We extract the values that were already defined in the drawingButton.c file

extern Vector2 brushPosition;
extern Vector2 prevBrushPosition;
extern RenderTexture2D canvas;

Button eraser;

void initErasing(float currentSize);
void drawEraserButton(Button *eraser);
void updateEraserButton(Button *eraser);

#endif