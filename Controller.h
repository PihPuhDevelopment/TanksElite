
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "GameObject.h"
#include "Tank.h"
#include "Map.h"
#include "Bullet.h"
#include <vector>

class Tank;
class Menu;
class PauseMenu;
class Bot;

class Controller
{	
public:
	Controller();
	void Tick();
	void Render();
	void NewGame();
	void Continue();
	void StopGame();
	void ResetGame();
	void AddPlayerBullet(Bullet b);
	void AddEnemyBullet(Bullet b);
	void SetPlayer(Tank* p);
	void SetMap(Map* m);
	void SetMenu(Menu* m);
	void SetPauseMenu(PauseMenu* m);
	void Keyboard(unsigned char key);
	void SpecialKeyboard(int k);
	~Controller();
private:
	void HandleBlocks();
	std::vector<Bullet> playerBullets;
    std::vector<Bullet> enemyBullets;
	std::vector<Bot> enemies;

	Menu* menu;
	PauseMenu* pmenu;
	Tank* player;
	Map* map;

	bool pause;
	bool start;
};
#endif
