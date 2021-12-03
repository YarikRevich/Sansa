#pragma once

#include "glad/glad.h"

namespace Sansa
{
    class Window
    {
    private:
        static GLFWwindow *s_Window;

    public:
        Window(const void *width, const void *height, const char *name);

        static inline GLFWwindow GetWindow() { return s_Window; };
    };
};
