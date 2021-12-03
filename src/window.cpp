#include "window.hpp"

namespace Sansa
{
    Window::Window(const void *width, const void *height, const char *name)
    {
        s_Window = glfwCreateWindow(width, height, name, NULL, NULL);

        glfwMakeContextCurrent(s_Window);
        if (!s_Window)
        {
            glfwTerminate();
            // return -1;
        }
    }
};
