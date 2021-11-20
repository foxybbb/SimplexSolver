//
// Created by IvanEarth on 14.11.2021.
//

#ifndef SIMPLEXSOLVER_FRACTION_H
#define SIMPLEXSOLVER_FRACTION_H

#include <cmath>

class Fraction
{
private:
    int nominator;
    int denominator;
    int sign;

    void reduce();

public:
    int getDenominator() const;

    int getNumerator() const;

    int getSign() const;


    int getGCD(int nominator, int denominator);
};


#endif //SIMPLEXSOLVER_FRACTION_H
