#pragma once
#include "raylib.h"
#include "World.hpp"
#include "Player.hpp"
#include "Vehicle.hpp"
#include "Mission.hpp"
#include "HUD.hpp"
#include "Enemy.hpp"
#include "Weapon.hpp"

class Game {
public:
  void Init();
  void Update(float dt);
  void Render();
  void Unload();

private:
  World world;
  Player player;
  Vehicle vehicle;
  Mission mission;
  HUD hud;
  std::vector<Enemy> enemies;
  std::vector<Weapon> weapons;
  Camera3D camera;
  float gameTime;
  int score;
  int health;
  int money;
  bool inVehicle;
  int currentMission;

  void InitCamera();
  void UpdateCamera(float dt);
  void SpawnEnemies();
  void CheckCollisions();
  void ProcessInput(float dt);
};