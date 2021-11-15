//
// Created by IvanEarth on 14.11.2021.
//

#include "SolverTable.h"
#include "vector"
#include <iostream>

SolverTable::SolverTable()
{
    this->table = new std::vector<std::vector<int>>();
    this->table->resize(0);
}

PrintSolverTable::PrintSolverTable(SolverTable *table)
{
    SolverTable *table_ = table;
}


std::vector<std::vector<int>> SolverTable::getTable() const
{
    return *this->table;
}

SolverTable::~SolverTable()
{
    delete this->table;
}

void PrintSolverTable::printTable()
{
    std::cout << "Table:" << std::endl;
    for (int i = 0; i < solverTable->getTable().size(); i++)
    {
        for (int j = 0; j < solverTable->getTable()[i].size(); j++)
        {
            std::cout << solverTable->getTable()[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

PrintSolverTable::~PrintSolverTable()
{
    delete solverTable;
}
