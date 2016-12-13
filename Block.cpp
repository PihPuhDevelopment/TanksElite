#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Block.h"
#include "Rectangle.h"
#include "Color.h"
#include <iostream>
#include <ctime>
#include <random>

Block::Block(float x, float y, float width, float height, Color c): GameObject(x, y), Rectangle(x, y, width, height), Point(x, y), color(c)
{

}

void Block::Tick()
{

}

void Block::Render()
{
	glColor3f(color.r, color.g, color.b);
	glRectf(x*SCALE, y*SCALE, (x+width)*SCALE, (y+height)*SCALE);
}

void Block::Keyboard(int key)
{

}

void Block::SpecialKeyboard(int key)
{
	
}