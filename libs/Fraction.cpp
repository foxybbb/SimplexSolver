//
// Created by IvanEarth on 14.11.2021.
//

#include "Fraction.h"

int Fraction::getDenominator() const
{
    return denominator;
}

int Fraction::getNumerator() const
{
    return nominator;
}

int Fraction::getSign() const
{
    return sign;
}

void Fraction::reduce()
{
    int gcd = getGCD(nominator, denominator);
    nominator /= gcd;
    denominator /= gcd;
}

int Fraction::getGCD(int nominator, int denominator)
{
    if (denominator == 0)
        return nominator;
    return getGCD(denominator, nominator % denominator);
}
