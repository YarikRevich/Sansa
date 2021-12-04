#include "window.hpp"
#include "log.hpp"


namespace Sansa
{
    Window::Window(const int width, const int height, const char *name)
    {
        s_Window = glfwCreateWindow(width, height, name, NULL, NULL);

        glfwMakeContextCurrent(s_Window);
        if (!s_Window)
        {
            glfwTerminate();
            LOG_ERROR("Window was not created");
        }
    }
};
