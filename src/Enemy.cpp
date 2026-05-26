#include "Enemy.hpp"
#include "raymath.h"
#include <cstdlib>
void Enemy::Init(Vector3 pos){
  position=pos;health=50+(rand()%100);speed=2+rand()%3;type=rand()%3;timer=0;
  target={0};model=LoadModelFromMesh(GenMeshCylinder(0.4f,1.8f,8));
}
void Enemy::Update(float dt, Vector3 playerPos){
  if(health<=0)return;
  timer+=dt;
  float dist=Vector3Distance(position,playerPos);
  if(dist<20){
    Vector3 dir=Vector3Normalize(Vector3Subtract(playerPos,position));
    position=Vector3Add(position,Vector3Scale(dir,speed*dt));
    if(dist<2){/*attack*/}
    if(timer>1&&dist<15){/*shoot*/timer=0;}
  }else if(type==0){
    position.x+=sin(timer)*dt*2;
    position.z+=cos(timer*0.7f)*dt*2;
  }
  if(position.y<0)position.y=0;
}
void Enemy::Render(){
  if(health<=0)return;
  Color c=type==0?RED:type==1?PURPLE:ORANGE;
  DrawModel(model,position,1,c);
  DrawSphere({position.x,position.y+1.8f,position.z},0.25f,c);
  // Health bar
  float hw=30.0f;
  DrawRectangle(position.x-hw/2,position.y-1,hw,4,RED);
  DrawRectangle(position.x-hw/2,position.y-1,hw*health/100,4,GREEN);
}