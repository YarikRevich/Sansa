#pragma once

#include "pch.hpp"

namespace Sansa
{
    class Window
    {
    private:
        static GLFWwindow* s_Window;

    public:
        Window(const int width, const int height, const char *name);

        static inline GLFWwindow* GetWindow() { return s_Window; };
    };
};
