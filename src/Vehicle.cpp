#include "Vehicle.hpp"
#include "raymath.h"
void Vehicle::Init(Vector3 pos){position=pos;velocity={0};angle=0;speed=0;steer=0;
  model=LoadModelFromMesh(GenMeshCube(2,1,4));}
void Vehicle::Update(float dt){
  HandleInput(dt);
  Matrix rot=MatrixRotateY(angle);
  Vector3 forward={rot.m8,0,rot.m10};
  velocity=Vector3Add(velocity,Vector3Scale(forward,speed*dt));
  velocity=Vector3Scale(velocity,0.95f);
  position=Vector3Add(position,velocity);
  angle+=steer*speed*dt*0.01f;
  if(position.y<0)position.y=0;
}
void Vehicle::HandleInput(float dt){
  if(IsKeyDown(KEY_UP))speed=MathClamp(speed+20*dt,-30,60);
  else if(IsKeyDown(KEY_DOWN))speed=MathClamp(speed-30*dt,-30,60);
  else speed=MathClamp(speed*0.98f,-5,5);
  if(IsKeyDown(KEY_LEFT))steer=-1;else if(IsKeyDown(KEY_RIGHT))steer=1;else steer=0;
}
void Vehicle::Render(){
  Matrix rot=MatrixRotateY(angle);
  Matrix trans=MatrixTranslate(position.x,position.y+0.5f,position.z);
  DrawMesh(model.meshes[0],model.materials[0],MatrixMultiply(rot,trans));
  DrawSphere({position.x,position.y+0.8f,position.z-2},0.5f,RED);
  DrawSphere({position.x,position.y+0.8f,position.z+2},0.5f,RED);
}
void Vehicle::Unload(){UnloadModel(model);}