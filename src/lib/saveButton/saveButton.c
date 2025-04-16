#include "saveButton.h"

// Draw the save button on the screen

void drawSaveButton(Button *save){
  createButton(save, 310);
}

// When the button is pressed the canvas is exported as a png file
// The image is flipped vertically to match the drawing orientation

void updateSaveButton(Button *save, RenderTexture2D canvas){

  if (CheckCollisionPointRec(GetMousePosition(), save->rect)) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      saveImage(save, canvas);
    }
  }
  if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_S)) {
    saveImage(save, canvas);
  }
}
void saveImage(Button *save, RenderTexture2D canvas){
  Image image = LoadImageFromTexture(canvas.texture);
  ImageFlipVertical(&image);

  // Get the current time
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];
  time (&rawtime);
  timeinfo = localtime(&rawtime);


  // Create a new image with a white background
  Image whiteBackground = GenImageColor(image.width, image.height, RAYWHITE);

  // Draw the original image onto the white background
  ImageDraw(&whiteBackground, image, (Rectangle){0, 0, image.width, image.height}, (Rectangle){0, 0, image.width, image.height}, WHITE);

  strftime(buffer, sizeof(buffer),"%H_%M_%S-%d.%m.%Y", timeinfo); // Formatting the time string
  char filename[100];
  sprintf(filename, "output_%s.png", buffer); // Format the filename string with the time string


  // Save the new image
  ExportImage(whiteBackground, filename);

  // Unload the images
  UnloadImage(image);
  UnloadImage(whiteBackground);
}
