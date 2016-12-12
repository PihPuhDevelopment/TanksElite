#ifndef BLOCK_H
#define BLOCK_H
#include "GameObject.h"
#include "Rectangle.h"

extern const int SCALE;

class Block : public GameObject, public Rectangle
{
public:
	Block(float, float, float, float);
	void Tick();
	void Render();
	void Keyboard(int);
	void SpecialKeyboard(int);
private:
	int id;
};
#endif