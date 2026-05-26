#include "Mission.hpp"
#include <cstdlib>
void Mission::Init(int id){
  this->id=id;active=true;reward=100+id*50;
  const char* targets[][3]={{"Abobo Gare","Aller a la gare d'Abobo",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Marche d'Abobo","Trouver le marche central",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Pharmacie","Recuperer des medicaments",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Mairie","Payer les impots",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Gbinta","Visiter le quartier Gbinta",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"PKK","Aller au camp militaire",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Yopougon","Traverser vers Yopougon",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Banco","Explorer la foret du Banco",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Plateau","Aller au centre ville",{(float)(rand()%100-50),0,(float)(rand()%100-50)}},
  {"Cocody","MISSION FINALE - Cocody",{(float)(rand()%100-50),0,(float)(rand()%100-50)}}};
  int idx=(id-1)%10;
  title=targets[idx][0];desc=targets[idx][1];target={targets[idx][2][0],0,targets[idx][2][2]};
}
void Mission::RenderUI(){
  if(active){
    DrawText(TextFormat("Mission: %s",title.c_str()),10,40,20,RAYWHITE);
    DrawText(TextFormat("Objectif: %s",desc.c_str()),10,65,15,RAYWHITE);
    DrawText(TextFormat("Recompense: %d FCFA",reward),10,85,15,GOLD);
  }
}