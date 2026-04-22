#include <iostream>
#include <string>
#include <stdexcept>
#include "ExpressionEvaluator.h"

using namespace std;

int main()
{
    int size = 0;

    try {
        cout << "Введіть кількість об'єктів: ";
        if (!(cin >> size) || size <= 0) {
            throw runtime_error("Некоректний розмір масиву");
        }
    }
    catch (const std::exception& ex) {
        cout << "Помилка: " << ex.what() << endl;
        return 1;
    }

    ExpressionEvaluator** evaluators = new ExpressionEvaluator*[size];

    for (int i = 0; i < size; i++) {
        bool success = false;

        while (!success) {
            try {
                double a, b, c, d;

                cout << "Введіть значення параметрів:\n";
                cout << "A: "; cin >> a;
                cout << "B: "; cin >> b;
                cout << "C: "; cin >> c;
                cout << "D: "; cin >> d;

                evaluators[i] = new ExpressionEvaluator(a, b, c, d);

                cout << "Результат: " << evaluators[i]->GetValues() << endl;

                success = true;
            }
            catch (const std::exception& ex) {
                cout << "Помилка: " << ex.what() << endl;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        delete evaluators[i];
    }
    delete[] evaluators;

    return 0;
}