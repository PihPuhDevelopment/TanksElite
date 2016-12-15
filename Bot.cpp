#include "Bot.h"

#include <chrono>
#include <GL/glut.h>

Bot::Bot(Tank t): tank(t) 
{  
    keys.push_back(GLUT_KEY_LEFT);
    keys.push_back(GLUT_KEY_UP);
    keys.push_back(GLUT_KEY_RIGHT);
    keys.push_back(GLUT_KEY_DOWN);
    keys.push_back(32);
    opDelay = 500;
    perfDelay = 250;
    shootKey = 32;

    prevOp = std::chrono::system_clock::now();
    prevPerf = std::chrono::system_clock::now();
}

void Bot::Tick()
{
    EmulateKeyboard();
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - prevOp).count();
    if(delta > perfDelay)
    {
        int operation = operationQueue.front();
        operationQueue.pop_front();
        if(operation == shootKey)
        {
            tank.Keyboard(operation);
        }
        else
        {
            tank.SpecialKeyboard(operation);
        }
    }
}

void Bot::Render()
{
    tank.Render();
}

void Bot::EmulateKeyboard()
{
    //проверить, прошло ли достаточно времени
    //сгенерировать случайную длину цепочки
    //добавить элементы цепочки в стек
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - prevOp).count();
    if(delta > opDelay)
    {
        int length = rand() % 3 + 1; //генерируем цепочки длиной 1..4
        int operation = rand() % 5; //генерируем случайную операцию
        for(int i = 0;i<length;i++)
        {
            operationQueue.push_back(operation);
        }
    }
}

Tank& Bot::GetTank()
{
    return tank;
}