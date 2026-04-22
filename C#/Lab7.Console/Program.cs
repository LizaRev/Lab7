using System;
using Lab7.Library;

namespace Lab7 
{
    class Program
    {
        static void Main(string[] args)
        {
            int size = 0;

            try {
                 Console.WriteLine("Введіть, будь ласка, кількість об'єктів ");
                 size = int.Parse(Console.ReadLine());
            }
            catch (FormatException ex) {
                Console.WriteLine("Ви ввели не ціле число. Встановіть ціле число");
                Console.WriteLine(ex.Message);
                return;
            }

           ExpressionEvaluator[] evaluators = new ExpressionEvaluator[size];

           for (int i = 0; i < size; i++) 
           {
                bool success = false;
                while (!success)
                {
                    try {
                        Console.WriteLine("Введіть значення параметрів:");
                        Console.WriteLine("A:");
                        double a = double.Parse(Console.ReadLine());

                        Console.WriteLine("B:");
                        double b = double.Parse(Console.ReadLine());

                        Console.WriteLine("C:");
                        double c = double.Parse(Console.ReadLine());

                        Console.WriteLine("D:");
                        double d = double.Parse(Console.ReadLine());

                        evaluators[i] = new ExpressionEvaluator(a, b, c, d);
                        
                        Console.WriteLine(evaluators[i].GetValues());
                        success = true;
                    }
                    catch (FormatException ex) {
                        Console.WriteLine("Ви ввели не число. Об'єкт не створено.");
                        Console.WriteLine(ex.Message);

                    }
                    catch (ArgumentOutOfRangeException ex) {
                        Console.WriteLine("Помилка логарифма: аргумент має бути > 0");
                        Console.WriteLine(ex.Message);
                    }
                    catch (DivideByZeroException ex) {
                        Console.WriteLine("Помилка: ділення на нуль!");
                        Console.WriteLine(ex.Message);
                    }
                }
           } 
        }
    }
}