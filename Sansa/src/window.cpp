#include "window.hpp"
#include "log.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "pch.hpp"



GLFWwindow* Sansa::Window::Create(const int width, const int height, const char *name)
{
    Sansa::Logger::Init();

    if (!glfwInit())
    {
        LOG_ERROR("Window was not created!");
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    auto window = glfwCreateWindow(width, height, name, NULL, NULL);

    glfwMakeContextCurrent(window);
    if (!window)
    {
        LOG_ERROR("Window was not created");
        glfwTerminate();
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG_ERROR("Failed to initialize OpenGL context");
        return nullptr;
    }

    return window;
}
