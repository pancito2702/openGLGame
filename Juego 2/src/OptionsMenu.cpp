#include "../include/OptionsMenu.h"
#include "../include/GameWindow.h"
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
OptionsMenu::OptionsMenu() {

}

void OptionsMenu::createOptionsMenu() {
    ImGui::BeginChild("Opciones", ImVec2(200, 100), true);

    int monitorCount = 0;

    GLFWmonitor **monitors = glfwGetMonitors(&monitorCount);

    static int selectedMonitor = 0;

   
    for (int i = 0; i < monitorCount; i++) {
        GLFWmonitor *monitor = monitors[i];
        const char *monitorName = glfwGetMonitorName(monitor);


        if (ImGui::RadioButton(monitorName, selectedMonitor == i)) {
            selectedMonitor = i;
        }
    }

    GLFWwindow* window = glfwGetCurrentContext();
    int x, y;
    glfwGetWindowSize(window, &x, &y);

    printf("%d", x);
    ImGui::Button("Cambiar monitor", ImVec2(150, 30));

    ImGui::EndChild();
}

