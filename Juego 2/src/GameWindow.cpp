#include "../include/GameWindow.h"

bool GameWindow::initOpenGl() {
    if (!glfwInit())
    {
        printf("Ha ocurrido un error al iniciar OpenGL");
        return false;
    }
    return true;
}

bool GameWindow::createWindow(GLFWwindow *&window) {
    window = glfwCreateWindow(640, 480, "Juego", NULL, NULL);

    if (!window)
    {
        printf("Ha ocurrido un error al crear la ventana\n");
        return false;
    }
    return true;
}

void GameWindow::closeWindowCallback(GLFWwindow *window)
{
    printf("Cerrando la ventana\n");

    glfwSetWindowShouldClose(window, GL_TRUE);
}


void GameWindow::configureWindowCloseCallback(GLFWwindow *window) {
    GLFWwindowclosefun previusCallback = glfwSetWindowCloseCallback(window, closeWindowCallback);

    if (previusCallback == NULL) {
        printf("No habia un callback definido con anterioridad para la funcionm de cerrar ventana");
    }
}


void GameWindow::setContextToCurrentWindow(GLFWwindow *window) {
    glfwMakeContextCurrent(window);
}

void GameWindow::liberateWindow() {
    glfwTerminate();
}

