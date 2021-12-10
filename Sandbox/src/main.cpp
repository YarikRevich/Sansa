//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
//#include <iostream>
//#include <stdlib.h>

//#include "loader.hpp"
//#include "error.hpp"
//
//#include "glm/glm.hpp"
//#include "glm/matrix_transform.hpp"

//#include "pch.hpp"

//#include "renderer.hpp"
//#include "indexBuffer.hpp"
//#include "vertexBuffer.hpp"
//
// using glm::mat4;
// using glm::vec3;

#include "window.hpp"
#include "vbo.hpp"
#include "vao.hpp"
#include "vbolayout.hpp"
#include "ib.hpp"
#include "shader.hpp"
#include "renderer.hpp"
#include "objloader.hpp"
#include "texture.hpp"

using namespace Sansa;

int main(int argc, char **argv)
{
    GLFWwindow *window = Window::CreateWindow(600, 800, "Sandbox");

    //  -0.5f, -0.5f,  
    //     0.5f, -0.5f,   
    //     0.5f, 0.5f,    
    //     -0.5f, 0.5f,   

    float positions[] = {
        // front
        -0.5f, -0.5f, 0.0f, 0.0f,  
        0.5f, -0.5f,  1.0f, 0.0f,
        0.5f, 0.5f,   1.0f, 1.0f,
        -0.5f, 0.5f,  0.0f, 1.0f,

        // // right
        // -0.3f,-0.3f,
        // 0.7f,-0.3f,
        // 0.7f,0.7f,

        // // top
        // -0.17f, 0.7f,
    };

    unsigned int indecies[] = {
        0,
        1,
        2,
        2,
        3,
        0,

        // 1,
        // 5,
        // 6,
        // 6,
        // 2,
        // 1,

        // 3,
        // 2,
        // 6,
        // 6,
        // 7,
        // 3,
    };

    VAO vao;

    // std::vector<glm::vec3> positions;
    // std::vector<int> indecies;

    // OBJLoader model("models/teapot.obj", positions, indecies);

    VBO vb(positions, sizeof(positions) * sizeof(float));
    IndexBuffer ib(indecies, sizeof(indecies));

    VBOLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);

    vao.AddBuffer(vb, layout);

    Shader shader(ShaderLoader::LoadShader("shaders/base.glsl"));

    Texture texture("textures/example.png");
    texture.Bind();
    
    shader.SetUniform1i("u_Texture", 0);
    

    /*     unsigned int vao;
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

         glUseProgram(shader);*/

    ///////////////////////////////

    // unsigned int blockIndex = glGetUniformBlockIndex(shader, "BlobSettings");

    // int blockSize;
    // glGetActiveUniformBlockiv(shader, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);

    // const char *names[] = {"InnerColor", "OuterColor", "InnerRadius", "OuterRadius"};
    // unsigned int indeces[4];
    // glGetUniformIndices(shader, 4, names, indeces);

    /*    int offsets[4];
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
        };*/

    // float innerRadius = 0.2f, outerRadius = 0.5f;

    // GLubyte *blockBuffer = (GLubyte *)malloc(sizeof(blockSize));

    // std::memcpy(blockBuffer + offsets[0], innerColor, 4 * sizeof(float));
    // std::memcpy(blockBuffer + offsets[1], outerColor, 4 * sizeof(float));
    // std::memcpy(blockBuffer + offsets[2], &innerRadius, sizeof(float));
    // std::memcpy(blockBuffer + offsets[3], &outerRadius, sizeof(float));

    // unsigned int uniformBuffer;
    // glGenBuffers(1, &uniformBuffer);
    // glBindBuffer(GL_UNIFORM_BUFFER, uniformBuffer);
    // glBufferData(GL_UNIFORM_BUFFER, blockSize, blockBuffer, GL_STATIC_DRAW);

    // glBindBufferBase(GL_UNIFORM_BUFFER, blockIndex, uniformBuffer);

    ///////////////////////////////

    // vao.Unbind()
    // ib.Unbind()
    // shader.Unbind()

    /*   glBindVertexArray(0);
       glUseProgram(0);
       glBindBuffer(GL_ARRAY_BUFFER, 0);
       glBindBuffer(GL_UNIFORM_BUFFER, 0);*/

    // vao.Unbind();
    // shader.Unbind();

    vao.Unbind();
    shader.Unbind();
    // shader.Unbind();
    // shader.Bind();
    {
        while (!glfwWindowShouldClose(window))
        {
            Renderer::Clear();

            shader.Bind();
            shader.SetUniform1i("u_Texture", 0);
            
            // Renderer::SetUniforms(
            //     [&]()
            //     {
            //         shader.SetUniform1i("texId", 0);
            //     });

                // shader.SetUniform1i("texId", 0);

            // glClearColor(0.1, 0.2, 1.0, 1.0);
            Renderer::Draw(vao, ib, shader);

            // GL_LOG(glClear(GL_COLOR_BUFFER_BIT));

            // GL_LOG(glfwSwapBuffers(window));
            // GL_LOG(glfwPollEvents());

            // Renderer::Clear()

            // shader.Bind()
            // vao.Bind()

            // Renderer::Draw()

            // glUseProgram(shader);

            // mat4 rotationMatrix = glm::rotate(mat4(1.0f), 40.0f, vec3(0.0, 0.0, 1.0));

            // unsigned int location = glGetUniformLocation(shader, "RotationMatrix");
            // if (location >= 0)
            //{
            //     glUniformMatrix4fv(location, 1, GL_FALSE, &rotationMatrix[0][0]);
            // }

            // glBindVertexArray(vao);

            // glDrawArrays(GL_TRIANGLES, 0, 3);

            glfwSwapBuffers(window);
            glfwPollEvents();
        };
    };

    glfwTerminate();
    return 0;
}