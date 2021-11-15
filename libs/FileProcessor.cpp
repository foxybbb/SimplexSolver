//
// Created by IvanEarth on 14.11.2021.
//

#include "FileProcessor.h"
#include <fstream>
#include "iostream"

FileProcessor::FileProcessor()
{

}


void FileProcessor::readFile(const char *fileName)
{
    this->fileExists(fileName);

    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            fileContent.append(line + "\n");
        }
        file.close();

        std::cout << "File " << fileName << " was read successfully" << std::endl;



    } else
        std::cout << "File zanat" << std::endl;
}

void FileProcessor::writeFile(const char *fileName)
{

}

void FileProcessor::fileExists(std::string fileName)
{
// check if file exists
    if(!std::ifstream(fileName))
    {
        std::cout << "File " << fileName << " does not exist" << std::endl;
        exit(1);
    }
}




