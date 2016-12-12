/*
Класс хранит все объекты игры и отвечает за их обновление и взаимодействие.
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "GameObject.h"
#include "Tank.h"
#include "Map.h"
#include <vector>

class Tank;

class Controller
{	
public:
	void Tick();
	void Render();
	void AddLevelMapItem(GameObject& item);
	void AddEnemy(GameObject& enemy);
	void AddOther(GameObject& other);
	void SetPlayer(Tank* p);
	void SetMap(Map* m);
	void Keyboard(unsigned char key);
	void SpecialKeyboard(int k);
private:
	std::vector<GameObject*> levelMap;
	std::vector<GameObject*> enemies;
	std::vector<GameObject*> other;
	Tank* player;
	Map* map;
};
#endif