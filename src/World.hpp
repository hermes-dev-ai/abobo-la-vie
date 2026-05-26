#pragma once
#include "raylib.h"
#include <vector>
#include <string>

struct Building {
  BoundingBox bounds;
  Color color;
  int floors;
};

struct Road {
  Vector3 start, end;
  float width;
};

struct Tree {
  Vector3 pos;
  float size;
};

struct StreetLight {
  Vector3 pos;
  bool on;
};

class World {
public:
  void Init();
  void Render();
  void Unload();
  std::vector<BoundingBox>& GetBuildings() { return buildingBoxes; }

private:
  std::vector<Building> buildings;
  std::vector<BoundingBox> buildingBoxes;
  std::vector<Road> roads;
  std::vector<Tree> trees;
  std::vector<StreetLight> lights;
  Model groundModel;
  Texture2D roadTex, buildingTex;
  void GenerateCity();
  void GenerateBuilding(float x, float z, float w, float d, float h);
  void RenderRoads();
  void RenderBuildings();
  void RenderTrees();
  void RenderLights();
};