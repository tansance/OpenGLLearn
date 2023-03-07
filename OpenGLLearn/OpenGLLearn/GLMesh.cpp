#include "GLMesh.h"

void GLVBO::PrepareMesh()
{
    // Bind VAO
    glGenVertexArrays(1, &VAOID);
    glBindVertexArray(VAOID);

    glGenBuffers(1, &VBOID);
    glBindBuffer(GL_ARRAY_BUFFER, VBOID);
    // layout, attri num, attri type, bNormalize, stride, begining offset
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // Set Vertex Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Unbind VAO
    glBindVertexArray(0);
}

GLuint GLVBO::GetVBO()
{
    return VBOID;
}

GLuint GLVBO::GetVAO()
{
    return VAOID;
}
