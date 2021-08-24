#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "camera.h"

class Mouse
{
public:
    static void mouse_callback(GLFWwindow *window, double _dx, double _dy);
    static double getDx();
    static double getDy();
    static double getX();
    static double getY();

private:
    static bool firstMouse;

    static double x;
    static double y;
    static double dx;
    static double dy;
    static double lastx;
    static double lasty;
};

#endif