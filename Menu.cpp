#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Menu.h"
#include <iostream>

Menu::Menu(std::string _title, Controller& _c): title(_title), position(1), c(_c)
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
	glColor3ub( 0, 0, 0);
    glRectf(0,0,800,600);

	glColor3ub( 0, 222, 18);
    glRasterPos3d(WIDTH/2-title.length()*4.5, HEIGHT - 30, 0);
    glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)"TANKS ELITE");
}