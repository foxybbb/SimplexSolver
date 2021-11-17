//
// Created by IvanEarth on 14.11.2021.
//

#include "FileProcessor.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include "iostream"


void FileProcessor::fileImport()
{
    std::cout << "Enter the file name with full path and extension: \n";
    fileName = "C:\\Users\\IvanEarth\\Desktop\\input0.txt";
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

    coefficentCount = 0;
    for(char &c : lines[0])
    {
        if(std::isdigit(c))
        {
             coefficentCount++;
        }
    }

    constrainCount = lineCount - 4;

    std:std::vector<double> functionCoefficients;
    std::vector<std::vector<double>> constraintsCoefficients;
    std::vector<double> constraintsEqualities;

    for(char &c : lines[0])
    {
        if(std::isdigit(c))
        {
            functionCoefficients.push_back(std::stod(std::string(1, c)));
        }
    }

    for(int constrainRow = 2; constrainRow <= constrainCount+2; constrainRow++)
    {
        for(char &c : lines[constrainRow])
        {
            if(std::isdigit(c))
            {
                constraintsCoefficients[constrainRow-1].push_back(std::stod(std::string(1, c)));
            }
        }
    }


    for(char &c : lines[lineCount])
    {
        if(std::isdigit(c))
        {
            constraintsEqualities.push_back(std::stod(std::string(1, c)));
        }
    }

    // convert string to number array
    file.close();


}
