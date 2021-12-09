#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <string>
#include <iostream>

#include <vector>

#include <fstream>


#ifndef WIN32
#include <experimental/filesystem>
#else
#include <filesystem>
#endif

#include <functional>

#include <sstream>


#include "glm/glm.hpp"
#include "glad/glad.h"

#ifdef ENABLE_VK
#define GLFW_ENABLE_VULKAN
#include "glfw/GLFW/glfw3.h"
#endif
