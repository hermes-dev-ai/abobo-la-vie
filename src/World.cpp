#include "World.hpp"
#include <cstdlib>

void World::Init() {
  GenerateCity();
  groundModel = LoadModelFromMesh(GenMeshPlane(500, 500, 1, 1));
}

void World::GenerateCity() {
  // Generate roads in grid pattern
  for (int i = -5; i <= 5; i++) {
    roads.push_back({{(float)i*20, 0, -120}, {(float)i*20, 0, 120}, 6});
    roads.push_back({{-120, 0, (float)i*20}, {120, 0, (float)i*20}, 6});
  }

  // Generate buildings in city blocks
  for (int bx = -4; bx <= 4; bx++) {
    for (int bz = -4; bz <= 4; bz++) {
      if (rand() % 100 < 70) { // 70% fill rate
        float w = 5 + (rand() % 8);
        float d = 5 + (rand() % 8);
        float h = 5 + (rand() % 25);
        GenerateBuilding(bx * 20, bz * 20, w, d, h);
      }
    }
  }

  // Add trees along roads
  for (int i = -5; i <= 5; i += 2) {
    trees.push_back({(float)i*20 + 12, 0, (float)(rand()%100-50), 2 + (rand()%3)*0.5f});
    trees.push_back({(float)i*20 - 12, 0, (float)(rand()%100-50), 2 + (rand()%3)*0.5f});
  }

  // Street lights
  for (int i = -4; i <= 4; i++) {
    lights.push_back({(float)i*20+8, 0, -100, true});
    lights.push_back({(float)i*20-8, 0, -100, true});
  }
}

void World::GenerateBuilding(float x, float z, float w, float d, float h) {
  Building b;
  Vector3 pos = {x, h/2, z};
  b.bounds = {
    {pos.x - w/2, 0, pos.z - d/2},
    {pos.x + w/2, h, pos.z + d/2}
  };
  // Color based on height (slum-like diverse colors)
  int r = 100 + rand() % 155;
  int g = 80 + rand() % 120;
  int bl = 60 + rand() % 100;
  b.color = { (unsigned char)r, (unsigned char)g, (unsigned char)bl, 255 };
  b.floors = (int)(h / 3);
  buildings.push_back(b);
  buildingBoxes.push_back(b.bounds);
}

void World::Render() {
  DrawModel(groundModel, {-250, -0.5, -250}, 1, DARKGRAY);
  RenderRoads();
  RenderBuildings();
  RenderTrees();
  RenderLights();
}

void World::RenderRoads() {
  for (auto& r : roads) {
    DrawCubeV(Vector3Scale(Vector3Add(r.start, r.end), 0.5f),
              {r.width, 0.2f, Vector3Distance(r.start, r.end)}, GRAY);
  }
}

void World::RenderBuildings() {
  for (auto& b : buildings) {
    Vector3 center = {
      (b.bounds.min.x + b.bounds.max.x) / 2,
      (b.bounds.min.y + b.bounds.max.y) / 2,
      (b.bounds.min.z + b.bounds.max.z) / 2
    };
    Vector3 size = {
      b.bounds.max.x - b.bounds.min.x,
      b.bounds.max.y - b.bounds.min.y,
      b.bounds.max.z - b.bounds.min.z
    };
    DrawCubeV(center, size, b.color);
    DrawCubeWiresV(center, size, ColorBrightness(b.color, -0.3f));
    // Windows
    for (int f = 0; f < b.floors; f++) {
      float fy = 1.5f + f * 3;
      for (int wi = 0; wi < 3; wi++) {
        float wx = center.x - size.x/3 + wi * size.x/3;
        if(wx>center.x-size.x/2&&wx<center.x+size.x/2)
          DrawCube({wx, fy, center.z + size.z/2 + 0.1f}, 1.2f, 1.8f, 0.1f, (rand()%100<60)?YELLOW:BLACK);
        DrawCube({wx, fy, center.z - size.z/2 - 0.1f}, 1.2f, 1.8f, 0.1f, (rand()%100<60)?YELLOW:BLACK);
      }
    }
  }
}

void World::RenderTrees() {
  for (auto& t : trees) {
    DrawCylinder(t.pos, 0.2f, 0.3f, 2, 8, BROWN);
    DrawSphere({t.pos.x, t.pos.y + 2 + t.size, t.pos.z}, t.size, GREEN);
  }
}

void World::RenderLights() {
  for (auto& l : lights) {
    DrawCylinder(l.pos, 0.15f, 0.15f, 4, 6, DARKGRAY);
    DrawSphere({l.pos.x, l.pos.y + 4.5f, l.pos.z}, 0.3f, l.on ? YELLOW : DARKGRAY);
    if (l.on) DrawLight(GEN_LIGHT_SPOT, {l.pos.x, l.pos.y + 4, l.pos.z}, {0,-1,0}, YELLOW);
  }
}

void World::Unload() {
  UnloadModel(groundModel);
}