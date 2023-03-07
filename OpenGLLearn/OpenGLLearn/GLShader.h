#pragma once
#include<glad/glad.h>
#include<fstream>

class GLShader {
public:
	GLShader(const char* ShaderFilePath, unsigned int ShaderType);
	unsigned int GetShader();
	~GLShader() {
		glDeleteShader(ShaderID);
	}
protected:
	unsigned int ShaderID;
};

class GLVertexShader : public GLShader {
public:
	GLVertexShader(const char* ShaderSource):GLShader(ShaderSource, GL_VERTEX_SHADER) {}
};

class GLFragShader :public GLShader {
public:
	GLFragShader(const char* ShaderSource):GLShader(ShaderSource, GL_FRAGMENT_SHADER){}
};