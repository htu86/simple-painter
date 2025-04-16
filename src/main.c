#include "../include/raylib.h"
#include "./lib/colorButtons/colorButtons.h"
#include "./lib/paintingButton/paintingButton.h"
#include "./lib/brushSizes/brushSizes.h"
#include "./lib/mousePos/mousePos.h"
#include "./lib/eraserButton/eraserButton.h"
#include "./lib/textureLoader/textureLoader.h"
#include "./lib/saveButton/saveButton.h"
#include "./lib/helpMenu/helpMenu.h"

#define WIDTH 1280
#define HEIGHT 860

// These variables are global because they need to be accessed in the appropriate header files

bool showUI = false;
bool drawingMode = true;
bool erasingMode = false;
int currentColorIndex = 0;
int currentSizeIndex = 0;

int main() {
  InitWindow(WIDTH, HEIGHT, "Simple Painter");
  bool showHelpMenu = false;

  initColorButtons();
  initBrushSizeButtons();

  // Load the textures and initialize the canvas as its own texture

  canvas = LoadRenderTexture(WIDTH, HEIGHT);
  loadSprite(&painter.texture, "./textures/pencil.png");
  loadSprite(&eraser.texture, "./textures/eraser.png");
  loadSprite(&save.texture, "./textures/export.png");

  SetTargetFPS(120);

  while (!WindowShouldClose()) {

    BeginDrawing();

    //Here we update all of the buttons continuously to check for any changes

    updateColorButtons();
    updateBrushSizeButtons();
    updatePaintButton(&painter);
    updateEraserButton(&eraser);
    updateSaveButton(&save, canvas);

    // Below are the key bindings for the program

    // Toggle the UI with the q key

    if(IsKeyPressed(KEY_Q)){
      showUI = !showUI;
    }

    // Toggle the help menu with the h key

    if(IsKeyPressed(KEY_H)){
      showHelpMenu = !showHelpMenu;
    }

    // Clear the canvas using the r key

    if (IsKeyPressed(KEY_R)) {
      BeginTextureMode(canvas);
      DrawRectangle(0, 0, canvas.texture.width, canvas.texture.height, RAYWHITE);
      EndTextureMode();
    }

    // Change the color with the left and right arrow keys

    if(IsKeyPressed(KEY_RIGHT)){
      currentColorIndex++;
      if(currentColorIndex >= MAX_COLORS){
        currentColorIndex = 0;
      }
      currentColor = colorButtons[currentColorIndex].color;
    }
    if(IsKeyPressed(KEY_LEFT)){
      currentColorIndex--;
      if(currentColorIndex < 0){
        currentColorIndex = MAX_COLORS - 1;
      }
      currentColor = colorButtons[currentColorIndex].color;
    }

    // Change brush size using the up and down arrow keys

    if(IsKeyPressed(KEY_UP)){
      currentSizeIndex++;
      if(currentSizeIndex >= MAX_SIZES){
        currentSizeIndex = 0;
      }
      currentSize = sizeButtons[currentSizeIndex].size;
    }
    if(IsKeyPressed(KEY_DOWN)){
      currentSizeIndex--;
      if(currentSizeIndex < 0){
        currentSizeIndex = MAX_SIZES - 1;
      }
      currentSize = sizeButtons[currentSizeIndex].size;
    }

    // Toggle between drawing and erasing modes with the e and d keys

    if(IsKeyPressed(KEY_E)){
      erasingMode = true;
      drawingMode = false;
    }
    if(IsKeyPressed(KEY_D)){
      drawingMode = true;
      erasingMode = false;
    }

    // Initialize the canvas and draw the texture

    ClearBackground(RAYWHITE);
    DrawTexturePro(canvas.texture, (Rectangle){0.0f, 0.0f, (float)canvas.texture.width, (float)-canvas.texture.height}, (Rectangle){0.0f, 0.0f, (float)1280, (float)860}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);

    // If the drawing mode is enabled, we initialize the painting algorithm
    // Else the erasing mode is toggled

    if(drawingMode){
      initPainting(currentColor, currentSize);
    }
    else if(erasingMode){
      initErasing(currentSize);
    }

    // The UI is only drawn if the showUI variable is true

    if(showUI){

      Rectangle windowRect = { 200, 200, 245, 410 };
      Rectangle borderRect = { windowRect.x - 1, windowRect.y - 1, windowRect.width + 2, windowRect.height + 2 };


      DrawRectangleRec(borderRect, GRAY);
      DrawRectangleRec(windowRect, WHITE);

      // Drawing all of the buttons

      drawColorButtons();
      drawBrushSizeButtons();
      drawPaintButton(&painter);
      drawEraserButton(&eraser);
      drawSaveButton(&save);

      //Here we update all of the buttons continuously to check for any changes

      updateColorButtons();
      updateBrushSizeButtons();
      updatePaintButton(&painter);
      updateEraserButton(&eraser);
      updateSaveButton(&save, canvas);
    }

    // This is the help menu that shows the controls

    if(showHelpMenu){
      drawHelpMenu();
    }

    EndDrawing();
  }

  // Free the memory that was allocated for the canvas and other textures

  UnloadRenderTexture(canvas);
  UnloadTexture(painter.texture);
  UnloadTexture(eraser.texture);
  UnloadTexture(save.texture);
  CloseWindow();

  return 0;
}