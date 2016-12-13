/*
Класс хранит все объекты игры и отвечает за их обновление и взаимодействие.
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "GameObject.h"
#include "Tank.h"
#include "Map.h"
#include "Bullet.h"
#include "Menu.h"
#include <vector>

class Tank;
class Menu;

class Controller
{	
public:
	Controller();
	void Tick();
	void Render();
	void NewGame();
	void ResetGame();
	void AddPlayerBullet(Bullet b);
	void SetPlayer(Tank* p);
	void SetMap(Map* m);
	void SetMenu(Menu* m);
	void Keyboard(unsigned char key);
	void SpecialKeyboard(int k);
private:
	void HandleBlocks();
	bool pause;
	std::vector<Bullet> playerBullets;
	Menu* menu;
	Tank* player;
	Map* map;
};
#endif