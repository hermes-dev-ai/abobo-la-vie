#pragma once
#include "raylib.h"
#include "raymath.h"

class Player {
public:
  void Init(Vector3 pos);
  void Update(float dt);
  void Render();
  void Unload();
  Vector3 GetPosition() const { return position; }
  void SetPosition(Vector3 pos) { position = pos; }
  float GetAngle() const { return angle; }
  Vector3 GetForward() const;
  BoundingBox GetBBox() const;

private:
  Vector3 position;
  Vector3 velocity;
  float angle, pitch;
  float speed;
  Model model;
  void HandleInput(float dt);
};