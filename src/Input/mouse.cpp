#include "mouse.h"

bool Mouse::firstMouse = true;

double Mouse::x = 0;
double Mouse::y = 0;

double Mouse::dx = 0;
double Mouse::dy = 0;

double Mouse::lastx = 0;
double Mouse::lasty = 0;

void Mouse::mouse_callback(GLFWwindow *window, double _x, double _y)
{
    x = _x;
    y = _y;

    if (firstMouse)
    {
        lastx = x;
        lasty = y;
        firstMouse = false;
    }

    dx = x - lastx;
    dy = lasty - y; // y coordinates are inverted
    lastx = x;
    lasty = y;
}

double Mouse::getDx()
{
    double temp = dx;
    dx = 0;
    return temp;
}

double Mouse::getDy()
{
    double temp = dy;
    dy = 0;
    return temp;
}
