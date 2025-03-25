#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../include/GameWindow.h"
#include "../include/MenuState.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/Menu.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mod)
{
    GameMenu *menu = static_cast<GameMenu *>(glfwGetWindowUserPointer(window));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        if (menu->getState() == OPEN)
        {
            menu->setState(CLOSE);
        }
        else
        {
            std::cout << "Escape presionado, cambiando estado a ABIERTO." << std::endl;
            menu->setState(OPEN);
        }
    }
}

int main(int argc, char **argv)
{
    GameWindow *gameWindow = new GameWindow();
    if (!gameWindow->initOpenGl())
    {
        exit(0);
    }

    GLFWwindow *window = NULL;

    if (!gameWindow->createWindow(window))
    {
        exit(0);
    }

    gameWindow->setContextToCurrentWindow(window);

    gameWindow->configureWindowCloseCallback(window);



    GameMenu *menu = new GameMenu(START);

    menu->initImguioContext();

    ImGuiIO io;

    menu->initImguioInputOutput(io);

    menu->imguioConfigFlags(io);

    bool resultInitImguioOpenGL = menu->initImguioForOpenGL(window);

    if (!resultInitImguioOpenGL)
    {
        gameWindow->liberateWindow();
        exit(0);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwSetWindowUserPointer(window, menu);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        menu->menuState(menu->getState());

        glfwSwapBuffers(window);
    }

    menu->destroyMenu();
    gameWindow->liberateWindow();
    delete gameWindow;
    delete menu;
    return 0;
}
