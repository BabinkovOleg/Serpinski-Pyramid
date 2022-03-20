#include "raylib.h"
#include "functions.h"

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

	Camera3D camera = { 0 };
	camera.position = (Vector3) { 40.0f, 40.0f, 40.0f };
	camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	//Set

	Vector3 cubePosition = { 0.0f, 20.0f, 20.0f };

	SetCameraMode(camera, CAMERA_FREE);

	SetTargetFPS(144);
	
	while (!WindowShouldClose())
	{
		
		UpdateCamera(&camera);

		if (IsKeyDown('Z')) camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
		
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);

		DrawCylinder((Vector3) { 0.0f, 0.0f, 0.0f }, 0.0f, 4.0f, 3.0f, 3, GOLD);
		DrawCylinderWires((Vector3) { 0.0f, 0.0f, 0.0f }, 0.0f, 4.0f, 3.0f, 3, PINK);

		//DrawTriangle3D((Vector3) { 100, 0, 0 }, (Vector3) { 0, 100, 0 }, (Vector3) { 0, 0, 100 }, RED);
		//DrawTriangle3D(cubePosition, (Vector3) { 100, 0, 0 }, (Vector3) { 0, 0, 100 }, RED);
		//DrawTriangle3D(cubePosition, (Vector3) { 100, 0, 0 }, (Vector3) { 0, 100, 0 }, RED);
		//DrawTriangle3D(cubePosition, (Vector3) { 0, 100, 0 }, (Vector3) { 0, 0, 100 }, RED);

		//DrawCube(cubePosition, 20.0f, 20.0f, 20.0f, RED);
		//DrawCubeWires(cubePosition, 20.0f, 20.0f, 20.0f, MAROON);
		//DrawSphere(cubePosition, 15.0f, BLUE);
		//DrawSphereWires(cubePosition, 15.0f, 50, 50, MAROON);

		DrawGrid(100, 1.0f);

		EndMode3D();

		DrawControls();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}