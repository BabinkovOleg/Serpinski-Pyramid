#include "raylib.h"
#include "functions.h"

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

void DrawSerpinskiPyramid(float side, Vector3 top) {
	if (side >= 10) {
		DrawSerpinskiPyramid(side / 2, (Vector3) { top.x, top.y, top.z });
		DrawSerpinskiPyramid(side / 2, (Vector3) { top.x, top.y, top.z });
		DrawSerpinskiPyramid(side / 2, (Vector3) { top.x, top.y, top.z });
		DrawSerpinskiPyramid(side / 2, (Vector3) { top.x, top.y, top.z });
		DrawSerpinskiPyramid(side / 2, (Vector3) { top.x, top.y, top.z });
	}
}