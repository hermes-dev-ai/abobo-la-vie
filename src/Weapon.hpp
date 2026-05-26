#pragma once
#include "raylib.h"
class Weapon {
public:
  void Init(Vector3 pos, Vector3 dir, int dmg);
  void Update(float dt);
  void Render();
  bool IsActive() const { return active; }
  void Deactivate() { active = false; }
  Vector3 GetPosition() const { return position; }
  int GetDamage() const { return damage; }
private:
  Vector3 position, velocity;
  int damage;
  bool active;
  float lifetime;
};