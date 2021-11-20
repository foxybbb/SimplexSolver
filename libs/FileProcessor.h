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

    void saveFile(const std::string &fileName, const std::string &fileContent);

    std::vector<double> extractMatrixforB(std::vector<std::string> lines);

    std::vector<double> extractMatrixforC(std::vector<std::string> lines);

    std::vector<std::vector<double>> extractMatrixforA(std::vector<std::string> lines, int coefficentCount);
};

#endif // SIMPLEXSOLVER_FILEPROCESSOR_H
