cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Debug)

# Nombre del proyecto
project(OpenGL)

set(SOURCES
    src/main.cpp
    src/GameWindow.cpp
    src/Menu.cpp
    src/OptionsMenu.cpp
)

# Crear el ejecutable con tu archivo fuente
add_executable(OpenGL ${SOURCES})

# Encontrar las dependencias necesarias
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)


# Vincular las bibliotecas necesarias
target_link_libraries(OpenGL PRIVATE OpenGL::GL)
target_link_libraries(OpenGL PRIVATE GLUT::GLUT)
target_link_libraries(OpenGL PRIVATE GLEW::GLEW)
target_link_libraries(OpenGL PRIVATE glfw)
target_link_libraries(OpenGL PRIVATE imgui::imgui)