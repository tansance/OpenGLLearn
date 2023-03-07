#pragma once
#include<fstream>

#define LINE_CHAR_MAX 256
#define FILE_LINE_MAX 500
#define FILE_CHAR_MAX LINE_CHAR_MAX * FILE_LINE_MAX
#define FILE_PATH_PREFIX ""
#define PATH_WITH_PREFIX(PATH) FILE_PATH_PREFIX##PATH
using namespace std;

class FileUtils {
public: 
	static bool ReadFile(const char* FilePath, char* Out);
};