#pragma once

#include "pch.hpp"

namespace Sansa
{
    class Window
    {
    public:

       static GLFWwindow* CreateWindow(const int width, const int height, const char *name);
    };
   
};
