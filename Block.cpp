#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Block.h"
#include "Rectangle.h"
#include <iostream>
#include <ctime>
#include <random>

Block::Block(float x, float y, float width, float height): GameObject(x, y), Rectangle(x, y, width, height), Point(x, y)
{
	//std::cout << "Ama Block! " << (x-width/2)*SCALE << " " << (y-height/2)*SCALE << " " << (x+width/2)*SCALE << " " << (y+height/2)*SCALE << " " << std::endl;
	id = rand();
}

void Block::Tick()
{
		//std::cout << id << x << " " << y << " " << width << " " << height << " " << std::endl;
}

void Block::Render()
{
	glColor3f(0.2f, 0.5f, 0.5f);
	glRectf((x-width/2)*SCALE, (y-height/2)*SCALE, (x+width/2)*SCALE, (y+height/2)*SCALE);
}

void Block::Keyboard(int key)
{

}

void Block::SpecialKeyboard(int key)
{
	
}