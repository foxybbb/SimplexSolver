//
// Created by IvanEarth on 19.11.2021.
//

#ifndef SIMPLEXSOLVER_SOLVER_H
#define SIMPLEXSOLVER_SOLVER_H
#include <string>
#include <vector>

class Solver
{
private:
    bool _is_solved;
    double _max_value;

    int _row_count;
    int _column_count;
    std::vector<std::vector<double>> functionCoefficients;
    std::vector<double> constantsCoefficients;
    std::vector<double> objectiveFunctionCoefficients;
    bool check_optimality();
    int get_bazis_column();
    int get_bazis_row(int bazisColumn);
    void row_print();
public:
    Solver(std::vector<std::vector<double>> matrix, std::vector<double> b, std::vector<double> c);

    void set_row_count(int row_count);
    void set_column_count(int column_count);
    void fill_2D_Matrix(std::vector<std::vector<double>> &matrix);
    void fill_1D_Matrix(std::vector<double> &inputMatrix, std::vector<double> &outputMatrix);
    bool solve();
    void calculate_simplex_table();


    void convert_table(int row, int column);

    int countNegativesValues(int bazisColumn, float *positive_values, int negatives_variables);

    std::vector<float> &checkUnbound(const float *positive_values, std::vector<float> &temp, int negatives_variables);

    int findIndexOfMinValue(const std::vector<float> &temp) const;

    void calculateResolvingValuesRow(int row, double *resolving_value_rows);

    void calculateResolvingValuesColumn(int column, double *resolving_value_columns);

    void calculateNewRowData(int row, double resolving_value, const double *resolving_value_rows, double *new_row_data);

    void calculateMaximum(int row, int column, double resolving_value);

    void functionCoefficentRecalculation(int row, const double *resolving_value_columns, const double *new_row_data);

    void constantsCoefficientsRecalculation(int row, const double *resolving_value_columns);

    void CalculationObjFunction(const double *new_row_data, float multiplyValue);

    void printAnswerVariables();

    void printMaximumValues() const;
};


#endif //SIMPLEXSOLVER_SOLVER_H
