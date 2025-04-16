#include "textureLoader.h"

// This a simple function to load a texture from a path

void loadSprite(Texture2D *texture, const char *path) {
  *texture = LoadTexture(path);
}