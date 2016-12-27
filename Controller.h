
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
class LoseMenu;
class DifficultyMenu;
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
	void SwitchDiffMenu();
	void AddPlayerBullet(Bullet b);
	void AddEnemyBullet(Bullet b);
	void SetPlayer(Tank* p);
	void SetMap(Map* m);
	void SetMenu(Menu* m);
	void SetPauseMenu(PauseMenu* m);
	void SetLoseMenu(LoseMenu* m);
	void SetDifficultyMenu(DifficultyMenu* m);
	void SetDifficulty(int);
	void AddBot(Bot b);
	void Keyboard(unsigned char key);
	void SpecialKeyboard(int k);
	void RenderScore();
	~Controller();
private:
	void HandleBlocks();
	void HandleEnemies();
	void HandleBullets();
	bool CollidesBlocks(const Rectangle& r);
	int score;
	int startBotNumber;
	int difficulty;
	std::vector<Bullet> playerBullets;
    std::vector<Bullet> enemyBullets;
	std::vector<Bot> enemies;

	Menu* menu;
	PauseMenu* pmenu;
	LoseMenu* lmenu;
	DifficultyMenu* dmenu;
	Tank* player;
	Map* map;

	bool pause;
	bool start;
	bool lose;
	bool inDiff;
};
#endif
