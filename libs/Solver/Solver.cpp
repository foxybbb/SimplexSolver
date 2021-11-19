//
// Created by IvanEarth on 19.11.2021.
//

#include "Solver.h"
#include <iostream>

Solver::Solver(std::vector<std::vector<double>> matrix, std::vector<double> b, std::vector<double> c)
{
    _max_value = 0;
    _is_solved = false;
    set_row_count(matrix.size());
    set_column_count(matrix[0].size());

    functionCoefficients.resize(_row_count, std::vector<double>(_column_count, 0));
    constantsCoefficients.resize(c.size());
    objectiveFunctionCoefficients.resize(b.size());

    fill_2D_Matrix(matrix);
    fill_1D_Matrix(c, constantsCoefficients);
    fill_1D_Matrix(b, objectiveFunctionCoefficients);

}

void Solver::set_row_count(int row_count)
{
    _row_count = row_count;
}

void Solver::set_column_count(int column_count)
{
    _column_count = column_count;
}

void Solver::fill_2D_Matrix(std::vector<std::vector<double>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {             //pass A[][] values to the metrix
        for (int j = 0; j < matrix[0].size(); j++)
        {
            functionCoefficients[i][j] = matrix[i][j];
        }
    }
}

void Solver::fill_1D_Matrix(std::vector<double> &inputMatrix, std::vector<double> &outputMatrix)
{
    for (int i = 0; i < inputMatrix.size(); i++)
    {
        outputMatrix[i] = inputMatrix[i];
    }
}

bool Solver::check_optimality()
{
    int positive_count = 0;
    int negative_count = 0;
    // проверка на оптимальность, коэфиценты функции больше 0
    for (double &i: constantsCoefficients)
    {
        if (i >= 0)
        {
            positive_count++;
        } else
        {
            negative_count++;
        }
    }


    if (positive_count == constantsCoefficients.size())
    {
        _is_solved = true;
    }

    return false;
}

bool Solver::solve()
{

    if (check_optimality())
    {
        return true;
    }

    int bazisColumn = get_bazis_column();
    int bazisRow = get_bazis_row(bazisColumn); // находим строку базиса с наименьшим значением
    convert_table(bazisRow, bazisColumn);
    if (_is_solved)
    {
        row_print();
        return true;
    }

    return false;
}

int Solver::get_bazis_column()
{
    int pos = 0;
    double min = constantsCoefficients[0];
    // находим наименьшие коэффициенты ограничений в функци
    for (int col = 0; col < constantsCoefficients.size(); col++)
    {
        if (constantsCoefficients[col] < min)
        {
            min = constantsCoefficients[col];
            pos = col;
        }
    }

    return pos;
}

int Solver::get_bazis_row(int bazisColumn)
{
    float positive_values[_row_count];
    std::vector<float> temp(_row_count, 0); // переменная для вывод ответа

    int negatives_variables = 0;

    negatives_variables = countNegativesValues(bazisColumn, positive_values, negatives_variables);
    ////проверка условия, если все значения отрицательные
    temp = checkUnbound(positive_values, temp, negatives_variables);

    //найти местоположение минимума наименьшего элемента массива objectiveFunctionCoefficients
    return findIndexOfMinValue(temp);

}

