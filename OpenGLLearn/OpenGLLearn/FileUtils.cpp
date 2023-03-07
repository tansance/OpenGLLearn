#define _CRT_SECURE_NO_WARNINGS
#include "FileUtils.h"
#include <vector>
#include<string>

bool FileUtils::ReadFile(const char* FilePath, char* Out)
{
    Out[0] = '\0';
    //char Prefix[LINE_CHAR_MAX] = FILE_PATH_PREFIX;
    ifstream InFileStream;
    InFileStream.open(FilePath);
    if (!InFileStream.is_open()) {
        char* Out = nullptr;
        return false;
    }

    while (!InFileStream.eof()) {
        char buffer[LINE_CHAR_MAX];
        InFileStream.getline(buffer, LINE_CHAR_MAX);
        strcat(Out, buffer);
        strcat(Out, "\n");
    }
    InFileStream.close();
    return true;
}
