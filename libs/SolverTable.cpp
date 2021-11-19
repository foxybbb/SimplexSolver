#include <iostream>
#include "SolverTable.h"

int SolverTable::calculateNumbersInString(std::vector<std::string> &string, const int &pos)
{
    int count = 0;
    count = 0;
    for (char &c: string[pos])
    {
        if (std::isdigit(c))
        {
            count++;
        }
    }
    return count;
}

std::vector<double> SolverTable::fillVectorWithNumbers(std::vector<std::string> &string, const int &pos)
{
    std::vector<double> numbers;
    for (char &c: string[pos])
    {
        if (std::isdigit(c))
        {
            numbers.push_back(std::stod(std::string(1, c)));
        }
    }

    return numbers;
}

std::vector<std::vector<double>> SolverTable::fillVectorWithCoefficients(std::vector<std::string> &string) const
{
    std::vector<std::vector<double>> coefficients(constrainCount, std::vector<double>(coefficentCount));
    for (unsigned int i = 0; i < constrainCount; i++)
    {
        for (unsigned int j = 0; j < coefficentCount; j++)
        {
            char lastChar;
            for (char &c: string[i + 2])
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
    }
    return coefficients;
}


void SolverTable::calculateCoefficientsCount()
{
    coefficentCount = functionCoefficients.size() - 1;
}

void SolverTable::calculateConstrainsCount()
{
    constrainCount = linesCount - 4;
}

void SolverTable::extractDataFromString(std::vector<std::string> stringArray)
{
    linesCount = stringArray.size();
    calculateConstrainsCount();


    functionCoefficients = fillVectorWithNumbers(stringArray, 0);
    calculateCoefficientsCount();
    constraintsCoefficents = fillVectorWithCoefficients(stringArray);

    functionResult = fillVectorWithNumbers(stringArray, linesCount - 1);
    extendTable();
}

void SolverTable::extendTable()
{
    std::vector<std::vector<double>> extendTable(constrainCount + 1, std::vector<double>(coefficentCount * 2 + 1));

    for (auto row = constraintsCoefficents.begin(); row != constraintsCoefficents.end(); row++)
    {
        for (auto column = row->begin(); column != row->end(); column++)
        {
            extendTable[row - constraintsCoefficents.begin()][column - row->begin()] = *column;
        }
    }

    for (int i = 0; i < coefficentCount; i++)
    {
        extendTable[extendTable.size() - 1][i] = functionResult[i];
    }

    for (int row = 0; row < extendTable.size() - 2; row++)
    {
        for (int element = coefficentCount; element <= extendTable[0].size() - 2; element++)
        {
            extendTable[row][element] = 1;
            row++;
        }
    }

    for (int row = 0; row < extendTable.size() - 1; row++)
    {
        extendTable[row][extendTable[0].size() - 1] = functionResult[row];
    }
    std::endl(std::cout);

    beautifulPrint(extendTable);


}

void SolverTable::beautifulPrint(std::vector<std::vector<double>> &table) const
{
    std::cout << "\t";
    bool header = true;
    for (int row = 0; row < table.size(); row++)
    {

        if (header)
        {
            for (int x = 1; x <= coefficentCount; x++)
            {
                std::cout << "x" + std::to_string(x) << "\t";
            }
            for (int x = coefficentCount; x <= constrainCount * 2 - 1; x++)
            {
                std::cout << "s" + std::to_string(x - coefficentCount + 1) << "\t";
            }
            std::cout << "b" << std::endl;
            header = false;
        } // вывод заголовка

        if (row == table.size() - 1)
        { //вывод названий строк
            std::cout << "c" << "\t";
        } else
        {
            std::cout << "s" + std::to_string(row + 1) << "\t";
        }


        for (int element = 0; element < table[0].size(); element++)  // вывод чисел
        {
            std::cout << table[row][element] << "\t";
        }
        std::cout << std::endl;

    }
}

void SolverTable::printAnswer(int &ans) const
{
    switch (ans)
    {
        case 1:
            std::cout << "NO SOLUTION: unbounded problem " << std::endl;
            break;
        case 2:
            std::cout << "SOLUTION FOUND: unique solution" << std::endl << "Objective: " +
            std::to_string(Z_value) << std::endl;
            break;
        case 3:
            std::cout << "SOLUTION FOUND: multiple solutions" << std::endl << "Objective: " +
            std::to_string(Z_value) << std::endl;
            break;
}



