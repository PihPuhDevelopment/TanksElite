#ifndef BLOCK_H
#define BLOCK_H
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

class Menu 
{
	private:
	int position;
	Controller& c;
public:
	Menu();
	void Render();
	void SpecialKeyboard(int key);
};
#endif
