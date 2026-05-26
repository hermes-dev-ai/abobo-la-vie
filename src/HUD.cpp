#include "HUD.hpp"
void HUD::Init(){}
void HUD::Render(int health,int money,int score,int mission,float time,bool inVehicle){
  // Mini-map
  DrawRectangle(10,10,150,150,{0,0,0,150});
  DrawRectangleLines(10,10,150,150,WHITE);
  // Health bar
  DrawRectangle(10,170,150,15,GRAY);
  DrawRectangle(10,170,health*150/100,15,health>50?GREEN:health>25?ORANGE:RED);
  DrawText(TextFormat("SANTE: %d%%",health),15,172,10,WHITE);
  // Money
  DrawText(TextFormat("$$: %d FCFA",money),10,190,15,GOLD);
  DrawText(TextFormat("SCORE: %d",score),10,210,15,RAYWHITE);
  // Time
  int min=(int)time/60;int sec=(int)time%60;
  DrawText(TextFormat("%02d:%02d",min,sec),170,10,20,RAYWHITE);
  // Controls hint
  DrawText("WASD:Marcher  F:Vehicule  ESPACE:Tirer  R:Reset",170,190,12,RAYWHITE);
  // Weapon crosshair
  DrawCircle(GetScreenWidth()/2,GetScreenHeight()/2,3,RED);
  // Mission
  DrawText(TextFormat("MISSION %d",mission),170,210,12,YELLOW);
  // Vehicle indicator
  if(inVehicle){
    DrawText("VEHICULE",GetScreenWidth()-120,10,20,RED);
    DrawCircle(GetScreenWidth()-60,30,15,RED);
  }
  // Minimap player dot
  DrawCircle(85,85,4,GREEN);
}