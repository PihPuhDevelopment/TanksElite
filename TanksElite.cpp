#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "GameObject.h"
#include "Controller.h"
#include "Tank.h"

const int DELAY = 30;
const int WIDTH = 800, HEIGHT = 600;
const int SCALE = 10;

Controller c;

void Render() {
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
    glRectf(3*SCALE, 3*SCALE, 3.8f*SCALE, 3.8f*SCALE);
	c.Render();
}

void Tick(int = 0)
{
	c.Tick();
	Render();
	glutTimerFunc(DELAY, Tick, 0);
}

void Keyboard(unsigned char key, int a, int b)
{
	c.Keyboard(key);
}

void SpecialK(int key, int a, int b)
{
	c.SpecialKeyboard(key);
}

int main(int argc, char** argv)
{
	c.SetPlayer(new Tank(10, 10, c));
    c.SetMap(new Map("map", 0, 1));
    c.SetMenu(new Menu(c));
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("TanksElite");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glutDisplayFunc(Render);
    glutTimerFunc(DELAY, Tick, 0);
    glutSpecialFunc(SpecialK);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
}