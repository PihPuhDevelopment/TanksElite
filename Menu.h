#ifndef MENU_H
#define MENU_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Controller.h"
#include <string>

class Controller;

extern const int WIDTH;
extern const int HEIGHT;

class Menu 
{
public:
	Menu(std::string title, Controller&);
	void Render();
	void Keyboard(int);
	void SpecialKeyboard(int key);
private:
	std::string title;
	int position;
	Controller& c;
	std::vector<std::string> items;
};
#endif
