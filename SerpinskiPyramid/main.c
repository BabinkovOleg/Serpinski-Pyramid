#include "raylib.h"
#include "functions.h"
#include <math.h>

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	const float pyramidHeight = 100.0f;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

	Camera3D camera = { 0 };
	camera.position = (Vector3) { 40.0f, 40.0f, 40.0f };
	camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;


	Vector3 pyramidPosition = { 0.0f, pyramidHeight / 2, 0.0f };

	SetCameraMode(camera, CAMERA_FREE);

	SetTargetFPS(144);
	
	while (!WindowShouldClose())
	{
		
		UpdateCamera(&camera);

		if (IsKeyDown('Z')) camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
		
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);
		
		DrawSerpinskiPyramid3(pyramidHeight, pyramidPosition, RED, BLUE);

		EndMode3D();

		DrawControls();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}