#ifndef MENU_H
#define MENU_H
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>
#include "../include/MenuState.h"
#include "OptionsMenu.h"

struct GameMenu
{
  
    MenuState state;
    OptionsMenu optionsMenu;


    GameMenu(MenuState state) : optionsMenu()
    {
        this->state = state;
    }

    void initImguioContext();

    void initImguioInputOutput(ImGuiIO &io);

    void imguioConfigFlags(ImGuiIO &io);

    bool initImguioForOpenGL(GLFWwindow *window);

    void createMenu();

    void setState(MenuState state);

    MenuState getState();

    void menuState(MenuState state);

    
    
    void destroyMenu();
};

#endif
