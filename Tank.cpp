#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include "Tank.h"
#include "Rectangle.h"
#include "Bullet.h"
#include "Controller.h"
#include "GameObject.h"
#include "Dir.h"
#include "Map.h"

Tank::Tank(): GameObject(), dir(LEFT){  }
Tank::Tank(float _x, float _y, Controller& _c): Point(_x, _y), dir(LEFT), c(&_c)
{
    collisionMaps.push_back(Map("Tank/left", 1, 2));
    collisionMaps.push_back(Map("Tank/up", 1, 2));
    collisionMaps.push_back(Map("Tank/right", 1, 2));
    collisionMaps.push_back(Map("Tank/down", 1, 2));
    y = _y;
    x = _x;
    for(Map& m : collisionMaps)
    {
        m.Translate(_x, _y);
    }
}
void Tank::Render() 
    {
        collisionMaps[dir].Render();
        /*switch(dir) 
        {
            case LEFT:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-0.4)*SCALE,(x-1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y+1-0.4)*SCALE,(x+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y-1-0.4)*SCALE,(x+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y+1-0.4)*SCALE,(x+1+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-1-0.4)*SCALE,(x+1+0.4)*SCALE,(y-1+0.4)*SCALE);
                break;
            case RIGHT:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-0.4)*SCALE,(x+1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y+1-0.4)*SCALE,(x+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y-1-0.4)*SCALE,(x+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y+1-0.4)*SCALE,(x-1+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-1-0.4)*SCALE,(x-1+0.4)*SCALE,(y-1+0.4)*SCALE);
                break;  
            case UP:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-0.4)*SCALE,(x+1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-0.4)*SCALE,(x-1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y+1-0.4)*SCALE,(x+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-1-0.4)*SCALE,(x+1+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-1-0.4)*SCALE,(x-1+0.4)*SCALE,(y-1+0.4)*SCALE);
                break;
            case DOWN:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y-1-0.4)*SCALE,(x+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-0.4)*SCALE,(x+1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-0.4)*SCALE,(x-1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y+1-0.4)*SCALE,(x+1+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y+1-0.4)*SCALE,(x-1+0.4)*SCALE,(y+1+0.4)*SCALE);
                break;
        }*/
    }

    void Tank::SpecialKeyboard(int key) 
    {
        switch(key) {
            case GLUT_KEY_UP: 
                if(dir == UP)
                {
                    restoreX = 0; restoreY = -1;
                    for(Map& m : collisionMaps)
                    {
                        m.Translate(0, 1);
                    }
                    y++;
                }
                else
                {
                    restoreX = 0; restoreY = 0;
                    prevDir = dir; 
                }
                prevDir = dir;
                dir = UP;
                break;

            case GLUT_KEY_RIGHT: 
                if(dir == RIGHT)
                {
                    restoreX = -1; restoreY = 0;
                    for(Map& m : collisionMaps)
                    {
                        m.Translate(1, 0);
                    }
                    x++;
                }
                else
                {
                    restoreX = 0; restoreY = 0;  
                }
                prevDir = dir;
                dir = RIGHT;
                break;

            case GLUT_KEY_LEFT:
                if(dir == LEFT)
                {
                    restoreX = 1; restoreY = 0;
                    for(Map& m : collisionMaps)
                    {
                        m.Translate(-1, 0);
                    } 
                    x--;
                }
                else
                {
                    restoreX = 0; restoreY = 0;
                    prevDir = dir;
                    dir = LEFT;   
                }
                prevDir = dir;
                dir = LEFT;
                break;

            case GLUT_KEY_DOWN: 
                if(dir == DOWN)
                {
                    restoreX = 0; restoreY = 1;
                    for(Map& m : collisionMaps)
                    {
                        m.Translate(0, -1);
                    }
                    y--;
                }
                else
                {
                    restoreX = 0; restoreY = 0;  
                }
                prevDir = dir;
                dir = DOWN;
                break;
        }
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
        c->AddOther(*(new Bullet(x, y, dir)));
    }

    bool Tank::Intersects(const Rectangle& r)
    {
        for(Block& b: collisionMaps[dir].GetBlocks())
        {
            //std::cout << r.GetX() << " " << r.GetY() << " " << b.GetX() << " " << b.GetY() << std::endl;
            if(b.Intersects(r))
            {
                return true;
            }
        }
        return false;
    }

    Map& Tank::GetCollisionMap()
    {
        return collisionMaps[dir];
    }

  void Tank::Tick() {
       
  }