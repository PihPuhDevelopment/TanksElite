#include "Menu.h"

Menu::Menu(Controller& _c): position(1), c(_c)
{}
void Menu::SpecialKeyboard(int key) 
    {
        switch(key) {
	  case 27:
	  	c.Pause = C.Pause + 1;
      case GLUT_KEY_UP: 
        break;
      case GLUT_KEY_RIGHT: 
        break;
      case GLUT_KEY_LEFT: 
        break;
      case GLUT_KEY_DOWN: 
        break;
        }
    }
void Menu::Render()
{
	glColor3ub( 25, 0, 125);
    glRectf(0,0,600,800);
}