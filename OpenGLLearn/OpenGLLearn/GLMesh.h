#pragma once
#include <glad/glad.h>

const float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

class GLVBO {
public:
    GLVBO(const float *Vertices){
        this->Vertices = Vertices;
        VBOID = 0;
        VAOID = 0;
    }
    void PrepareMesh();
    GLuint GetVBO();
    GLuint GetVAO();
private:
    const float *Vertices;
    GLuint VBOID;
    GLuint VAOID;
};