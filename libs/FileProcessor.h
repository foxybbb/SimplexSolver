//
// Created by IvanEarth on 14.11.2021.
//
# include <string>
#include "vector"

#ifndef SIMPLEXSOLVER_FILEPROCESSOR_H
#define SIMPLEXSOLVER_FILEPROCESSOR_H


class FileProcessor
{
private:

    std::string fileName;
    std::string filePath;
    std::string *fileContent;

public:
    std::vector<std::string> getFileContent(const std::string &fileName);

};

#endif // SIMPLEXSOLVER_FILEPROCESSOR_H
