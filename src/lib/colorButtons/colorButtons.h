#ifndef COLORBUTTONS_H  
#define COLORBUTTONS_H

#include "raylib.h"

#define MAX_COLORS 15

typedef struct ColorButton {
  Rectangle rect;
  Color color;
} ColorButton;

ColorButton colorButtons[MAX_COLORS];
Color currentColor;

void initColorButtons(void);
void updateColorButtons(void);
void drawColorButtons(void);

#endif

