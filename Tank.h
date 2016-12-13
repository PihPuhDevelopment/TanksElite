#ifndef TANK_H
#define TANK_H
#include <vector>
#include <chrono>
#include "Rectangle.h"
#include "Controller.h"
#include "GameObject.h"
#include "Dir.h"
#include "Map.h"

class Controller;

extern const int SCALE;

class Tank: public GameObject, public Rectangle
{
public:
    Tank();
    Tank(float _x, float _y, Controller& _c);
    Map& GetCollisionMap();
    void Render();
    void SpecialKeyboard(int key);
    void Keyboard(int key);
    void Restore();
    void Shoot();
    void Tick();

 private:
  void Move(Direction d, float dx, float dy);
  const double STEP_TIME = 0.1;
  float restoreX, restoreY;
  Direction prevDir;
  Direction dir;
  Controller* c;
  std::vector<Map> collisionMaps;
  std::chrono::high_resolution_clock::time_point prevStepTime;
}; 
#endif