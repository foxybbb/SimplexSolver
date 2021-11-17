//
// Created by IvanEarth on 14.11.2021.
//
# include <string>
#ifndef SIMPLEXSOLVER_FILEPROCESSOR_H
#define SIMPLEXSOLVER_FILEPROCESSOR_H


class FileProcessor {
private:
    int coefficentCount;
    int constrainCount;
    std::string fileName;
    std::string filePath;
    std::string *fileContent;

public:
    void fileImport();

};

#endif // SIMPLEXSOLVER_FILEPROCESSOR_H
