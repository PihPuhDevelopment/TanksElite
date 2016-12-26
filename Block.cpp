#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Block.h"
#include "Rectangle.h"
#include "Color.h"
#include <iostream>
#include <ctime>
#include <random>

Block::Block(float x, float y, float width, float height, Color c, bool destr, int _hp): GameObject(x, y), 
									Rectangle(x, y, width, height),  Point(x, y), color(c), destructible(destr), hp(_hp)
{

}

void Block::Tick()
{
	
}

void Block::Render()
{
	glColor3ub(color.r, color.g, color.b);
	color.r = (color.r+rand()%40)%255;
	color.g = (color.g+rand()%40)%255;
	color.b = (color.b+rand()%40)%255;
	glRectf(x*SCALE, y*SCALE, (x+width)*SCALE, (y+height)*SCALE);
}

void Block::Keyboard(int key)
{

}

void Block::SpecialKeyboard(int key)
{
	
}

bool Block::IsDestructible() const
{
	return destructible;
}

int Block::GetHp() const
{
	return hp;
}

void Block::SetHp(int _hp)
{
	hp = _hp;
}