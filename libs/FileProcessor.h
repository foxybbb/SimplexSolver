//
// Created by IvanEarth on 14.11.2021.
//
# include <string>
#ifndef SIMPLEXSOLVER_FILEPROCESSOR_H
#define SIMPLEXSOLVER_FILEPROCESSOR_H


class FileProcessor {
private:
    std::string inputFileName;
    std::string outputFileName;
    std::string fileContent;
    void fileExists(std::string fileName);

public:
    FileProcessor();

    void readFile(const char *fileName);
    void writeFile(const char *fileName);
};

#endif // SIMPLEXSOLVER_FILEPROCESSOR_H
