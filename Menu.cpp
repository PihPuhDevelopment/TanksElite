#include "Menu.h"

Menu::Menu(Controller& _c): position(1), c(_c)
{

}

void Menu::Keyboard(int key)
{

}

void Menu::SpecialKeyboard(int key) 
{
      
}

void Menu::Render()
{
	glColor3ub( 25, 0, 125);
    glRectf(0,0,600,800);
}