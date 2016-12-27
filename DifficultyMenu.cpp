#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include "DifficultyMenu.h"
#include "MenuBase.h"

DifficultyMenu::DifficultyMenu(std::string _title, Controller* _c): MenuBase(_title, _c)
{
	items.push_back("EASY");
    items.push_back("NORMAL");
    items.push_back("HARD");
    items.push_back("CHE KAVO SUKI !&!&&!&");
    items.push_back("TO MENU");
}

void DifficultyMenu::SelectMenuItem(int pos)
{
	switch(pos)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			c->SetDifficulty(pos);
			c->SwitchDiffMenu();
			c->StopGame();
			break;
		case 4:
			c->SwitchDiffMenu();
			c->StopGame();
			break;
	}
}