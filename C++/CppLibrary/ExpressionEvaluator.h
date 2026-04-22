#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <string>
#include "MathOperation.h"

class ExpressionEvaluator
{
private:
    double a, b, c, d;

public:
    ExpressionEvaluator(double A, double B, double C, double D);

    void SetParameters(double A, double B, double C, double D);

    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    double Calculate() const;
    std::string GetValues() const;
};

#endif