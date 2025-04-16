#ifndef PAINTINGBUTTON_H  
#define PAINTINGBUTTON_H

#include <math.h>
#include "raylib.h"
#include "../createButton/createButton.h"

Vector2 brushPosition;
Vector2 prevBrushPosition;
RenderTexture2D canvas;

Button painter;

void initPainting(Color currentColor, float currentSize);
void drawPaintButton(Button *painter);
void updatePaintButton(Button *painter);

#endif