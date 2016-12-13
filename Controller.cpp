#include "Controller.h"
#include "Tank.h"
#include "Map.h"
#include "Menu.h"
#include <iostream>

Controller::Controller():Pause(true)
{

}
void Controller::Tick()
{
	player->Tick();
	map->Tick();
	for (Bullet& bul: playerBullets) 
	{
		bul.Tick();
	}
	int i = 0;
	for(Block& b: map->GetBlocks())
	{
		if(player->Intersects(b))
		{
			player->Restore();
		}

		auto itr = playerBullets.begin();
		while (itr != playerBullets.end()) {
    		if (itr->Intersects(b)) {
      			itr = playerBullets.erase(itr);
      			if(b.IsDestructible()){
      				b.SetHp(b.GetHp()-1);
      			}
    		} 
    		else 
    		{
      			++itr;
    		}
  		}
	}
	auto itr = map->GetBlocks().begin();
	while (itr != map->GetBlocks().end()) {
    	if (itr->IsDestructible() && itr->GetHp() <= 0) {
      		itr = map->GetBlocks().erase(itr);
    	} 
    	else 
    	{
      		++itr;
    	}
  	}

}

void Controller::Render()
{
	if(Pause)
		menu->Render();
	else
	{
		player->Render();
		map->Render();
		for (Bullet& b: playerBullets) 
		{
			b.Render();
		}
	}
}

void Controller::AddEnemy(GameObject& enemy)
{
	enemies.push_back(&enemy);
}

void Controller::SetPlayer(Tank* player)
{
	this->player = player;
}

void Controller::SetMap(Map* map)
{
	this->map = map;
}

void Controller::SetMenu(Menu* menu)
{
	this->menu = menu;
}

void Controller::AddPlayerBullet(Bullet b)
{
	playerBullets.push_back(b);
}
void Controller::Keyboard(unsigned char key)
{
	switch(key) {
       case 27:
      Pause = !Pause;
      break;
  }
	if(Pause)
		menu->Keyboard(key);
	else
		player->Keyboard(key);
}
void Controller::SpecialKeyboard(int key)
{
	if(Pause)
		menu->SpecialKeyboard(key);
	else
		player->SpecialKeyboard(key);
}

