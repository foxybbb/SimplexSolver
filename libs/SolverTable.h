//
// Created by IvanEarth on 14.11.2021.
//

#ifndef SIMPLEXSOLVER_SOLVERTABLE_H
#define SIMPLEXSOLVER_SOLVERTABLE_H

#include <vector>

class SolverTable
{
private:
    std::vector<std::vector<int>> *table;
public:
    SolverTable();

    ~SolverTable();

    std::vector<std::vector<int>> getTable() const;

};

class PrintSolverTable
{
private:
    SolverTable *solverTable{};
public:
    explicit PrintSolverTable(SolverTable *table);

    ~PrintSolverTable();

    void printTable();
};

#endif //SIMPLEXSOLVER_SOLVERTABLE_H