int Solver::findIndexOfMinValue(const std::vector<float> &temp) const
{
    float minimum = 99999999;
    int location = 0;
    for (int i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
    {
        if (temp[i] > 0)
        {
            if (temp[i] < minimum)
            {
                minimum = temp[i];

                location = i;
            }
        }

    }

    return location;
}

std::vector<float> &
Solver::checkUnbound(const float *positive_values, std::vector<float> &temp, int negatives_variables)
{
    if (negatives_variables == _row_count)
    {
        _is_solved = true;
    } else
    {
        for (int i = 0; i < _row_count; i++)
        {
            float value = positive_values[i];
            if (value > 0)
            {
                temp[i] = objectiveFunctionCoefficients[i] / value;

            } else
            {
                temp[i] = 0;
            }
        }
    }
    return temp;
}

int Solver::countNegativesValues(int bazisColumn, float *positive_values, int negatives_variables)
{
    for (int i = 0; i < _row_count; i++)
    {
        if (functionCoefficients[i][bazisColumn] > 0)
        {
            positive_values[i] = functionCoefficients[i][bazisColumn];
        } else
        {
            positive_values[i] = 0;
            negatives_variables += 1;
        }
    }
    return negatives_variables;
}

void Solver::convert_table(int row, int column)
{
    double resolving_value = functionCoefficients[row][column];

    double resolving_value_rows[_column_count];

    double resolving_value_columns[_row_count];

    double new_row_data[_column_count];

    calculateMaximum(row, column, resolving_value);
    //получаем строку, которая имеет значение
    calculateResolvingValuesRow(row, resolving_value_rows);

    //получаем столбец, которая имеет значение
    calculateResolvingValuesColumn(column, resolving_value_columns);

    //вычисляем значчения для новой строки
    calculateNewRowData(row, resolving_value, resolving_value_rows, new_row_data);

    // умножение коэфицентов матрицы
    functionCoefficentRecalculation(row, resolving_value_columns, new_row_data);
    // умножение  коэффициентов ограничений

    constantsCoefficientsRecalculation(row, resolving_value_columns);


    // наименьший коэффициент ограничений объективной функции
    float multiplyValue = constantsCoefficients[column];

    CalculationObjFunction(new_row_data, multiplyValue);


    //  замена символов в старой строке новой
    for (int i = 0; i < _column_count; i++)
    {
        functionCoefficients[row][i] = new_row_data[i];
    }


}

void Solver::CalculationObjFunction(const double *new_row_data, float multiplyValue)
{
    for (int i = 0; i < constantsCoefficients.size(); i++)
    {
        constantsCoefficients[i] = constantsCoefficients[i] - (multiplyValue * new_row_data[i]);

    }
}

void Solver::constantsCoefficientsRecalculation(int row, const double *resolving_value_columns)
{
    for (int i = 0; i < objectiveFunctionCoefficients.size(); i++)
    {
        if (i != row)
        {

            float multiplyValue = resolving_value_columns[i];
            objectiveFunctionCoefficients[i] =
                    objectiveFunctionCoefficients[i] - (multiplyValue * objectiveFunctionCoefficients[row]);

        }
    }
}

void
Solver::functionCoefficentRecalculation(int row, const double *resolving_value_columns, const double *new_row_data)
{
    for (int m = 0; m < _row_count; m++)
    {

        if (m != row)
        {
            for (int p = 0; p < _column_count; p++)
            {
                float multiplyValue = resolving_value_columns[m];
                functionCoefficients[m][p] = functionCoefficients[m][p] - (multiplyValue * new_row_data[p]);

            }

        }
    }
}

void Solver::calculateMaximum(int row, int column, double resolving_value)
{
    _max_value = _max_value - (constantsCoefficients[column] *
                               (objectiveFunctionCoefficients[row] / resolving_value));
}

void
Solver::calculateNewRowData(int row, double resolving_value, const double *resolving_value_rows, double *new_row_data)
{
    for (int k = 0; k < _column_count; k++)
    {
        new_row_data[k] = resolving_value_rows[k] / resolving_value;
    }

    objectiveFunctionCoefficients[row] = objectiveFunctionCoefficients[row] / resolving_value;
}

void Solver::calculateResolvingValuesColumn(int column, double *resolving_value_columns)
{
    for (int j = 0; j < _row_count; j++)
    {
        resolving_value_columns[j] = functionCoefficients[j][column];
    }
}

void Solver::calculateResolvingValuesRow(int row, double *resolving_value_rows)
{
    for (int i = 0; i < _column_count; i++)
    {
        resolving_value_rows[i] = functionCoefficients[row][i];
    }
}

void Solver::calculate_simplex_table()
{
    bool ready = false;

    std::cout << "initial array(Not optimal)" << std::endl;
    row_print();
    while (!ready)
    {

        bool result = solve();;

        if (result == true)
        {

            ready = true;


        }

    }
    //к каждому базовый столбецу получаем значение  из массива
    printAnswerVariables();
    printMaximumValues();
}

void Solver::printMaximumValues() const
{
    std::cout << std::endl << std::endl;
    std::cout << "Fmax: " << _max_value << std::endl;
}

void Solver::printAnswerVariables()
{
    for (int i = 0; i < functionCoefficients.size(); i++)
    {
        int count0 = 0;
        int index = 0;
        for (int j = 0; j < _row_count; j++)
        {
            if (functionCoefficients[j][i] == 0.0)
            {
                count0 += 1;
            } else if (functionCoefficients[j][i] == 1)
            {
                index = j;
            }


        }
        if (count0 == _row_count - 1)
        {

            std::cout << "x" << index + 1 << ": " << objectiveFunctionCoefficients[index]
                      << std::endl;
        } else
        {
            std::cout << "x" << index + 1 << ": " << 0 << std::endl;

        }


    }
}

void Solver::row_print()
{
    for (int i = 0; i < _row_count; i++)
    {
        for (int j = 0; j < _column_count; j++)
        {
            std::cout << functionCoefficients[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


