#include <iostream>
#include <cstdlib>
#include "Controller.h"
#include "Tank.h"
#include "Map.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "Bot.h"

Controller::Controller(): start(false), pause(false)
{

}

void Controller::HandleBlocks()
{
	for(Block& b: map->GetBlocks())
	{
		if(player->Intersects(b))
		{
			player->Restore();
		}

		auto itr = playerBullets.begin();
		while (itr != playerBullets.end()) 
		{
    		if (itr->Intersects(b)) 
			{
      			itr = playerBullets.erase(itr);
      			if(b.IsDestructible())
				{
      				b.SetHp(b.GetHp()-1);
      			}
    		}	 
    		else 
    		{
      			++itr;
    		}
  		}
		itr = enemyBullets.begin();
		while (itr != enemyBullets.end()) 
		{
	    	if (itr->Intersects(b)) 
			{
	      		itr = enemyBullets.erase(itr);
	      		if(b.IsDestructible())
				{
	      			b.SetHp(b.GetHp()-1);
	      		}
	    	} 
	    	else 
	    	{
	      		++itr;
	    	}
  		}
	}
}

void Controller::Tick()
{
	if(start)
	{
		if(!pause)
		{
			player->Tick();
			map->Tick();

			for (Bullet& bul: playerBullets) 
			{
				bul.Tick();
			}

			for (Bullet& bul: enemyBullets) 
			{
				bul.Tick();
			}

			HandleBlocks();

			int i = 0;
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

			  for(Bot& b: enemies)
			  {
				  b.Tick();
			  }
		}
	}
}

void Controller::Render()
{
	if(!start)
		menu->Render();
	else
	{
		if(!pause)
		{
			player->Render();

			map->Render();

			for (Bullet& b: playerBullets) 
			{
				b.Render();
			}

			for (Bullet& b: enemyBullets) 
			{
				b.Render();
			}

			for(Bot& b: enemies)
			{
				b.Render();
			}
		}
		else
		{
			pmenu->Render();
		}
	}
	
}

void Controller::NewGame()
{
	ResetGame();
	pause = false;
	start = true;
}

void Controller::Continue()
{
	pause = !pause;
}

void Controller::StopGame()
{
	pause = false;
	start = false;
}

void Controller::ResetGame()
{
	delete map;
	delete player;
	SetPlayer(new Tank(10, 10, "Tank", *this, false));
   	SetMap(new Map("map", 0, 1));
	playerBullets.clear();
	enemyBullets.clear();
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

void Controller::SetPauseMenu(PauseMenu* menu)
{
	pmenu = menu;
}

void Controller::AddPlayerBullet(Bullet b)
{
	playerBullets.push_back(b);
}

void Controller::AddEnemyBullet(Bullet b)
{
	enemyBullets.push_back(b);
}

void Controller::Keyboard(unsigned char key)
{
	if(start)
	{
		switch(key) {
		case 27:
			pause = !pause;
			break;
  		}
		if(pause)
			pmenu->Keyboard(key);
		else
			player->Keyboard(key);
	}
	else
	{
		menu->Keyboard(key);
	}
}
void Controller::SpecialKeyboard(int key)
{
	if(start)
	{
		if(pause)
			pmenu->SpecialKeyboard(key);
		else
			player->SpecialKeyboard(key);
	}
	else
	{
		menu->SpecialKeyboard(key);
	}
}

Controller::~Controller()
{
	delete menu;
	delete pmenu;
	delete player;
	delete map;
}