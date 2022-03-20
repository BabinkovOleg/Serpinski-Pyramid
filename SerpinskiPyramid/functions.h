#include "raylib.h"
#pragma once

void DrawControls();
void DrawSerpinskiPyramid3(float height, Vector3 top, Color pyramidColor, Color wireColor, float minHeight);
void DrawModelSerpinskiPyramid3(float height, Vector3 top, Color pyramidColor, Color wireColor, Shader shader, float scale, Model model, float minHeight);