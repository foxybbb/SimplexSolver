//
// Created by IvanEarth on 14.11.2021.
//

#ifndef SIMPLEXSOLVER_SOLVERTABLE_H
#define SIMPLEXSOLVER_SOLVERTABLE_H

#include <vector>
#include "string"

class SolverTable
{
private:
    int linesCount;
    int coefficentCount;
    int constrainCount;
    double Z_value;
    std::vector<double> functionCoefficients;
    std::vector<double> constraintsEqualities;
    std::vector<double> functionResult;
    std::vector<std::vector<double>> constraintsCoefficents;

    std::vector<std::vector<double>> ExtendedTable;


    static int calculateNumbersInString(std::vector<std::string> &string,const int &pos);
    std::vector<double> fillVectorWithNumbers(std::vector<std::string> &string,const int &pos);
    std::vector<std::vector<double>> fillVectorWithCoefficients(std::vector<std::string> &string) const;
    void calculateCoefficientsCount();
    void calculateConstrainsCount();
    std::vector<std::vector<double>> extendTable();

public:
    void extractDataFromString(std::vector<std::string> stringArray);
    void beautifulPrint(std::vector<std::vector<double>> &table) const;
    void printAnswer(int &ans) const;
    void solve();
};

#endif //SIMPLEXSOLVER_SOLVERTABLE_H
