#pragma once
#include "raylib.h"
class Vehicle {
public:
  void Init(Vector3 pos);
  void Update(float dt);
  void Render();
  void Unload();
  Vector3 GetPosition() const { return position; }
private:
  Vector3 position, velocity;
  float angle, speed, steer;
  Model model;
  void HandleInput(float dt);
};