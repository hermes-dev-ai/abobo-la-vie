#pragma once
#include "raylib.h"
class HUD {
public:
  void Init();
  void Render(int health, int money, int score, int mission, float time, bool inVehicle);
};