#ifndef CREATEBUTTON_H
#define CREATEBUTTON_H

#include "raylib.h"

typedef struct Button {
  Texture2D texture;
  Rectangle rect;
} Button;

Button button;
void createButton(Button *button, int posX);

#endif