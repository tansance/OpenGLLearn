#pragma once

class GLShaderProgram {
public:
	GLShaderProgram(unsigned int InVS, unsigned int InFS);
	unsigned int GetProgram();

	unsigned int GetVS();
	unsigned int GetFS();
private:
	unsigned int VS;
	unsigned int FS;
	unsigned int ProgramID;
};
