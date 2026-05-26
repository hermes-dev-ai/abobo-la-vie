#pragma once
#include "raylib.h"
class Enemy {
public:
  void Init(Vector3 pos);
  void Update(float dt, Vector3 playerPos);
  void Render();
  Vector3 GetPosition() const { return position; }
  void TakeDamage(int dmg) { health -= dmg; }
  bool IsDead() const { return health <= 0; }
private:
  Vector3 position, target;
  int health, type;
  float speed, timer;
  Model model;
};