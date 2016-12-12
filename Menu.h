#ifndef MENU_H
#define MENU_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Controller.h"

class Controller;

class Menu 
{
private:
	int position;
	Controller& c;
public:
	Menu(Controller&);
	void Render();
	void Keyboard(int);
	void SpecialKeyboard(int key);
};
#endif
