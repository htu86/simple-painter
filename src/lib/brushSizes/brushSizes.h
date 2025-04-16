#ifndef BRUSHSIZES_H
#define BRUSHSIZES_H

#include "raylib.h"

#define MAX_SIZES 10

typedef struct BrushSizeButton {
  Rectangle rect;
  int size;
} BrushSizeButton;

BrushSizeButton sizeButtons[MAX_SIZES];
int currentSize;

void initBrushSizeButtons(void);
void updateBrushSizeButtons(void);
void drawBrushSizeButtons(void);

#endif