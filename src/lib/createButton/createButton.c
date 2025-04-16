#include "createButton.h"

void createButton(Button *button, int posX) {
  Vector2 mousePos = GetMousePosition();
  bool isMouseOver = CheckCollisionPointRec(mousePos, button->rect);

  int borderOffset = 2; 
  int buttonOffset = isMouseOver ? 1 : 0;
  
  // Calculate and position the button

  button->rect = (Rectangle){ posX - buttonOffset, 460 - buttonOffset, 25 + 2*buttonOffset, 25 + 2*buttonOffset };

  // Draw the border
  Rectangle borderRect = { button->rect.x - borderOffset, button->rect.y - borderOffset, button->rect.width + 2*borderOffset, button->rect.height + 2*borderOffset };
  DrawRectangleRec(borderRect, BLACK);

  // Draw the button
  DrawRectangleRec(button->rect, WHITE);
  int textureX = button->rect.x + button->rect.width / 2 - button->texture.width / 2;
  int textureY = button->rect.y + button->rect.height / 2 - button->texture.height / 2;
  DrawTexture(button->texture, textureX, textureY, WHITE);
}