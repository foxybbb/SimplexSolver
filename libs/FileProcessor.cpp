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

void FileProcessor::saveFile(const std::string &fileName, const std::string &fileContent)
{
    std::ofstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "File not found!\n";
    }
    file << fileContent;
    file.close();
}

std::vector<double> FileProcessor::extractMatrixforB(std::vector<std::string> lines)
{
    std::vector<double> coefficients;

    char last_char;
    for (int pos = 0; pos < lines[lines.size() - 1].size(); pos++)
    {
        char current_char = lines[0][pos];
        if (last_char == '-' && std::isdigit(current_char))
        {
            coefficients.push_back(std::stod('-' + std::string(1, current_char)));
            pos++;
        } else if (std::isdigit(last_char) && std::isdigit(current_char))
        {
            coefficients.push_back(std::stod(std::string(1, last_char) + std::string(1, current_char)));
            pos++;
        } else if (std::isdigit(current_char))
        {
            coefficients.push_back(std::stod(std::string(1, current_char)));
        }
        last_char = current_char;
    }
    return coefficients;
}

std::vector<double> FileProcessor::extractMatrixforC(std::vector<std::string> lines)
{
    std::vector<double> coefficients;

    char last_char;
    for (int pos = 0; pos < lines[0].size(); pos++)
    {
        char current_char = lines[0][pos];
        if (last_char == '-' && std::isdigit(current_char))
        {
            coefficients.push_back(std::stod('-' + std::string(1, current_char)));
            pos++;
        } else if (std::isdigit(last_char) && std::isdigit(current_char))
        {
            coefficients.push_back(std::stod(std::string(1, last_char) + std::string(1, current_char)));
            pos++;
        } else if (std::isdigit(current_char))
        {
            coefficients.push_back(std::stod(std::string(1, current_char)));
        }
        last_char = current_char;
    }
    coefficients.push_back(0);
    coefficients.push_back(0);
    coefficients.push_back(0);
    return coefficients;
}

std::vector<std::vector<double>> FileProcessor::extractMatrixforA(std::vector<std::string> lines, int coefficentCount)
{
    int constrainCount = lines.size() - 4;

    std::vector<std::vector<double>> coefficients(constrainCount, std::vector<double>(coefficentCount));
    for (unsigned int i = 0; i < constrainCount; i++)
    {
        for (unsigned int j = 0; j < coefficentCount; j++)
        {
            char lastChar;
            for (char &c: lines[i + 2])
            {

                if (std::isdigit(c) && lastChar == '-')
                {
                    coefficients[i][j] = std::stod('-' + std::string(1, c));
                    j++;
                } else if (std::isdigit(c))
                {
                    coefficients[i][j] = std::stod(std::string(1, c));
                    j++;
                }


                lastChar = c;
            }

        }
        for(int pos = 0; pos < coefficentCount; pos++)
        {
           coefficients[pos].push_back(1);
        }

    }
    return coefficients;
}


