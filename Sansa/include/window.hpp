#pragma once

#include "pch.hpp"

namespace Sansa
{
    class Window
    {
    public:

       static GLFWwindow* Create(const int width, const int height, const char *name);
    };
   
};
