#ifndef TANK_H
#define TANK_H
#include <vector>
#include "Rectangle.h"
#include "Controller.h"
#include "GameObject.h"
#include "Dir.h"
#include "Map.h"

class Controller;

const int SCALE = 20;

class Tank: public GameObject
{
public:
    Tank();
    Tank(float _x, float _y, Controller& _c);
    Map& GetCollisionMap();
    bool Intersects(const Rectangle& r);
    void Render();
    void SpecialKeyboard(int key);
    void Keyboard(int key);
    void Restore();
    void Shoot();
    void Tick();

 private:
  float x, y;
  float restoreX, restoreY;
  Direction prevDir;
  Direction dir;
  Controller* c;
  std::vector<Map> collisionMaps;
}; 
#endif