#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <stdlib.h>
#include <experimental/filesystem>

#include "loader.hpp"
#include "error.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "renderer.hpp"
#include "indexBuffer.hpp"
#include "vertexBuffer.hpp"

using glm::mat4;
using glm::vec3;

static unsigned int CompileShader(unsigned int type, const std::string &src)
{
    unsigned int id = glCreateShader(type);
    const char *s = src.c_str();
    glShaderSource(id, 1, &s, nullptr);
    glCompileShader(id);

    OpenGL::ShaderErrorCatcher(id, "shader error", [&] {});

    return id;
}

static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(int argc, char **argv)
{
    GLFWwindow *window;

    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(640, 400, "Hello world", NULL, NULL);

    glfwMakeContextCurrent(window);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    float positions[6] = {
        -0.2f,
        -0.5f,
        0.0f,
        0.2f,
        0.2f,
        -0.5f,
    };

    float texpositions[6] = {
        -0.2f,
        -0.5f,
        0.0f,
        0.2f,
        0.2f,
        -0.5f,
    };

    {
        unsigned int vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        OpenGL::VertexBuffer vertexPosition(positions, 6 * sizeof(float));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        OpenGL::VertexBuffer texPosition(texpositions, 6 * sizeof(float));

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        OpenGL::Loader l("shaders/Basic.shader.glsl");

        unsigned int shader = CreateShader(l.GetVertexShader(), l.GetFragmentShader());

        glUseProgram(shader);

        ///////////////////////////////

        unsigned int blockIndex = glGetUniformBlockIndex(shader, "BlobSettings");

        int blockSize;
        glGetActiveUniformBlockiv(shader, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);

        const char *names[] = {"InnerColor", "OuterColor", "InnerRadius", "OuterRadius"};
        unsigned int indeces[4];
        glGetUniformIndices(shader, 4, names, indeces);

        int offsets[4];
        glGetActiveUniformsiv(shader, 4, indeces, GL_UNIFORM_OFFSET, offsets);

        float outerColor[] = {
            0.0f,
            0.0f,
            0.0f,
            0.0f,
        };

        float innerColor[] = {
            1.0f,
            1.0f,
            1.0f,
            1.0f,
        };

        float innerRadius = 0.2f, outerRadius = 0.5f;

        GLubyte *blockBuffer = (GLubyte *)malloc(sizeof(blockSize));

        std::memcpy(blockBuffer + offsets[0], innerColor, 4 * sizeof(float));
        std::memcpy(blockBuffer + offsets[1], outerColor, 4 * sizeof(float));
        std::memcpy(blockBuffer + offsets[2], &innerRadius, sizeof(float));
        std::memcpy(blockBuffer + offsets[3], &outerRadius, sizeof(float));

        unsigned int uniformBuffer;
        glGenBuffers(1, &uniformBuffer);
        glBindBuffer(GL_UNIFORM_BUFFER, uniformBuffer);
        glBufferData(GL_UNIFORM_BUFFER, blockSize, blockBuffer, GL_STATIC_DRAW);

        glBindBufferBase(GL_UNIFORM_BUFFER, blockIndex, uniformBuffer);

        ///////////////////////////////

        glBindVertexArray(0);
        glUseProgram(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_UNIFORM_BUFFER, 0);

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shader);

            mat4 rotationMatrix = glm::rotate(mat4(1.0f), 40.0f, vec3(0.0, 0.0, 1.0));

            unsigned int location = glGetUniformLocation(shader, "RotationMatrix");
            if (location >= 0)
            {
                glUniformMatrix4fv(location, 1, GL_FALSE, &rotationMatrix[0][0]);
            }

            glBindVertexArray(vao);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            glfwSwapBuffers(window);

            glfwPollEvents();
        };

        glDeleteProgram(shader);
    }

    glfwTerminate();
    return 0;
}