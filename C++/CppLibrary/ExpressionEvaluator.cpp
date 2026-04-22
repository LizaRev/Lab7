#include "ExpressionEvaluator.h"
#include <string>
#include <stdexcept>

ExpressionEvaluator::ExpressionEvaluator(double A, double B, double C, double D)
{
    a = A;
    b = B;
    c = C;
    d = D;
}

void ExpressionEvaluator::SetParameters(double A, double B, double C, double D)
{
    a = A;
    b = B;
    c = C;
    d = D;
}

double ExpressionEvaluator::getA() const { return a; }
double ExpressionEvaluator::getB() const { return b; }
double ExpressionEvaluator::getC() const { return c; }
double ExpressionEvaluator::getD() const { return d; }

double ExpressionEvaluator::Calculate() const
{
    if (d == 0)
        throw std::runtime_error("D не може бути 0");

    double logCalculate = 4 * b - c;

    MathOperation mathOps;
    double resultLog = mathOps.Logarithm(logCalculate);

    double denominator = b + (c / d) - 1;

    if (denominator == 0)
        throw std::runtime_error("Знаменник дорівнює 0");

    return (resultLog + a) / denominator;
}

std::string ExpressionEvaluator::GetValues() const
{
    return std::to_string(Calculate());
}