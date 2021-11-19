//
// Created by IvanEarth on 14.11.2021.
//

#include "FileProcessor.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include "iostream"


std::vector<std::string> FileProcessor::getFileContent(const std::string &fileName)
{
    std::cout << "Enter the file name with full path and extension: \n";
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "File not found!\n";

    }
    std::string line;
    std::vector<std::string> lines;
    // calculate the number of lines in the file
    unsigned int lineCount = 0;
    while (std::getline(file, line))
    {
        lineCount++;
        lines.push_back(line);
    }

    file.close();
    return lines;


}
