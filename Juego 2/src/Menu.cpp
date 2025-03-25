#include "../include/Menu.h"
#include <iostream>
#include "../include/OptionsMenu.h"
void GameMenu::initImguioContext()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
}

void GameMenu::initImguioInputOutput(ImGuiIO &io)
{
    io = ImGui::GetIO();
}

void GameMenu::imguioConfigFlags(ImGuiIO &io)
{
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
}

bool GameMenu::initImguioForOpenGL(GLFWwindow *window)
{
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true); // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    if (!ImGui_ImplOpenGL3_Init())
    {
        return false;
    }
    return true;
}

void GameMenu::createMenu()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Menu del Juego");

    if (ImGui::Button("Reanudar", ImVec2(100, 30)))
    {

        setState(CLOSE);

        menuState(getState());
    }

    optionsMenu.createOptionsMenu();

    ImGui::End();
   

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GameMenu::menuState(MenuState state)
{

    switch (state)
    {

    case OPEN:
        createMenu();
        break;

    case CLOSE:
        std::cout << "Cambiando estado a cerrado" << std::endl;

        setState(START);
        break;
    case START:
        std::cout << "Cambiando estado a iniciando" << std::endl;
        // No hace nada, solamente es para que no se muestre el menu cuando inicia el jeugo
        break;
    }
}

void GameMenu::destroyMenu()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void GameMenu::setState(MenuState state)
{
    this->state = state;
}

MenuState GameMenu::getState()
{
    return state;
}
