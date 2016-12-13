#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <chrono>
#include "Tank.h"
#include "Rectangle.h"
#include "Bullet.h"
#include "Controller.h"
#include "GameObject.h"
#include "Dir.h"
#include "Map.h"

Tank::Tank(): GameObject(), dir(LEFT){  }
Tank::Tank(float _x, float _y, Controller& _c): Rectangle(_x, _y, 2, 2), Point(_x, _y), dir(LEFT), c(&_c)
{
    collisionMaps.push_back(Map("Tank/left", 0, 1));
    collisionMaps.push_back(Map("Tank/up", 0, 1));
    collisionMaps.push_back(Map("Tank/right", 0, 1));
    collisionMaps.push_back(Map("Tank/down", 0, 1));
    
    x = _x;
    y = _y;

    for(Map& m : collisionMaps)
    {
        m.Translate(_x, _y);
    }
    prevStepTime = std::chrono::high_resolution_clock::now();
}
void Tank::Render() 
{
	collisionMaps[dir].Render();
}

void Tank::Move(Direction d, float dx, float dy)
{
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dur = std::chrono::duration_cast<std::chrono::duration<double>>(now - prevStepTime);
    double seconds = dur.count();

	if(d == dir)
	{
		if(seconds >= STEP_TIME)
		{
			prevStepTime = std::chrono::high_resolution_clock::now();
			restoreX = -dx;
			restoreY = -dy;
			for(Map& m : collisionMaps)
        	{
        	    m.Translate(dx, dy);
        	}
        	x += dx;
        	y += dy;
    	}	
	}
	else
	{
		dir = d;
	}
}

    void Tank::SpecialKeyboard(int key) 
    {
        	switch(key) {
            case GLUT_KEY_UP: 
                Move(UP, 0, 1);
                break;

            case GLUT_KEY_RIGHT: 
                Move(RIGHT, 1, 0);
                break;

            case GLUT_KEY_LEFT:
                Move(LEFT, -1, 0);
                break;

            case GLUT_KEY_DOWN: 
                Move(DOWN, 0, -1);
                break;
        }
        //std::cout << GameObject::Point::x << " " << GameObject::Point::y << std::endl;
    }

    void Tank::Keyboard(int key)
    {
        switch(key)
        {
            case 32:
                Shoot();
                break;
        }
    }

    void Tank::Restore()
    {
        x += restoreX;
        y += restoreY;
        dir = prevDir;
        for(Map& m : collisionMaps)
            {
                m.Translate(restoreX, restoreY);
            }
    }

    void Tank::Shoot() 
    {
        c->AddOther(*(new Bullet(x+1, y+1, dir)));
    }

    Map& Tank::GetCollisionMap()
    {
        return collisionMaps[dir];
    }

  void Tank::Tick() {
       
  }