#include "GLShader.h"
#include "FileUtils.h"
#include "ExceptionMacros.h"

GLShader::GLShader(const char* ShaderFilePath, unsigned int ShaderType)
{
	char* ShaderSource = new char[FILE_CHAR_MAX];
	FileUtils::ReadFile(ShaderFilePath, ShaderSource);
	ShaderID = glCreateShader(ShaderType);
	glShaderSource(ShaderID, 1, &ShaderSource, nullptr);
	glCompileShader(ShaderID);
	delete[] ShaderSource;
}

unsigned int GLShader::GetShader()
{
    return ShaderID;
}
