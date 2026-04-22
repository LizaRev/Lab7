#include "MathOperation.h"
#include <cmath>
#include <stdexcept>

double MathOperation::Logarithm(double value)
{
    if (value <= 0)
        throw std::runtime_error("Логарифм: аргумент має бути > 0");

    return std::log10(value);
}