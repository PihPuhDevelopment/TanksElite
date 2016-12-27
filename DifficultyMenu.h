#ifndef DIFFICULTYMENU_H
#define DIFFICULTYMENU_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>
#include "Controller.h"
#include "MenuBase.h"

class Controller;

extern const int WIDTH;
extern const int HEIGHT;

class DifficultyMenu : public MenuBase
{
public:
	DifficultyMenu(std::string title, Controller* c);
private:
	std::string originalTitle;
	void SelectMenuItem(int);
};
#endif
