#include "GLShaderProgram.h"
#include <glad/glad.h>

GLShaderProgram::GLShaderProgram(unsigned int InVS, unsigned int InFS) :VS(InVS), FS(InFS) {
	ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VS);
	glAttachShader(ProgramID, FS);
	glLinkProgram(ProgramID);
}

unsigned int GLShaderProgram::GetProgram()
{
	return ProgramID;
}

unsigned int GLShaderProgram::GetVS()
{
	return VS;
}

unsigned int GLShaderProgram::GetFS()
{
	return FS;
}
