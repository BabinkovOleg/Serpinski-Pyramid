#include "raylib.h"
#include "functions.h"
#include "rlights.h"
#include "rlgl.h"
#include <math.h>

#define GLSL_VERSION 330

int main(void)
{
	const int screenWidth = 1800;
	const int screenHeight = 900;
	const float pyramidHeight = 100.0f;
	float minHeightOfPyramidElement = 5.0f;

	SetConfigFlags(FLAG_MSAA_4X_HINT);

	InitWindow(screenWidth, screenHeight, "Serpinski pyramid");

	Camera3D camera = { 0 };
	camera.position = (Vector3) { -40.0f, 60.0f, 200.0f };
	camera.target = (Vector3) { 0.0f, pyramidHeight / 2, 0.0f };
	camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	

	Vector3 pyramidPosition = { 0.0f, pyramidHeight, 0.0f };

	SetCameraMode(camera, CAMERA_FREE);
	int isCameraFree = 1;

	Shader shader = LoadShader(TextFormat("resources/shaders/glsl%i/base_lighting.vs", GLSL_VERSION),
		TextFormat("resources/shaders/glsl%i/lighting.fs", GLSL_VERSION));

	int ambientLoc = GetShaderLocation(shader, "ambient");
	SetShaderValue(shader, ambientLoc, (float[4]) { 0.1f, 0.1f, 0.1f, 1.0f }, SHADER_UNIFORM_VEC4);

	Light light = CreateLight(LIGHT_POINT, (Vector3) { 0, 100, 70 }, (Vector3) { 0, 0, 0 }, WHITE, shader);

	int viewEyeLoc = GetShaderLocation(shader, "viewEye");
	int viewCenterLoc = GetShaderLocation(shader, "viewCenter");
	int resolutionLoc = GetShaderLocation(shader, "resolution");

	float resolution[2] = { (float)screenWidth, (float)screenHeight };
	SetShaderValue(shader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2);

	Model pyramid = LoadModelFromMesh(GenMeshCone(pyramidHeight * sqrt((double)12 / 13) * 2 / 3, pyramidHeight, 3));
	Model plate = LoadModelFromMesh(GenMeshPlane(pyramidHeight * 30, pyramidHeight * 30, 1, 1));
	pyramid.materials[0].shader = shader;
	plate.materials[0].shader = shader;

	SetTargetFPS(144);
	
	while (!WindowShouldClose())
	{
		
		UpdateCamera(&camera);

		if (IsKeyDown(KEY_Z)) camera.target = (Vector3) { 0.0f, pyramidHeight / 2, 0.0f };
		if (IsKeyDown(KEY_RIGHT)) light.position.x += 1;
		if (IsKeyDown(KEY_LEFT)) light.position.x -= 1;
		if (IsKeyDown(KEY_UP)) light.position.z -= 1;
		if (IsKeyDown(KEY_DOWN)) light.position.z += 1;
		if (IsKeyPressed(KEY_W)) light.enabled = !light.enabled;
		if (IsKeyPressed(KEY_C)) {
			if (isCameraFree) {
				isCameraFree = 0;
				SetCameraMode(camera, CAMERA_ORBITAL);
				camera.target = (Vector3) { 0.0f, pyramidHeight / 2, 0.0f };
			}
			else {
				isCameraFree = 1;
				SetCameraMode(camera, CAMERA_FREE);
			}
		}
		
		//light.position.x = camera.position.x;
		//light.position.z = camera.position.z;

		UpdateLightValues(shader, light);

		float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
		float cameraTarget[3] = { camera.target.x, camera.target.y, camera.target.z };

		SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);

		BeginDrawing();
			ClearBackground(SKYBLUE);

			BeginMode3D(camera);

			DrawModelSerpinskiPyramid3(pyramidHeight, pyramidPosition, LIGHTGRAY, shader, 1.0f, pyramid, minHeightOfPyramidElement);
			
			DrawSphereEx(light.position, 2.0f, 8, 8, RAYWHITE);
			
			DrawModel(plate, (Vector3) { 0, 0, 0 }, 1.0f, GREEN);

			EndMode3D();

			DrawFPS(screenWidth - 100, 0);

			DrawControls();
		EndDrawing();
	}

	UnloadShader(shader);
	UnloadModel(pyramid);
	CloseWindow();
	return 0;
}