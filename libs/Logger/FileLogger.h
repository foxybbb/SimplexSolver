//
// Created by IvanEarth on 14.11.2021.
//

#ifndef SIMPLEXSOLVER_FILELOGGER_H
#define SIMPLEXSOLVER_FILELOGGER_H

#include "fstream"
#include "iostream"
class FileLogger
{
// file logger
private:
    std::ofstream logFile;
    std::string fileName;
    std::fstream file;
public:
    explicit FileLogger(const std::string &fileName);
    ~FileLogger();
    void log(const std::string &message);


};


#endif //SIMPLEXSOLVER_FILELOGGER_H
