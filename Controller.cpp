#include <iostream>
#include <cstdlib>
#include "Controller.h"
#include "Tank.h"
#include "Map.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "LoseMenu.h"
#include "Bot.h"

Controller::Controller(): start(false), pause(false), lose(false)
{
	score = 10;
}

void Controller::HandleBullets()
{
		auto itr = enemyBullets.begin();
		while (itr != enemyBullets.end()) 
		{				
	    	if (player->Intersects(*itr)) 
			{
	      		itr = enemyBullets.erase(itr);
	      		player->Hit();
	    	} 
	    	else 
	    	{
	      		++itr;
	    	}
  		}

		itr = playerBullets.begin();

		for(Bot& b: enemies)
		{
			while (itr != playerBullets.end()) 
			{				
				if(itr->Intersects(b.GetTank()))
				{
					b.GetTank().Hit();
					itr = playerBullets.erase(itr);
				}
	    		else 
	    		{
	      			++itr;
	    		}
  			}
		}
}

void Controller::HandleBlocks()
{
	for(Block& b: map->GetBlocks())
	{
		if(player->Intersects(b))
		{
			player->Restore();
		}

		for(Bot& bot: enemies)
		{
			if(bot.GetTank().Intersects(b))
			{
				bot.GetTank().Restore();
			}
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
			if(player->IsDead())
			{
				lose = true;
				pause = true;
				lmenu->SetScore(score);
			}
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

			HandleBullets();

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

			auto itr2 = enemies.begin();
			while (itr2 != enemies.end()) { 
				std::cout << itr2->GetTank().GetHp() << std::endl;
	    		if (itr2->GetTank().IsDead()) {
	      			itr2 = enemies.erase(itr2);
	    		} 
	    		else 
	    		{
	      			++itr2;
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
		if(lose)
		{
			lmenu->Render();
		}
		else if(!pause)
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
	lose = false;
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
	SetPlayer(new Tank(10, 10, "Tank", *this, false, 3));
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

void Controller::SetLoseMenu(LoseMenu* menu)
{
	this->lmenu = menu;
}

void Controller::AddPlayerBullet(Bullet b)
{
	playerBullets.push_back(b);
}

void Controller::AddEnemyBullet(Bullet b)
{
	enemyBullets.push_back(b);
}

void Controller::AddBot(Bot b)
{
	enemies.push_back(b);
}

void Controller::Keyboard(unsigned char key)
{
	if(start)
	{
		if(lose)
		{
			lmenu->Keyboard(key);
		}
		else
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
		if(lose)
		{
			lmenu->SpecialKeyboard(key);
		}
		else
		{
			if(pause)
				pmenu->SpecialKeyboard(key);
			else
				player->SpecialKeyboard(key);
		}
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