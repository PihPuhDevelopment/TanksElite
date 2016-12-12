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
	for (int i=0; i<other.size(); ++i) 
	{
		other[i]->Tick();
	}
	int i = 0;
	for(Block& b: map->GetBlocks())
	{
		if(player->Intersects(b))
		{
			player->Restore();
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
		for (int i=0; i<other.size(); ++i) 
		{
			other[i]->Render();
		}
	}
}

void Controller::AddLevelMapItem(GameObject& item)
{
	levelMap.push_back(&item);
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

void Controller::AddOther(GameObject& o)
{
	other.push_back(&o);
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

