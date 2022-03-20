#include "raylib.h"
#include "functions.h"
#include <math.h>

void DrawControls() {
	DrawRectangle(10, 10, 320, 133, Fade(SKYBLUE, 0.5f));
	DrawRectangleLines(10, 10, 320, 133, BLUE);

	DrawText("Free camera default controls:", 20, 20, 10, BLACK);
	DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
	DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
	DrawText("- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, DARKGRAY);
	DrawText("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, DARKGRAY);
	DrawText("- Z to zoom to (0, 0, 0)", 40, 120, 10, DARKGRAY);
}

void DrawSerpinskiPyramid3(float height, Vector3 top, Color pyramidColor, Color wireColor, float minHeight) {
	float triangleHeight = height * (float)sqrt(12.0f / 13.0f);
	if (height >= minHeight) {
		float side = 4 * height / (float)sqrt(13.0f);
		DrawSerpinskiPyramid3(height / 2, (Vector3) { top.x, top.y, top.z }, pyramidColor, wireColor, minHeight);

		DrawSerpinskiPyramid3(height / 2, (Vector3) { top.x, top.y - height / 2, top.z + triangleHeight / 3 }, pyramidColor, wireColor, minHeight);
		DrawSerpinskiPyramid3(height / 2, (Vector3) { top.x + side / 4, top.y - height / 2, top.z - triangleHeight / 6 }, pyramidColor, wireColor, minHeight);
		DrawSerpinskiPyramid3(height / 2, (Vector3) { top.x - side / 4, top.y - height / 2, top.z - triangleHeight / 6 }, pyramidColor, wireColor, minHeight);
	}
	else {
		DrawCylinder(top, 0.0f, triangleHeight * 2 / 3, height, 3, pyramidColor);
		DrawCylinderWires(top, 0.0f, triangleHeight * 2 / 3, height, 3, wireColor);
	}
}

void DrawModelSerpinskiPyramid3(float height, Vector3 top, Color pyramidColor, Shader shader, float scale, Model model, float minHeight) {
	float triangleHeight = height * (float)sqrt(12.0f / 13.0f);
	if (height >= minHeight) {
		float side = 4 * height / (float)sqrt(13.0f);
		DrawModelSerpinskiPyramid3(height / 2, (Vector3) { top.x, top.y, top.z }, pyramidColor, shader, scale / 2, model, minHeight);

		DrawModelSerpinskiPyramid3(height / 2, (Vector3) { top.x - triangleHeight / 3, top.y - height / 2, top.z }, pyramidColor,  shader, scale / 2, model, minHeight);
		DrawModelSerpinskiPyramid3(height / 2, (Vector3) { top.x + triangleHeight / 6, top.y - height / 2, top.z - side / 4 }, pyramidColor, shader, scale / 2, model, minHeight);
		DrawModelSerpinskiPyramid3(height / 2, (Vector3) { top.x + triangleHeight / 6, top.y - height / 2, top.z + side / 4 }, pyramidColor, shader, scale / 2, model, minHeight);
	}
	else {
		DrawModel(model, top, scale, pyramidColor);
	}
}