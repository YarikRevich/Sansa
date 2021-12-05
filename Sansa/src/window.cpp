#include "window.hpp"
#include "log.hpp"

   

std::shared_ptr<GLFWwindow> Sansa::Window::CreateWindow(const int width, const int height, const char* name)
{

        if (!glfwInit())
        {
            LOG_ERROR("Window was not created!");
            return nullptr
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
            glfwTerminate();
            LOG_ERROR("Window was not created");
        }


        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize OpenGL context" << std::endl;
            return -1;
        }
    
    return std::shared_ptr<GLFWwindow>(window);
}
