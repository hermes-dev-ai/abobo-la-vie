#include "raylib.h"
#include "raymath.h"
#include "Game.hpp"

int main() {
  const int screenWidth = 1920;
  const int screenHeight = 1080;

  SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "ABOBO LA VIE - Open World Action");
  InitAudioDevice();
  SetTargetFPS(60);
  SetCameraMode(CAMERA_FREE);
  DisableCursor();

  Game game;
  game.Init();

  while (!WindowShouldClose()) {
    game.Update(GetFrameTime());
    BeginDrawing();
    ClearBackground(SKYBLUE);
    game.Render();
    EndDrawing();
  }

  game.Unload();
  CloseAudioDevice();
  CloseWindow();
  return 0;
}