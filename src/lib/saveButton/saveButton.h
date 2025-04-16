#ifndef SAVEBUTTON_H
#define SAVEBUTTON_H

#include "raylib.h"
#include <time.h>
#include <stdio.h>
#include "../createButton/createButton.h"

Button save;

void drawSaveButton(Button *save);
void updateSaveButton(Button *save, RenderTexture2D canvas);
void saveImage(Button *save, RenderTexture2D canvas);

#endif