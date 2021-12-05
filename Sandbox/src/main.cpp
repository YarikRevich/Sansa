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
//using glm::mat4;
//using glm::vec3;
#include 

using namespace Sansa;


int main(int argc, char **argv)
{
    auto window = Window::CreateWindow(100, 200, "Sandbox");

    float positions[6] = {
        -0.2f, -0.5f,
        0.0f,  0.2f,
        0.2f, -0.5f,
    };

   /* floatf texpositions[6] = {
        -0.f2f, -0.5f,
           f0.0f, 0.2f,
           f0.2f, -0.5f,
    };*/   
           






    
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

        //unsigned int blockIndex = glGetUniformBlockIndex(shader, "BlobSettings");

        //int blockSize;
        //glGetActiveUniformBlockiv(shader, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);

        //const char *names[] = {"InnerColor", "OuterColor", "InnerRadius", "OuterRadius"};
        //unsigned int indeces[4];
        //glGetUniformIndices(shader, 4, names, indeces);

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

        //float innerRadius = 0.2f, outerRadius = 0.5f;

        //GLubyte *blockBuffer = (GLubyte *)malloc(sizeof(blockSize));

        //std::memcpy(blockBuffer + offsets[0], innerColor, 4 * sizeof(float));
        //std::memcpy(blockBuffer + offsets[1], outerColor, 4 * sizeof(float));
        //std::memcpy(blockBuffer + offsets[2], &innerRadius, sizeof(float));
        //std::memcpy(blockBuffer + offsets[3], &outerRadius, sizeof(float));

        //unsigned int uniformBuffer;
        //glGenBuffers(1, &uniformBuffer);
        //glBindBuffer(GL_UNIFORM_BUFFER, uniformBuffer);
        //glBufferData(GL_UNIFORM_BUFFER, blockSize, blockBuffer, GL_STATIC_DRAW);

        //glBindBufferBase(GL_UNIFORM_BUFFER, blockIndex, uniformBuffer);

        ///////////////////////////////





        //vao.Unbind()
        //ib.Unbind()
        //shader.Unbind()




     /*   glBindVertexArray(0);
        glUseProgram(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_UNIFORM_BUFFER, 0);*/

        //while (!glfwWindowShouldClose(window))
        //{
     /*       ear(GL_COLOR_BUFFER_BIT)*/

            //Renderer::Clear()

            //shader.Bind()
            //vao.Bind()

            //Renderer::Draw()

            //glUseProgram(shader);

            //mat4 rotationMatrix = glm::rotate(mat4(1.0f), 40.0f, vec3(0.0, 0.0, 1.0));

            //unsigned int location = glGetUniformLocation(shader, "RotationMatrix");
            //if (location >= 0)
            //{
            //    glUniformMatrix4fv(location, 1, GL_FALSE, &rotationMatrix[0][0]);
            //}

            //glBindVertexArray(vao);

            //glDrawArrays(GL_TRIANGLES, 0, 3);

            //glfwSwapBuffers(window);

            //////glfwPollEvents();
        //};

        //glDeleteProgram(shader);
    //}

    //glfwTerminate();
    return 0;
}