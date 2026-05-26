#pragma once
#include "raylib.h"
#include <string>
class Mission {
public:
  void Init(int id);
  void Complete(){active=false;}
  bool IsActive()const{return active;}
  Vector3 GetTarget()const{return target;}
  int GetReward()const{return reward;}
  void RenderUI();
private:
  int id,reward;
  Vector3 target;
  bool active;
  std::string title,desc;
};