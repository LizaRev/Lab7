using System;

namespace Lab7.Library
{
    public class ExpressionEvaluator
    {
        public double A { get; private set; }
        public double B { get; private set; }
        public double C { get; private set; }
        public double D { get; private set; }

        public ExpressionEvaluator(double a, double b, double c, double d)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }

        public void SetParameters(double a, double b, double c, double d)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }

        public double Calculate()
        {
            if (D == 0) 
                throw new DivideByZeroException("D не може бути нулем");

            double logCalculate = 4 * B - C;

            MathOperation mathOps = new MathOperation();
            double resultLog = mathOps.Logarithm(logCalculate);

            double denominator = B + (C / D) - 1;

            if (denominator == 0)
                throw new DivideByZeroException("Знаменник не може бути нулем");

            return (resultLog * A) / denominator;
        }

        public string GetValues()
        {
            string res = " ";
            res = res + Calculate();
            return res;
        }
    }
}