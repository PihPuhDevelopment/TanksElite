#ifndef BLOCK_H
#define BLOCK_H
#include "GameObject.h"
#include "Rectangle.h"
#include "Color.h"

extern const int SCALE;

class Block : public GameObject, public Rectangle
{
public:
	Block(float, float, float, float, Color);
	void Tick();
	void Render();
	void Keyboard(int);
	void SpecialKeyboard(int);
private:
	Color color;
};
#endif