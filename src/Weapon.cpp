#include "Weapon.hpp"
void Weapon::Init(Vector3 pos,Vector3 dir,int dmg){
  position=pos;velocity=Vector3Scale(dir,40);damage=dmg;active=true;lifetime=3;
}
void Weapon::Update(float dt){
  if(!active)return;
  position=Vector3Add(position,Vector3Scale(velocity,dt));
  lifetime-=dt;
  if(lifetime<=0)active=false;
}
void Weapon::Render(){
  if(!active)return;
  DrawSphere(position,0.15f,YELLOW);
  DrawPoint3D(position,YELLOW);
}