#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GLMesh.h"
#include "GLShader.h"
#include "GLShaderProgram.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // init window
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // viewport and callback
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Shaders
    GLVertexShader VShader("BaseVS.glsl");
    GLFragShader FShader("BaseFS.glsl");

    GLShaderProgram Program(VShader.GetShader(), FShader.GetShader());
    glDeleteShader(VShader.GetShader());
    glDeleteShader(FShader.GetShader());
    
    GLVBO TestVBO(vertices);
    TestVBO.PrepareMesh();
    
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // process input
        processInput(window);

        // rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(TestVBO.GetVAO());
        glUseProgram(Program.GetProgram());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // check events and swap buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // release resources
    glfwTerminate();
    return 0;
}