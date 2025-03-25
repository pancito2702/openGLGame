#ifndef GameWindow_H
#define GameWindow_H
#include <GLFW/glfw3.h>
#include <stdio.h>

struct GameWindow
{
    GLFWwindow *window;

    bool initOpenGl();

    bool createWindow(GLFWwindow *&window);

    static void closeWindowCallback(GLFWwindow *window);

    void configureWindowCloseCallback(GLFWwindow *window);

    void setContextToCurrentWindow(GLFWwindow *window);

    void liberateWindow();


};
#endif