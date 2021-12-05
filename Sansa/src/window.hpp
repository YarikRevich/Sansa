#pragma once

#include "pch.hpp"

namespace Sansa
{
    class Window
    {
    private:
    public:
       std::shared_ptr<GLFWwindow> CreateWindow(const int width, const int height, const char *name);
    };
   
};
