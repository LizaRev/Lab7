using System;

namespace Lab7.Library
{
    public class MathOperation 
    {
        public double Logarithm(double value)
        {
            if (value <= 0)
            {
                throw new ArgumentOutOfRangeException("Оскільки логарифм,то аргумент має бути >= 0");
            }
        
        return Math.Log10(value);
        }
    }
}