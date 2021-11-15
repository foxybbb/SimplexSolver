//
// Created by IvanEarth on 14.11.2021.
//

#include "FileLogger.h"
#include <fstream>
#include <iostream>

FileLogger::FileLogger(const std::string &fileName)
{
    this->fileName = fileName;
    this->file.open(fileName, std::ios::out);
}

FileLogger::~FileLogger()
{
    this->file.close();
}

void FileLogger::log(const std::string &message)
{
    this->file << message << std::endl;
}
